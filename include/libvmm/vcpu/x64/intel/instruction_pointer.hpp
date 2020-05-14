#ifndef LIBVMM_VCPU_X64_INTEL_INSTRUCTION_POINTER_HPP
#define LIBVMM_VCPU_X64_INTEL_INSTRUCTION_POINTER_HPP

#include <libvmm/type/vcpu_context.hpp>

namespace libvmm
{

/// @brief Set the given vcpu_context to advance the instruciton pointer on the
///     next vmentry
///
/// @return 0 on success, non-0 on failure
void advance_instruction_pointer(vcpu_context &vc) noexcept;

}

#endif
