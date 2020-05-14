#ifndef LIBVMM_VCPU_X64_INTEL_CPUID_HPP
#define LIBVMM_VCPU_X64_INTEL_CPUID_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Set a vmexit handler that will be called for all vmexits caused
///     by execution of a cpuid instruction while the given vcpu_context is
///     executing.
///
/// @param vc The vcpu_context to operate on
/// @param func The delegate function to be called
void set_cpuid_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

/// @brief Returns the cpuid leaf (value in register eax) that caused
///     a vmexit to occur when the given vcpu_context executed a cpuid
///     instruction
///
/// @param vc The vcpu_context to operate on
///
/// @return The cpuid leaf that caused a vmexit to occur
uint32_t get_cpuid_vmexit_leaf(vcpu_context &vc) noexcept;

/// @brief Returns the cpuid subleaf (value in register ecx) that caused
///     a vmexit to occur when the given vcpu_context executed a cpuid
///     instruction
///
/// @param vc The vcpu_context to operate on
///
/// @return The cpuid subleaf that caused a vmexit to occur
uint32_t get_cpuid_vmexit_subleaf(vcpu_context &vc) noexcept;

/// @brief TODO
///
/// @param vc The vcpu_context to operate on
void pass_through_cpuid(vcpu_context &vc) noexcept;

/// @brief Provide the result of a cpuid instruction to the given
///     vcpu_context. The given values are written into the context's general
///     registers eax, ebx, ecx, and edx.
///
/// @param vc The vcpu_context to operate on
/// @param eax The emulated output value to place in register eax
/// @param ebx The emulated output value to place in register ebx
/// @param ecx The emulated output value to place in register ecx
/// @param edx The emulated output value to place in register edx
void provide_cpuid_result(vcpu_context &vc, uint32_t eax, uint32_t ebx, uint32_t ecx, uint32_t edx) noexcept;

}

#endif
