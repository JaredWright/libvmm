#include <libvmm/vcpu/x64/intel/cpuid.hpp>

namespace libvmm
{

void set_cpuid_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept
{
    // TODO: Implement Me!
    return;
}

uint32_t get_cpuid_vmexit_leaf(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return 0;
}

uint32_t get_cpuid_vmexit_subleaf(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return 0;
}

void pass_through_cpuid(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return;
}

void provide_cpuid_result(vcpu_context &vc, uint32_t eax, uint32_t ebx, uint32_t ecx, uint32_t edx) noexcept
{
    // TODO: Implement Me!
    return;
}

}
