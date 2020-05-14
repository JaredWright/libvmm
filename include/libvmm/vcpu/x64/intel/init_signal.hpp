#ifndef LIBVMM_VCPU_X64_INTEL_INIT_SIGNAL_HPP
#define LIBVMM_VCPU_X64_INTEL_INIT_SIGNAL_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Set a vmexit handler that will be called for all vmexits caused
///     by an init signal while a vcpu is executing.
///
/// @param vc The vmexit_context to operate on
/// @param func The delegate function to be called
void set_init_signal_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

}

#endif
