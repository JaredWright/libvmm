#ifndef LIBVMM_STATE_SAVE_VMEXIT_STATE_SAVE_INTERPRETER_HPP
#define LIBVMM_STATE_SAVE_VMEXIT_STATE_SAVE_INTERPRETER_HPP

#include <libvmm/type/vmexit_id.hpp>
#include <state_save/vmexit_state_save.hpp>

namespace libvmm
{

class intel_vmexit_state_save_interpreter
{
public:

    intel_vmexit_state_save_interpreter() noexcept = default;

    bool is_cpuid_vmexit_context(vmexit_state_save &vme_ss) noexcept
    {
        auto vmexit_id = vme_ss.get_vmexit_id();
        if(vmexit_id == libvmm::vmexit_id::intel_cpuid) {
            return true;
        }
        return false;
    }

    uint32_t get_cpuid_vmexit_leaf(vmexit_state_save &vme_ss) noexcept
    {
        return vme_ss.get_vmexit_r0();
    }

    uint32_t get_cpuid_vmexit_subleaf(vmexit_state_save &vme_ss) noexcept
    {
        return vme_ss.get_vmexit_r1();
    }

    void set_cpuid_vmexit_context(vmexit_state_save &vme_ss, uint32_t leaf, uint32_t subleaf) noexcept
    {
        vme_ss.set_vmexit_id(libvmm::vmexit_id::intel_cpuid);
        vme_ss.set_vmexit_r0(leaf);
        vme_ss.set_vmexit_r1(subleaf);
        return;
    }

};

}

#endif
