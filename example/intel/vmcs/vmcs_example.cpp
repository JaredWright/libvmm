#include <libvmm/libvmm.hpp>
#include <libvmm/vcpu/vcpu.hpp>

#include <pal/vmcs/eptp.h>
#include <pal/vmcs/exit_reason.h>

void init_root_vcpu(libvmm::vcpu_context &vc) noexcept
{
    // You can interact with the VMCS associated with this function's given vcpu
    // through the Bareflank Processor Abstraction Layer (PAL). The PAL has
    // accessor functions (get/set) for VMCS registers, and fields within those
    // registers. For example:
    auto eptp = pal::eptp::get();
    auto ept_levels = pal::eptp::ept_page_walk_length::get();

    // You can read and write directly to a VMCS field:
    pal::eptp::ept_pml4_table::set(0xDEADBEEF);
    auto pml4 = pal::eptp::ept_pml4_table::get();

    // Or you can read and write using intermediate integer values:
    auto reason = pal::exit_reason::get();
    auto basic_reason = pal::exit_reason::basic_exit_reason::get(reason);
    auto vmentry_failure = pal::exit_reason::vm_entry_failure::is_enabled(reason);

    return;
}

bsl::exit_code main() noexcept
{
    libvmm::set_vcpu_init_handler(init_root_vcpu);
    return libvmm::start_vmm();
}
