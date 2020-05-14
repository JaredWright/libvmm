#ifndef LIBVMM_VCPU_X64_INTEL_CR4_HPP
#define LIBVMM_VCPU_X64_INTEL_CR4_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Enable vmexits for all writes to control register cr4
///
/// @param vc The vcpu_context to operate on
void enable_cr4_write_vmexit(vcpu_context &vc) noexcept;

/// @brief Disable vmexits for all writes to control register cr4
///
/// @param vc The vcpu_context to operate on
void disable_cr4_write_vmexit(vcpu_context &vc) noexcept;

/// @brief Set a vmexit handler that will be called for all vmexits caused
///     by a write to control register cr4 while a vcpu is executing.
///
/// @param vc The vcpu_context to operate on
/// @param func The delegate function to be called
void set_cr4_write_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

/// @brief Returns the value being written to control register cr4 that
///     caused a vmexit to occur while a vcpu was executing
///
/// @param vc The vcpu_context to operate on
///
/// @return The value written to cr4
uint64_t get_cr4_write_vmexit_value(vcpu_context &vc) noexcept;

/// @brief Emulate a write to cr4 that caused a vmexit to occur while a
///     vcpu was executing. The given value is written into the vcpu's
///     cr4, instead of the value that caused the vm exit to occur. 
///
/// @param vc The vcpu_context to operate on
/// @param cr4_value The value to be written to a vcpu's cr4
void provide_cr4_write_result(vcpu_context &vc, uint64_t cr4_value) noexcept;

}

#endif

