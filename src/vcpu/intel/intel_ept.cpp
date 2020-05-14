#include <libvmm/vcpu/x64/intel/ept.hpp>

namespace libvmm
{

void enable_nested_paging(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return;
}

void disable_nested_paging(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return;
}

void set_nested_paging_base_address(vcpu_context &vc, uintptr_t phys_addr) noexcept
{
    // TODO: Implement Me!
    return;
}

void set_nested_paging_violation_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept
{
    // TODO: Implement Me!
    return;
}

void set_nested_paging_misconfiguration_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept
{
    // TODO: Implement Me!
    return;
}

bool is_nested_paging_vmexit_read(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return false;
}

bool is_nested_paging_vmexit_write(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return false;
}

bool is_nested_paging_vmexit_execute(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return false;
}

bool is_nested_paging_vmexit_violation(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return false;
}

bool is_nested_paging_vmexit_misconfiguration(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return false;
}

}
