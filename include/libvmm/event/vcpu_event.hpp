#ifndef LIBVMM_EVENT_VCPU_EVENT_HPP
#define LIBVMM_EVENT_VCPU_EVENT_HPP

#include <libvmm/type/vcpu_delegate.hpp>

namespace libvmm
{

/// @brief Set a vmexit handler that will be called to initialize the given
///     vcpu_context.
///
/// @param func The delegate function to be called
void set_vcpu_init_handler(vcpu_delegate func) noexcept;

/// @brief Set a vmexit handler that will be called just prior to to destroying
///     the given vcpu_context.
///
/// @param func The delegate function to be called
void set_vcpu_fini_handler(vcpu_delegate func) noexcept;

}

#endif
