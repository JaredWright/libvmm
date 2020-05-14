#include <libvmm/vcpu/x64/intel/io_port.hpp>

namespace libvmm
{

void enable_io_port_vmexit(vcpu_context &vc, uint16_t port_number) noexcept
{
    // TODO: Implement Me!
    return;
}

void enable_io_port_vmexit_range(vcpu_context &vc, uint16_t begin, uint16_t end) noexcept
{
    // TODO: Implement Me!
    return;
}

void disable_io_port_vmexit(vcpu_context &vc, uint16_t port_number) noexcept
{
    // TODO: Implement Me!
    return;
}

void disable_io_port_vmexit_range(vcpu_context &vc, uint16_t begin, uint16_t end) noexcept
{
    // TODO: Implement Me!
    return;
}

void set_io_port_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept
{
    // TODO: Implement Me!
    return;
}

uint64_t get_io_port_vmexit_size(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return 0;
}

bool is_io_port_vmexit_in(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return false;
}

bool is_io_port_vmexit_out(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return false;
}

uint16_t get_io_port_vmexit_port_number(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return 0;
}

uint64_t get_io_port_vmexit_value(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return 0;
}

void pass_through_io_port(vcpu_context &vc) noexcept
{
    // TODO: Implement Me!
    return;
}

void provide_io_port_result(vcpu_context &vc, uint64_t value) noexcept
{
    // TODO: Implement Me!
    return;
}

}
