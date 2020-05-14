#ifndef LIBVMM_VCPU_X64_INTEL_INTERRUPT_WINDOW_HPP
#define LIBVMM_VCPU_X64_INTEL_INTERRUPT_WINDOW_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Enable vmexits for interrupt windows
void enable_interrupt_window_vmexit(vcpu_context &vc) noexcept;

/// @brief Disable vmexits for interrupt windows
void disable_interrupt_window_vmexit(vcpu_context &vc) noexcept;

/// @brief Set a vmexit handler that will be called for all vmexits caused
///     by an interrupt window vmexit while a vcpu is executing.
///
/// @param func The delegate function to be called
void set_interrupt_window_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

}

#endif
