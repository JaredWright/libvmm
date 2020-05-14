#ifndef LIBVMM_VCPU_EXECUTE_HPP
#define LIBVMM_VCPU_EXECUTE_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <bsl/errc_type.hpp>

namespace libvmm
{

/// @brief Load a vcpu_context for execution on the physical cpu that executes
///     this function. This function does not yield execution to the vcpu,
///     but prepares the vcpu context so that it may be executed using run()
///
/// @return Returns 0 if the operation was successful, else an error code
bsl::errc_type load(vcpu_context &vc) noexcept;

/// @brief Unload the given vcpu_context from the physical cpu that executes
///     this function.
///
/// @return Returns 0 if the operation was successful, else an error code
bsl::errc_type unload(vcpu_context &vc) noexcept;

/// @brief Yield the execution of the physical cpu that executes this
///     function to a vcpu represented by the given vcpu_context.
///
/// @return This function will not return on success. On failure, an error
///     code is returned
bsl::errc_type run(vcpu_context &vc) noexcept;

}

#endif
