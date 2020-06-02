#ifndef LIBVMM_STATE_SAVE_VMEXIT_STATE_SAVE_HPP
#define LIBVMM_STATE_SAVE_VMEXIT_STATE_SAVE_HPP

#include <libvmm/type/vmexit_id.hpp>

namespace libvmm
{

class vmexit_state_save
{
public:

    vmexit_state_save() noexcept = default;

    vmexit_id get_vmexit_id() noexcept
    { return vmexit_id; }

    void set_vmexit_id(vmexit_id value) noexcept
    { vmexit_id = value; }

    uint64_t get_vmexit_r0() noexcept
    { return vmexit_r0; }

    void set_vmexit_r0(uint64_t value) noexcept
    { vmexit_r0 = value; }

    uint64_t get_vmexit_r1() noexcept
    { return vmexit_r1; }

    void set_vmexit_r1(uint64_t value) noexcept
    { vmexit_r1 = value; }

    uint64_t get_vmexit_r2() noexcept
    { return vmexit_r2; }

    void set_vmexit_r2(uint64_t value) noexcept
    { vmexit_r2 = value; }

    uint64_t get_vmexit_r3() noexcept
    { return vmexit_r3; }

    void set_vmexit_r3(uint64_t value) noexcept
    { vmexit_r3 = value; }

private:
    vmexit_id vmexit_id;
    uint64_t vmexit_r0{0};
    uint64_t vmexit_r1{0};
    uint64_t vmexit_r2{0};
    uint64_t vmexit_r3{0};
};

}

#endif
