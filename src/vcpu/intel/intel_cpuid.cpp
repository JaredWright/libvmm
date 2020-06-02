#include <libvmm/vcpu/x64/intel/cpuid.hpp>
#include <libvmm/vcpu/vcpu.hpp>
#include <vcpu_context/intel_vcpu_context.hpp>
#include <state_save/intel/intel_vmexit_state_save_interpreter.hpp>

namespace libvmm
{

void assert_is_intel_cpuid_vmexit_context(
        intel_vcpu_context &intel_vc,
        intel_vmexit_state_save_interpreter &interpreter
        )
{
    if(!interpreter.is_cpuid_vmexit_context(intel_vc)) {
        halt(intel_vc);
    }
}

void set_cpuid_vmexit_handler(vcpu_context &vc, vcpu_delegate func) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    // TODO: Implement Me!
    return;
}

uint32_t get_cpuid_vmexit_leaf(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vmexit_state_save_interpreter interpreter{};
    assert_is_intel_cpuid_vmexit_context(intel_vc, interpreter);

    return interpreter.get_cpuid_vmexit_leaf(intel_vc);
}

uint32_t get_cpuid_vmexit_subleaf(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vmexit_state_save_interpreter interpreter{};
    assert_is_intel_cpuid_vmexit_context(intel_vc, interpreter);

    return interpreter.get_cpuid_vmexit_subleaf(intel_vc);
}

void pass_through_cpuid(vcpu_context &vc) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vmexit_state_save_interpreter interpreter{};
    assert_is_intel_cpuid_vmexit_context(intel_vc, interpreter);

    auto leaf = get_cpuid_vmexit_leaf(vc);
    auto subleaf = get_cpuid_vmexit_subleaf(vc);
    // TODO: Implement Me!
    // auto [eax, ebx, ecx, edx] = pal::execute_cpuid(leaf, subleaf);
    uint32_t result[4] = {0, 0, 0, 0};
    auto [eax, ebx, ecx, edx] = result;
    provide_cpuid_result(intel_vc, eax, ebx, ecx, edx);
}

void provide_cpuid_result(vcpu_context &vc, uint32_t eax, uint32_t ebx, uint32_t ecx, uint32_t edx) noexcept
{
    auto &intel_vc = static_cast<intel_vcpu_context &>(vc);
    intel_vmexit_state_save_interpreter interpreter{};
    assert_is_intel_cpuid_vmexit_context(intel_vc, interpreter);

    intel_vc.set_rax(eax);
    intel_vc.set_rbx(ebx);
    intel_vc.set_rcx(ecx);
    intel_vc.set_rdx(edx);
}

}
