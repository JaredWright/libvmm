#ifndef LIBVMM_TYPE_VCPU_CONTEXT_HPP
#define LIBVMM_TYPE_VCPU_CONTEXT_HPP

namespace libvmm
{

class vcpu_context
{
public:
    virtual ~vcpu_context() noexcept = default;
protected:
    vcpu_context() noexcept = default;
    vcpu_context(vcpu_context &&) noexcept = default;
    vcpu_context &operator=(vcpu_context &&) noexcept = default;
    vcpu_context(vcpu_context const &) = delete;
    vcpu_context &operator=(vcpu_context const &) & = delete;
};

}

#endif
