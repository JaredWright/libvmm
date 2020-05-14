#ifndef LIBVMM_VCPU_X64_INTEL_XCR0_HPP
#define LIBVMM_VCPU_X64_INTEL_XCR0_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

/// @brief Set a vmexit handler that will be called for all vmexits caused
///     by a write to extended control register xcr0 using the xgetbv
///     instruction while a vcpu is executing.
///
/// @param func The delegate function to be called
void set_xcr0_write_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept;

}

#endif
