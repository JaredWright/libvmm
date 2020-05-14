#ifndef LIBVMM_VCPU_X64_INTEL_NMI_WINDOW_HPP
#define LIBVMM_VCPU_X64_INTEL_NMI_WINDOW_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Enable vmexits for nmi windows that occur during
///     execution of a vcpu
void enable_nmi_window_vmexit(vcpu_context &vc) noexcept;

/// @brief Disable vmexits for nmi windows that occur during
///     execution of a vcpu
void disable_nmi_window_vmexit(vcpu_context &vc) noexcept;

/// @brief Set a vmexit handler that will be called for all vmexits caused
///     by an nmi window while a vcpu is executing.
///
/// @param func The delegate function to be called
void set_nmi_window_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

}

#endif
