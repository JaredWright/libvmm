#include <libvmm/libvmm.hpp>
#include <libvmm/vcpu/vcpu.hpp>
#include <libvmm/vcpu/x64/intel/intel.hpp>

void handle_vmexit(libvmm::vcpu_context &vc) noexcept
{
    // This handler gets called on every vmexit that occurs on the given vcpu
    auto reason = libvmm::get_vmexit_reason(vc);
    auto qualification = libvmm::get_vmexit_qualification(vc);

    // On the Intel platform, you get to choose whether or not the instruction
    // pointer gets advanced on the next vmentry.
    libvmm::advance_instruction_pointer(vc);

    // You are responsible for returning execution to a vcpu. It could be this
    // vcpu, or it could be a different one.
    libvmm::run(vc);
}

void init_root_vcpu(libvmm::vcpu_context &vc) noexcept
{
    libvmm::set_vmexit_handler(vc, handle_vmexit);
}

bsl::exit_code main() noexcept
{
    libvmm::set_vcpu_init_handler(init_root_vcpu);
    return libvmm::start_vmm();
}
