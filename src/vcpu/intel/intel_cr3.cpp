#include <libvmm/vcpu/x64/intel/cr3.hpp>

namespace libvmm
{

void enable_cr3_read_vmexit(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return;
}

void disable_cr3_read_vmexit(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return;
}

void set_cr3_read_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept
{
    // TODO: Implement Me!
    return;
}

void provide_cr3_read_result(vcpu_context &vc, uint64_t cr3_value) noexcept
{
    // TODO: Implement Me!
    return;
}

void enable_cr3_write_vmexit(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return;
}

void disable_cr3_write_vmexit(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return;
}

void set_cr3_write_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept
{
    // TODO: Implement Me!
    return;
}

uint64_t get_cr3_write_vmexit_value(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return 0;
}

void provide_cr3_write_result(vcpu_context &vc, uint64_t cr3_value) noexcept
{
    // TODO: Implement Me!
    return;
}

}
