#ifndef LIBVMM_VCPU_X64_INTEL_INTERRUPT_HPP
#define LIBVMM_VCPU_X64_INTEL_INTERRUPT_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Enable vmexits for all external interrupts that arrive during
///     execution of a vcpu
void enable_interrupt_vmexit(vcpu_context &vc) noexcept;

/// @brief Disable vmexits for all external interrupts that arrive during
///     execution of a vcpu
void disable_interrupt_vmexit(vcpu_context &vc) noexcept;

/// @brief Set a vmexit handler that will be called for all vmexits caused
///     by arrival of an external interrupt while a vcpu is executing.
///
/// @param func The delegate function to be called
void set_interrupt_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

/// @brief Inject an external interrupt into a vcpu
///
/// @param vector The vector of the external interrupt to be injected
void inject_interrupt(uint64_t vector) noexcept;

}

#endif
