#include <libvmm/libvmm.hpp>
#include <libvmm/vcpu/vcpu.hpp>
#include <libvmm/vcpu/x64/intel/intel.hpp>

#include <pal/msr/ia32_efer.h>

// This example demonstrates how to virtualize model specific registers (MSRs)
// on an x64 platform using the Bareflank Hypervisor SDK. The example
// emulates reads and writes to the IA32_EFER MSR, and passes through all other
// MSR accesses from the guest to hardware.
//
// The following behaviors are emulated by this VMM:
//
//      - When the guest reads from IA32_EFER, the VMM advertises that the CPU
//        is not running in IA-32e long mode by emulating the "LMA" bit
//
//      - When the guest writes to IA32_EFER, the VMM prevents the CPU from
//        switching into IA-32e long mode by emulating the "LME" bit

void emulate_ia32_efer_read(libvmm::vcpu_context &vc) noexcept
{
    uint64_t emulated_msr = pal::ia32_efer::get();
    pal::ia32_efer::lma::disable(emulated_msr);
    libvmm::provide_rdmsr_result(vc, emulated_msr);
}

void emulate_ia32_efer_write(libvmm::vcpu_context &vc) noexcept
{
    uint64_t emulated_value = libvmm::get_wrmsr_vmexit_value(vc);
    pal::ia32_efer::lme::disable(emulated_value);
    libvmm::provide_wrmsr_result(vc, emulated_value);
}

void handle_rdmsr_vmexit(libvmm::vcpu_context &vc) noexcept
{
    uint64_t msr_address = libvmm::get_rdmsr_vmexit_address(vc);

    switch(msr_address) {
        case pal::ia32_efer::address:
            emulate_ia32_efer_read(vc);
        default:
            libvmm::pass_through_rdmsr(vc);
    }

    libvmm::advance_instruction_pointer(vc);
    libvmm::run(vc);
}

void handle_wrmsr_vmexit(libvmm::vcpu_context &vc) noexcept
{
    uint64_t msr_address = libvmm::get_wrmsr_vmexit_address(vc);

    switch(msr_address) {
        case pal::ia32_efer::address:
            emulate_ia32_efer_write(vc);
        default:
            libvmm::pass_through_wrmsr(vc);
    }

    libvmm::advance_instruction_pointer(vc);
    libvmm::run(vc);
}

void init_root_vcpu(libvmm::vcpu_context &vc) noexcept
{
    libvmm::set_rdmsr_vmexit_handler(vc, handle_rdmsr_vmexit);
    libvmm::enable_rdmsr_vmexit(vc, pal::ia32_efer::address);

    libvmm::set_wrmsr_vmexit_handler(vc, handle_wrmsr_vmexit);
    libvmm::enable_wrmsr_vmexit(vc, pal::ia32_efer::address);
}

bsl::exit_code main() noexcept
{
    libvmm::set_vcpu_init_handler(init_root_vcpu);
    return libvmm::start_vmm();
}
