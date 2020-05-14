#include <libvmm/vcpu/x64/intel/cr0.hpp>

namespace libvmm
{

void enable_cr0_write_vmexit(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return;
}

void disable_cr0_write_vmexit(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return;
}

void set_cr0_write_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept
{
    // TODO: Implement Me!
    return;
}

uint64_t get_cr0_write_vmexit_value(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return 0;
}

void provide_cr0_write_result(vcpu_context &vc, uint64_t cr0_value) noexcept
{
    // TODO: Implement Me!
    return;
}

}
