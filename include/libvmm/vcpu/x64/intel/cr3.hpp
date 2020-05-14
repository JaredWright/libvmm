#ifndef LIBVMM_VCPU_X64_INTEL_CR3_HPP
#define LIBVMM_VCPU_X64_INTEL_CR3_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Enable vmexits for all writes to control register cr3
///
/// @param vc The vcpu_context to operate on
void enable_cr3_read_vmexit(vcpu_context &vc) noexcept;

/// @brief Disable vmexits for all reads to control register cr3
///
/// @param vc The vcpu_context to operate on
void disable_cr3_read_vmexit(vcpu_context &vc) noexcept;

/// @brief Set a vmexit handler that will be called for all vmexits caused
///     by a read to control register cr3 while a vcpu is executing.
///
/// @param vc The vcpu_context to operate on
/// @param func The delegate function to be called
void set_cr3_read_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

/// @brief Emulate a read to cr3 that caused a vmexit to occur while a
///     vcpu was executing. The given value is written into the vcpu's
///     cr3, instead of the value that caused the vm exit to occur. 
///
/// @param vc The vcpu_context to operate on
/// @param cr3_value The value to be written to a vcpu's cr3
void provide_cr3_read_result(vcpu_context &vc, uint64_t cr3_value) noexcept;

/// @brief Enable vmexits for all writes to control register cr3
///
/// @param vc The vcpu_context to operate on
void enable_cr3_write_vmexit(vcpu_context &vc) noexcept;

/// @brief Disable vmexits for all writes to control register cr3
///
/// @param vc The vcpu_context to operate on
void disable_cr3_write_vmexit(vcpu_context &vc) noexcept;

/// @brief Set a vmexit handler that will be called for all vmexits caused
///     by a write to control register cr3 while a vcpu is executing.
///
/// @param vc The vcpu_context to operate on
/// @param func The delegate function to be called
void set_cr3_write_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

/// @brief Returns the value being written to control register cr3 that
///     caused a vmexit to occur while a vcpu was executing
///
/// @param vc The vcpu_context to operate on
///
/// @return The value written to cr3
uint64_t get_cr3_write_vmexit_value(vcpu_context &vc) noexcept;

/// @brief Emulate a write to cr3 that caused a vmexit to occur while a
///     vcpu was executing. The given value is written into the vcpu's
///     cr3, instead of the value that caused the vm exit to occur. 
///
/// @param vc The vcpu_context to operate on
/// @param cr3_value The value to be written to a vcpu's cr3
void provide_cr3_write_result(vcpu_context &vc, uint64_t cr3_value) noexcept;

}

#endif

