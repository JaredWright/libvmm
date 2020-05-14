#ifndef LIBVMM_VCPU_X64_INTEL_MONITOR_TRAP_HPP
#define LIBVMM_VCPU_X64_INTEL_MONITOR_TRAP_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Enable vmexits for all instructions that execute on a vcpu
void enable_monitor_trap_vmexit(vcpu_context &vc) noexcept;

/// @brief Disable vmexits for all instructions that execute on a vcpu
void disable_monitor_trap_vmexit(vcpu_context &vc) noexcept;

/// @brief Set a vmexit handler that will be called for all monitor trap
///     vmexits caused by exectuion of a vcpu
///
/// @param func The delegate function to be called
void set_monitor_trap_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

}

#endif
