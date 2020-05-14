#ifndef LIBVMM_VCPU_CONTEXT_INTEL_VCPU_CONTEXT_HPP
#define LIBVMM_VCPU_CONTEXT_INTEL_VCPU_CONTEXT_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <state_save/x64_gr_state_save.hpp>

namespace libvmm
{

class intel_vcpu_context :
    public vcpu_context,
    public x64_gr_state_save
{
public:

    intel_vcpu_context(x64_gr_state_save &grss) noexcept :
        m_x64_gr_state_save{grss}
    {}

    // ---------------------- x64_gr_state_save seam ---------------------------
    uint64_t get_rax() noexcept
    { return m_x64_gr_state_save.get_rax(); }

    void set_rax(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_rax(value); }

    uint64_t get_rbx() noexcept
    { return m_x64_gr_state_save.get_rbx(); }

    void set_rbx(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_rbx(value); }

    uint64_t get_rcx() noexcept
    { return m_x64_gr_state_save.get_rcx(); }

    void set_rcx(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_rcx(value); }

    uint64_t get_rdx() noexcept
    { return m_x64_gr_state_save.get_rdx(); }

    void set_rdx(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_rdx(value); }

    uint64_t get_rbp() noexcept
    { return m_x64_gr_state_save.get_rbp(); }

    void set_rbp(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_rbp(value); }

    uint64_t get_rsi() noexcept
    { return m_x64_gr_state_save.get_rsi(); }

    void set_rsi(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_rsi(value); }

    uint64_t get_rdi() noexcept
    { return m_x64_gr_state_save.get_rdi(); }

    void set_rdi(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_rdi(value); }

    uint64_t get_r8() noexcept
    { return m_x64_gr_state_save.get_r8(); }

    void set_r8(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_r8(value); }

    uint64_t get_r9() noexcept
    { return m_x64_gr_state_save.get_r9(); }

    void set_r9(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_r9(value); }

    uint64_t get_r10() noexcept
    { return m_x64_gr_state_save.get_r10(); }

    void set_r10(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_r10(value); }

    uint64_t get_r11() noexcept
    { return m_x64_gr_state_save.get_r11(); }

    void set_r11(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_r11(value); }

    uint64_t get_r12() noexcept
    { return m_x64_gr_state_save.get_r12(); }

    void set_r12(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_r12(value); }

    uint64_t get_r13() noexcept
    { return m_x64_gr_state_save.get_r13(); }

    void set_r13(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_r13(value); }

    uint64_t get_r14() noexcept
    { return m_x64_gr_state_save.get_r14(); }

    void set_r14(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_r14(value); }

    uint64_t get_r15() noexcept
    { return m_x64_gr_state_save.get_r15(); }

    void set_r15(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_r15(value); }

    uint64_t get_rip() noexcept
    { return m_x64_gr_state_save.get_rip(); }

    void set_rip(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_rip(value); }

    uint64_t get_rsp() noexcept
    { return m_x64_gr_state_save.get_rsp(); }

    void set_rsp(uint64_t value) noexcept
    { return m_x64_gr_state_save.set_rsp(value); }

private:
    x64_gr_state_save &m_x64_gr_state_save;
};

}

#endif
