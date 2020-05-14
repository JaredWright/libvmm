#include <libvmm/libvmm.hpp>
#include <libvmm/vcpu/vcpu.hpp>
#include <libvmm/vcpu/x64/x64.hpp>
#include <libvmm/vcpu/x64/intel/intel.hpp>

// This example demonstrates how to set up a hypercall interface using a
// vmcall vmexit handler. This example's hypercall interface consists of a
// single input/output register: rax. If the value "0xF00D" is in the register
// rax when the hypercall is made, the value "0xBEEF" is placed into rax
// as a return value. Otherwise, the value "0xBADC0FFEE" is placed into rax.

void handle_vmcall(libvmm::vcpu_context &vc) noexcept
{
    auto rax = libvmm::get_rax(vc);

    if (rax == 0xF00D) {
        libvmm::set_rax(vc, 0xBEEF);
    }
    else {
        libvmm::set_rax(vc, 0xBADC0FFEE);
    }

    libvmm::advance_instruction_pointer(vc);
    libvmm::run(vc);
}

void init_root_vcpu(libvmm::vcpu_context &vc) noexcept
{
    libvmm::set_vmexit_handler(vc, handle_vmcall);
}

bsl::exit_code main() noexcept
{
    libvmm::set_vcpu_init_handler(init_root_vcpu);
    return libvmm::start_vmm();
}
