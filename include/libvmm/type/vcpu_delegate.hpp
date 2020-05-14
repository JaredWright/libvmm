#ifndef LIBVMM_TYPE_VCPU_DELEGATE_HPP
#define LIBVMM_TYPE_VCPU_DELEGATE_HPP

#include <libvmm/type/vcpu_context.hpp>

namespace libvmm
{
    using vcpu_delegate = void(*)(vcpu_context &);
}

#endif
