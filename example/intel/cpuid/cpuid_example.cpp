#include <libvmm/libvmm.hpp>
#include <libvmm/vcpu/vcpu.hpp>
#include <libvmm/vcpu/x64/intel/intel.hpp>

#include <pal/cpuid/leaf_01_eax.h>
#include <pal/cpuid/leaf_01_ecx.h>

// This example demonstrates how to virtualize cpuid leaves on an x64 platform
// using the Bareflank Hypervisor SDK. The example adds a virtual cpuid leaf
// to the root vm at leaf number 0xBF000000, with emulated values returned in
// all cpuid output registers (eax, ebx, ecx, and edx). All other cpuid
// leaves/subleaves are passed through from the root vm to hardware.

void handle_cpuid_vmexit(libvmm::vcpu_context &vc) noexcept
{
    uint64_t leaf = libvmm::get_cpuid_vmexit_leaf(vc); 
    uint64_t subleaf = libvmm::get_cpuid_vmexit_subleaf(vc); 

    uint64_t rax_out;
    uint64_t rbx_out;
    uint64_t rcx_out;
    uint64_t rdx_out;

    switch(leaf) {
        case 0xBF000000:
            rax_out = 0xBFBFBFBF;
            rbx_out = 0x0;
            rcx_out = 0xFFFFFFFF;
            rdx_out = 0xA55A5AA5;
            libvmm::provide_cpuid_result(vc, rax_out, rbx_out, rcx_out, rdx_out);
            break;
        case 1:
            rax_out = pal::leaf_01_eax::get();
            rbx_out = 0x0;
            rcx_out = pal::leaf_01_ecx::get();
            rdx_out = 0x0;
            libvmm::provide_cpuid_result(vc, rax_out, rbx_out, rcx_out, rdx_out);
            break;
        default:
            libvmm::pass_through_cpuid(vc);
            break;
    }

    libvmm::advance_instruction_pointer(vc);
    libvmm::run(vc);
}

void init_root_vcpu(libvmm::vcpu_context &vc) noexcept
{
    libvmm::set_cpuid_vmexit_handler(vc, handle_cpuid_vmexit);
}

bsl::exit_code main() noexcept
{
    libvmm::set_vcpu_init_handler(init_root_vcpu);
    return libvmm::start_vmm();
}
