#ifndef LIBVMM_VCPU_X64_INTEL_EPT_HPP
#define LIBVMM_VCPU_X64_INTEL_EPT_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Enable ept
void enable_ept(vcpu_context &vc) noexcept;

/// @brief Disable ept
void disable_ept(vcpu_context &vc) noexcept;

/// @brief Set the physical address of the base page table structure to be
///     used for ept
///
/// @param phys_addr The host physical address of a base page table structure
void set_ept_base_address(vcpu_context &vc, uintptr_t phys_addr) noexcept;

/// @brief Set a vmexit handler that will be called for all vmexits caused
///     by a memory access violation while a vcpu is executing with nested
///     paging enabled.
///
/// @param func The delegate function to be called
void set_ept_violation_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

/// @brief Set a vmexit handler that will be called for all vmexits caused
///     by a page table misconfiguration while a vcpu is executing with
///     ept enabled.
///
/// @param func The delegate function to be called
void set_ept_misconfiguration_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

/// @brief Returns true if the current vmexit execution context was
///     triggered as a result of a memory read operation
///
/// @return True if a memory read caused the current vmexit, else false
bool is_ept_vmexit_read(vcpu_context &vc) noexcept;

/// @brief Returns true if the current vmexit execution context was
///     triggered as a result of a memory write operation
///
/// @return True if a memory write caused the current vmexit, else false
bool is_ept_vmexit_write(vcpu_context &vc) noexcept;

/// @brief Returns true if the current vmexit execution context was
///     triggered as a result of a memory execute operation
///
/// @return True if a memory execute caused the current vmexit, else false
bool is_ept_vmexit_execute(vcpu_context &vc) noexcept;

/// @brief Returns true if the current vmexit execution context was
///     triggered as a result of a ept violation operation
///
/// @return True if a ept violation caused the current vmexit,
///     else false
bool is_ept_vmexit_violation(vcpu_context &vc) noexcept;

/// @brief Returns true if the current vmexit execution context was
///     triggered as a result of a ept  misconfiguration operation
///
/// @return True if a ept  misconfiguration caused the current
///     vmexit, else false
bool is_ept_vmexit_misconfiguration(vcpu_context &vc) noexcept;

}

#endif
