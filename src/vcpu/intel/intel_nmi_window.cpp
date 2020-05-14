#include <libvmm/vcpu/x64/intel/nmi_window.hpp>

namespace libvmm
{

void enable_nmi_window_vmexit(vcpu_context &vc) noexcept
{
    return;
}

void disable_nmi_window_vmexit(vcpu_context &vc) noexcept
{
    return;
}

void set_nmi_window_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept
{
    return;
}

}
