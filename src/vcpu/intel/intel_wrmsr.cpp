#include <libvmm/vcpu/x64/intel/wrmsr.hpp>

namespace libvmm
{

void enable_wrmsr_vmexit(vcpu_context &vc, uint32_t msr_address) noexcept
{
    // TODO: Implement Me!
    return;
}

void enable_wrmsr_vmexit_range(vcpu_context &vc, uint32_t begin, uint32_t end) noexcept
{
    // TODO: Implement Me!
    return;
}

void disable_wrmsr_vmexit(vcpu_context &vc, uint32_t msr_address) noexcept
{
    // TODO: Implement Me!
    return;
}

void disable_wrmsr_vmexit_range(vcpu_context &vc, uint32_t begin, uint32_t end) noexcept
{
    // TODO: Implement Me!
    return;
}

void set_wrmsr_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept
{
    // TODO: Implement Me!
    return;
}

uint32_t get_wrmsr_vmexit_address(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return 0;
}

uint64_t get_wrmsr_vmexit_value(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return 0;
}

void pass_through_wrmsr(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return;
}

void provide_wrmsr_result(vcpu_context &vc, uint64_t value) noexcept
{
    // TODO: Implement Me!
    return;
}

}
