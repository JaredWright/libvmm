#include <libvmm/vcpu/x64/intel/rdmsr.hpp>

namespace libvmm
{

void enable_rdmsr_vmexit(vcpu_context &vc, uint32_t msr_address) noexcept
{
    // TODO: Implement Me!
    return;
}

void enable_rdmsr_vmexit_range(vcpu_context &vc, uint32_t begin, uint32_t end) noexcept
{
    // TODO: Implement Me!
    return;
}

void disable_rdmsr_vmexit(vcpu_context &vc, uint32_t msr_address) noexcept
{
    // TODO: Implement Me!
    return;
}

void disable_rdmsr_vmexit_range(vcpu_context &vc, uint32_t begin, uint32_t end) noexcept
{
    // TODO: Implement Me!
    return;
}

void set_rdmsr_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept
{
    // TODO: Implement Me!
    return;
}

uint32_t get_rdmsr_vmexit_address(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return 0;
}

void pass_through_rdmsr(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return;
}

void provide_rdmsr_result(vcpu_context &vc, uint64_t value) noexcept
{
    // TODO: Implement Me!
    return;
}

}
