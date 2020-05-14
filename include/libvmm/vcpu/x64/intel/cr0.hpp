#ifndef LIBVMM_VCPU_X64_INTEL_CR0_HPP
#define LIBVMM_VCPU_X64_INTEL_CR0_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Enable vmexits for all writes to control register cr0
///
/// @param vc The vcpu_context to operate on
void enable_cr0_write_vmexit(vcpu_context &vc) noexcept;

/// @brief Disable vmexits for all writes to control register cr0
///
/// @param vc The vcpu_context to operate on
void disable_cr0_write_vmexit(vcpu_context &vc) noexcept;

/// @brief Set a vmexit handler that will be called for all vmexits caused
///     by a write to control register cr0 while a vcpu is executing.
///
/// @param vc The vcpu_context to operate on
/// @param func The delegate function to be called
void set_cr0_write_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

/// @brief Returns the value being written to control register cr0 that
///     caused a vmexit to occur while a vcpu was executing
///
/// @param vc The vcpu_context to operate on
///
/// @return The value written to cr0
uint64_t get_cr0_write_vmexit_value(vcpu_context &vc) noexcept;

/// @brief Emulate a write to cr0 that caused a vmexit to occur while a
///     vcpu was executing. The given value is written into the vcpu's
///     cr0, instead of the value that caused the vm exit to occur. 
///
/// @param vc The vcpu_context to operate on
/// @param cr0_value The value to be written to a vcpu's cr0
void provide_cr0_write_result(vcpu_context &vc, uint64_t cr0_value) noexcept;

}

#endif

