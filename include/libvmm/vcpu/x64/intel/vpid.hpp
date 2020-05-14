#ifndef LIBVMM_VCPU_X64_INTEL_VPID_HPP
#define LIBVMM_VCPU_X64_INTEL_VPID_HPP

#include <libvmm/type/vcpu_context.hpp>
#include <libvmm/type/vcpu_delegate.hpp>
#include <bsl/cstdint.hpp>

namespace libvmm
{

void enable_vpid(vcpu_context &vc) noexcept;

}

#endif
