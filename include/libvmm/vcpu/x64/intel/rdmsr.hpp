#ifndef LIBVMM_VCPU_X64_INTEL_RDMSR_HPP
#define LIBVMM_VCPU_X64_INTEL_RDMSR_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Enable vmexits for a model specific register accesses via the
///     rdmsr instruction at the specified msr address during vcpu execution. 
///
/// @param msr_address The msr address to enable rdmsr vmexits for
void enable_rdmsr_vmexit(vcpu_context &vc, uint32_t msr_address) noexcept;

/// @brief Enable vmexits for a range of model specific register accesses
///     via the rdmsr instruction with msr addresses in the range
///     @param begin to @param end (inclusive) during vcpu execution. 
///
/// @expects begin <= end
///
/// @param begin The lower bound of msr addresses to enable vmexits for
/// @param end The upper bound of msr addresses to enable rdmsr vmexits for
void enable_rdmsr_vmexit_range(vcpu_context &vc, uint32_t begin, uint32_t end) noexcept;

/// @brief Disable vmexits for a model specific register accesses via the
///     rdmsr instruction at the specified msr address during vcpu execution. 
///
/// @param msr_address The msr address to disable rdmsr vmexits for
void disable_rdmsr_vmexit(vcpu_context &vc, uint32_t msr_address) noexcept;

/// @brief Disable vmexits for a range of model specific register accesses
///     via the rdmsr instruction with msr addresses in the range
///     @param begin to @param end (inclusive) during vcpu execution. 
///
/// @expects begin <= end
///
/// @param begin The lower bound of msr addresses to disable vmexits for
/// @param end The upper bound of msr addresses to disable rdmsr vmexits for
void disable_rdmsr_vmexit_range(vcpu_context &vc, uint32_t begin, uint32_t end) noexcept;

/// @brief Set a vmexit handler that will be called for all vmexits caused
///     by a rdmsr instruction while a vcpu is executing.
///
/// @param func The delegate function to be called
void set_rdmsr_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

/// @brief Returns the msr address of a rdmsr instruction that caused a
///     vmexit to occur while a vcpu was executing
///
/// @return The msr address used in a rdmsr instruction that caused a
///     vmexit to occur
uint32_t get_rdmsr_vmexit_address(vcpu_context &vc) noexcept;

/// @brief TODO
///
void pass_through_rdmsr(vcpu_context &vc) noexcept;

/// @brief Emulate a rdmsr instruction that caused a vmexit to occur
///     while a vcpu was executing. The given value is read into the
///     vcpu's destination registers, instead of the value at the physical
///     machine's msr.
///
/// @param value The value to be emulated as a the result of a rdmsr
///     instruction
void provide_rdmsr_result(vcpu_context &vc, uint64_t value) noexcept;

}

#endif
