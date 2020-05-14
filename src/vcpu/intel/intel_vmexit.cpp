#include <libvmm/vcpu/x64/intel/vmexit.hpp>

namespace libvmm
{

uint32_t get_vmexit_reason(vcpu_context &vc) noexcept
{
    // TODO: Implement me!
    return 0;
}

uint32_t get_vmexit_qualification(vcpu_context &vc) noexcept
{
    // TODO: Implement me!
    return 0;
}

void set_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept
{
    // TODO: Implement me!
}

void set_post_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept
{
    // TODO: Implement me!
}

}
