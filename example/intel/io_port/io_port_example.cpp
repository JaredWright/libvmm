#include <libvmm/libvmm.hpp>
#include <libvmm/vcpu/vcpu.hpp>
#include <libvmm/vcpu/x64/intel/intel.hpp>

// This example demonstrates how to virtualize I/O ports on an x64 platform
// using the Bareflank Hypervisor SDK. The example emulates reads and writes to
// the I/O port at address range 0xBF0 - 0xBFF, and passes through all other I/O
// port accesses from the root vm through to hardware.
//
// The following behaviors are emulated by this VMM:
//
//      - When the root vm reads from an I/O port in the range 0xBF0-0xBFF, the
//        VMM emulates a return value
//
//      - When the guest writes to an I/O port in the range 0xBF0-0xBFF, the VMM
//        discards the write so that it does not get written to a hardware port

constexpr const uint16_t emulated_range_low = 0xBF0;
constexpr const uint16_t emulated_range_high = 0xBFF;

void handle_in(libvmm::vcpu_context &vc) noexcept
{
    uint64_t port = libvmm::get_io_port_vmexit_port_number(vc); 

    if ((port > emulated_range_low) && (port < emulated_range_high)) {
        libvmm::provide_io_port_result(vc, 0xBFBFBFBF);
    }
    else {
        libvmm::pass_through_io_port(vc);
    }
}

void handle_out(libvmm::vcpu_context &vc) noexcept
{
    uint64_t port = libvmm::get_io_port_vmexit_port_number(vc); 

    if ((port < emulated_range_low) || (port > emulated_range_high)) {
        libvmm::pass_through_io_port(vc);
    }
}

void handle_io_port_vmexit(libvmm::vcpu_context &vc) noexcept
{
    if (libvmm::is_io_port_vmexit_in(vc)) {
        handle_in(vc);
    }
    else if(libvmm::is_io_port_vmexit_out(vc)) {
        handle_out(vc);
    }

    libvmm::advance_instruction_pointer(vc);
    libvmm::run(vc);
}

void init_root_vcpu(libvmm::vcpu_context &vc) noexcept
{
    libvmm::set_io_port_vmexit_handler(vc, handle_io_port_vmexit);
    libvmm::enable_io_port_vmexit_range(vc, emulated_range_low, emulated_range_high);
}

bsl::exit_code main() noexcept
{
    libvmm::set_vcpu_init_handler(init_root_vcpu);
    return libvmm::start_vmm();
}
