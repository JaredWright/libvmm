#ifndef LIBVMM_VCPU_X64_INTEL_WRMSR_HPP
#define LIBVMM_VCPU_X64_INTEL_WRMSR_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Enable vmexits for a model specific register accesses via the
///     wrmsr instruction at the specified msr address during vcpu execution. 
///
/// @param msr_address The msr address to enable wrmsr vmexits for
void enable_wrmsr_vmexit(vcpu_context &vc, uint32_t msr_address) noexcept;

/// @brief Enable vmexits for a range of model specific register accesses
///     via the wrmsr instruction with msr addresses in the range
///     @param begin to @param end (inclusive) during vcpu execution. 
///
/// @expects begin <= end
///
/// @param begin The lower bound of msr addresses to enable vmexits for
/// @param end The upper bound of msr addresses to enable wrmsr vmexits for
void enable_wrmsr_vmexit_range(vcpu_context &vc, uint32_t begin, uint32_t end) noexcept;

/// @brief Disable vmexits for a model specific register accesses via the
///     wrmsr instruction at the specified msr address during vcpu execution. 
///
/// @param msr_address The msr address to disable wrmsr vmexits for
void disable_wrmsr_vmexit(vcpu_context &vc, uint32_t msr_address) noexcept;

/// @brief Disable vmexits for a range of model specific register accesses
///     via the wrmsr instruction with msr addresses in the range
///     @param begin to @param end (inclusive) during vcpu execution. 
///
/// @expects begin <= end
///
/// @param begin The lower bound of msr addresses to disable vmexits for
/// @param end The upper bound of msr addresses to disable wrmsr vmexits for
void disable_wrmsr_vmexit_range(vcpu_context &vc, uint32_t begin, uint32_t end) noexcept;

/// @brief Set a vmexit handler that will be called for all vmexits caused
///     by a wrmsr instruction while a vcpu is executing.
///
/// @param func The delegate function to be called
void set_wrmsr_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

/// @brief Returns the msr address of a wrmsr instruction that caused a
///     vmexit to occur while a vcpu was executing
///
/// @return The msr address used in a wrmsr instruction that caused a
///     vmexit to occur
uint32_t get_wrmsr_vmexit_address(vcpu_context &vc) noexcept;

/// @brief Returns the value of a wrmsr instruction that caused a
///     vmexit to occur while a vcpu was executing
///
/// @return The value used in a wrmsr instruction that caused a
///     vmexit to occur
uint64_t get_wrmsr_vmexit_value(vcpu_context &vc) noexcept;

/// @brief Emulate a wrmsr instruction that caused a vmexit to occur
///     while a vcpu was executing. The given value is written to the
///     msr (at the vmexit wrmsr address) instead of the value
///     that caused the vmexit to occur. 
///
void pass_through_wrmsr(vcpu_context &vc) noexcept;

/// @brief Emulate a wrmsr instruction that caused a vmexit to occur
///     while a vcpu was executing. The given value is written to the
///     msr (at the vmexit wrmsr address) instead of the value
///     that caused the vmexit to occur. 
///
/// @param value The value to be written to the msr
void provide_wrmsr_result(vcpu_context &vc, uint64_t value) noexcept;

}

#endif
