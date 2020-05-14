#ifndef LIBVMM_VCPU_X64_GENERAL_REGISTER_X64_HPP
#define LIBVMM_VCPU_X64_GENERAL_REGISTER_X64_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Return the value of register rax
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register rax
uint64_t get_rax(vcpu_context &vc) noexcept;

/// @brief Set the value of register rax
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register rax to
void set_rax(vcpu_context &vc, uint64_t value) noexcept;

/// @brief Return the value of register rbx
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register rbx
uint64_t get_rbx(vcpu_context &vc) noexcept;

/// @brief Set the value of register rbx
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register rbx to
void set_rbx(vcpu_context &vc, uint64_t value) noexcept;

/// @brief Return the value of register rcx
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register rcx
uint64_t get_rcx(vcpu_context &vc) noexcept;

/// @brief Set the value of register rcx
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register rcx to
void set_rcx(vcpu_context &vc, uint64_t value) noexcept;

/// @brief Return the value of register rdx
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register rdx
uint64_t get_rdx(vcpu_context &vc) noexcept;

/// @brief Set the value of register rdx
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register rdx to
void set_rdx(vcpu_context &vc, uint64_t value) noexcept;

/// @brief Return the value of register rbp
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register rbp
uint64_t get_rbp(vcpu_context &vc) noexcept;

/// @brief Set the value of register rbp
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register rbp to
void set_rbp(vcpu_context &vc, uint64_t value) noexcept;

/// @brief Return the value of register rsi
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register rsi
uint64_t get_rsi(vcpu_context &vc) noexcept;

/// @brief Set the value of register rsi
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register rsi to
void set_rsi(vcpu_context &vc, uint64_t value) noexcept;

/// @brief Return the value of register rdi
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register rdi
uint64_t get_rdi(vcpu_context &vc) noexcept;

/// @brief Set the value of register rdi
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register rdi to
void set_rdi(vcpu_context &vc, uint64_t value) noexcept;

/// @brief Return the value of register r8
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register r8
uint64_t get_r8(vcpu_context &vc) noexcept;

/// @brief Set the value of register r8
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register r8 to
void set_r8(vcpu_context &vc, uint64_t value) noexcept;

/// @brief Return the value of register r9
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register r9
uint64_t get_r9(vcpu_context &vc) noexcept;

/// @brief Set the value of register r9
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register r9 to
void set_r9(vcpu_context &vc, uint64_t value) noexcept;

/// @brief Return the value of register r10
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register r10
uint64_t get_r10(vcpu_context &vc) noexcept;

/// @brief Set the value of register r10
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register r10 to
void set_r10(vcpu_context &vc, uint64_t value) noexcept;

/// @brief Return the value of register r11
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register r11
uint64_t get_r11(vcpu_context &vc) noexcept;

/// @brief Set the value of register r11
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register r11 to
void set_r11(vcpu_context &vc, uint64_t value) noexcept;

/// @brief Return the value of register r12
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register r12
uint64_t get_r12(vcpu_context &vc) noexcept;

/// @brief Set the value of register r12
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register r12 to
void set_r12(vcpu_context &vc, uint64_t value) noexcept;

/// @brief Return the value of register r13
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register r13
uint64_t get_r13(vcpu_context &vc) noexcept;

/// @brief Set the value of register r13
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register r13 to
void set_r13(vcpu_context &vc, uint64_t value) noexcept;

/// @brief Return the value of register r14
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register r14
uint64_t get_r14(vcpu_context &vc) noexcept;

/// @brief Set the value of register r14
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register r14 to
void set_r14(vcpu_context &vc, uint64_t value) noexcept;

/// @brief Return the value of register r15
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register r15
uint64_t get_r15(vcpu_context &vc) noexcept;

/// @brief Set the value of register r15
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register r15 to
void set_r15(vcpu_context &vc, uint64_t value) noexcept;

/// @brief Return the value of register rip
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register rip
uint64_t get_rip(vcpu_context &vc) noexcept;

/// @brief Set the value of register rip
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register rip to
void set_rip(vcpu_context &vc, uint64_t value) noexcept;

/// @brief Return the value of register rsp
///
/// @param vc The vcpu_context to operate on
///
/// @return The value of register rsp
uint64_t get_rsp(vcpu_context &vc) noexcept;

/// @brief Set the value of register rsp
///
/// @param vc The vcpu_context to operate on
/// @param value The value to set register rsp to
void set_rsp(vcpu_context &vc, uint64_t value) noexcept;
}

#endif

