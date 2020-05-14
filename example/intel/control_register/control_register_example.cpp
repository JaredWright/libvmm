#include <libvmm/libvmm.hpp>
#include <libvmm/vcpu/vcpu.hpp>
#include <libvmm/vcpu/x64/intel/intel.hpp>

#include <pal/control_register/cr0.h>
#include <pal/control_register/cr3.h>
#include <pal/control_register/cr4.h>

// This example demonstrates how to virtualize control registers on an x64
// platform using the Bareflank Hypervisor SDK. The example includes emulation
// for the root virtual machine's cr0, cr3, and cr4.
//
// The following behaviors are emulated by this VMM:
//
//      - Attempts to disable protected mode (cr0.pe) and paging (cr0.pg) from
//        within the root virtual machine are transparently blocked by the vmm.
//
//      - Reads to cr3 from within the root virtual machine are passed through
//
//      - If the root virtual machine writes the value "0x1337" to it's cr3,
//        the vmm prints its own cr3 out to a serial port
//
//      - Attempts to enable virtual machine extensions (cr4.vmxe) from within
//        root virtual machine are transparently blocked by the vmm.

void handle_cr0_write_vmexit(libvmm::vcpu_context &vc) noexcept
{
    uint64_t emulated_cr0 = libvmm::get_cr0_write_vmexit_value(vc);
    pal::cr0::pe::enable(emulated_cr0);
    pal::cr0::pg::enable(emulated_cr0);
    libvmm::provide_cr0_write_result(vc, emulated_cr0);

    libvmm::advance_instruction_pointer(vc);
    libvmm::run(vc);
}

void handle_cr3_read_vmexit(libvmm::vcpu_context &vc) noexcept
{
    libvmm::provide_cr3_read_result(vc, 0xBADC0FFEE);

    libvmm::advance_instruction_pointer(vc);
    libvmm::run(vc);
}

void handle_cr3_write_vmexit(libvmm::vcpu_context &vc) noexcept
{
    uint64_t cr3_value = libvmm::get_cr3_write_vmexit_value(vc);
    if (cr3_value == 0x1337) {
        pal::cr3::dump();
    }

    libvmm::advance_instruction_pointer(vc);
    libvmm::run(vc);
}

void handle_cr4_write_vmexit(libvmm::vcpu_context &vc) noexcept
{
    uint64_t emulated_cr4 = libvmm::get_cr4_write_vmexit_value(vc);
    pal::cr4::vmxe::disable(emulated_cr4);
    libvmm::provide_cr4_write_result(vc, emulated_cr4);

    libvmm::advance_instruction_pointer(vc);
    libvmm::run(vc);
}

void init_root_vcpu(libvmm::vcpu_context &vc) noexcept
{
    libvmm::set_cr0_write_vmexit_handler(vc, handle_cr0_write_vmexit);
    libvmm::enable_cr0_write_vmexit(vc);

    libvmm::set_cr3_read_vmexit_handler(vc, handle_cr3_write_vmexit);
    libvmm::set_cr3_write_vmexit_handler(vc, handle_cr3_write_vmexit);
    libvmm::enable_cr3_read_vmexit(vc);
    libvmm::enable_cr3_write_vmexit(vc);

    libvmm::set_cr4_write_vmexit_handler(vc, handle_cr4_write_vmexit);
    libvmm::enable_cr4_write_vmexit(vc);
}

bsl::exit_code main()
{
    libvmm::set_vcpu_init_handler(init_root_vcpu);
    return libvmm::start_vmm();
}
