#ifndef LIBVMM_VCPU_X64_INTEL_NMI_HPP
#define LIBVMM_VCPU_X64_INTEL_NMI_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Enable vmexits for all non-maskable interrupts that arrive
///     during execution of a vcpu
void enable_nmi_vmexit(vcpu_context &vc) noexcept;

/// @brief Disable vmexits for all non-maskable interrupts that arrive
///     during execution of a vcpu
void disable_nmi_vmexit(vcpu_context &vc) noexcept;

/// @brief Set a vmexit handler that will be called for all vmexits caused
///     by arrival of a non-maskable interrupt while a vcpu is executing.
///
/// @param func The delegate function to be called
void set_nmi_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

/// @brief Inject a non-maskable interrupt into a vcpu
void inject_nmi(vcpu_context &vc) noexcept;

}

#endif
