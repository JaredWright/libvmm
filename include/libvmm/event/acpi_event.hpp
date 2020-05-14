#ifndef LIBVMM_EVENT_ACPI_EVENT_HPP
#define LIBVMM_EVENT_ACPI_EVENT_HPP

#include <libvmm/type/vcpu_delegate.hpp>

namespace libvmm
{

/// @brief TODO
///
/// @param func The delegate function to be called
void set_acpi_s3_resume_handler(vcpu_delegate func) noexcept;

}

#endif
