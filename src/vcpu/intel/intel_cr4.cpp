#include <libvmm/vcpu/x64/intel/cr4.hpp>

namespace libvmm
{

void enable_cr4_write_vmexit(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return;
}

void disable_cr4_write_vmexit(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return;
}

void set_cr4_write_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept
{
    // TODO: Implement Me!
    return;
}

uint64_t get_cr4_write_vmexit_value(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return 0;
}

void provide_cr4_write_result(vcpu_context &vc, uint64_t cr4_value) noexcept
{
    // TODO: Implement Me!
    return;
}

}
