#include <libvmm/vcpu/x64/general_register_x64.hpp>
#include <vcpu_context/intel_vcpu_context.hpp>

namespace libvmm
{

uint64_t get_rax(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_rax();
}

void set_rax(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_rax(value);
}

uint64_t get_rbx(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_rbx();
}

void set_rbx(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_rbx(value);
}

uint64_t get_rcx(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_rcx();
}

void set_rcx(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_rcx(value);
}

uint64_t get_rdx(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_rdx();
}

void set_rdx(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_rdx(value);
}

uint64_t get_rbp(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_rbp();
}

void set_rbp(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_rbp(value);
}

uint64_t get_rsi(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_rsi();
}

void set_rsi(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_rsi(value);
}

uint64_t get_rdi(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_rdi();
}

void set_rdi(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_rdi(value);
}

uint64_t get_r8(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_r8();
}

void set_r8(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_r8(value);
}

uint64_t get_r9(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_r9();
}

void set_r9(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_r9(value);
}

uint64_t get_r10(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_r10();
}

void set_r10(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_r10(value);
}

uint64_t get_r11(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_r11();
}

void set_r11(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_r11(value);
}

uint64_t get_r12(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_r12();
}

void set_r12(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_r12(value);
}

uint64_t get_r13(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_r13();
}

void set_r13(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_r13(value);
}

uint64_t get_r14(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_r14();
}

void set_r14(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_r14(value);
}

uint64_t get_r15(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_r15();
}

void set_r15(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_r15(value);
}

uint64_t get_rip(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_rip();
}

void set_rip(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_rip(value);
}

uint64_t get_rsp(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    return intel_vc.get_rsp();
}

void set_rsp(vcpu_context &vc, uint64_t value) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vc.set_rsp(value);
}

}
