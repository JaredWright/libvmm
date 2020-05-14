#ifndef LIBVMM_VCPU_X64_INTEL_VMEXIT_HPP
#define LIBVMM_VCPU_X64_INTEL_VMEXIT_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Returns the basic vm exit reason that caused a vmexit while a
///     vcpu was running
///
/// @return The basic vm exit reason
uint32_t get_vmexit_reason(vcpu_context &vc) noexcept;

/// @brief Returns the basic vm exit qualification that caused a vmexit
///     while a vcpu was running
///
/// @return The basic vm exit qualification
uint32_t get_vmexit_qualification(vcpu_context &vc) noexcept;

/// @brief Set a vmexit handler that will be called for all vmexits that
///     occur while a vcpu is executing. This handler is called before
///     execution of all other user defined vmexit handlers.
///
/// @param func The delegate function to be called
void set_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

/// @brief Set a vmexit handler that gets called in the event that no user
///     defined vmexit handlers serviced a vmexit. This handler will get
///     called after execution of all user defined vmexit handlers for a
///     specific exit reason.
///
/// @param func The delegate function to be called
void set_post_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

}

#endif
