#include <libvmm/libvmm.hpp>
#include <libvmm/vcpu/vcpu.hpp>

// #include <bsl/print.hpp> // <-- I don't think this work in a vmm context yet

void handle_vcpu_init(libvmm::vcpu_context &vc) noexcept
{
    // The following would print once on each host cpu right after it is
    // initilized
    //
    // bsl::print() << "Your host is now in a vm";
    return;
}

void handle_vcpu_fini(libvmm::vcpu_context &vc) noexcept
{
    // The following would print once on each host cpu right before it is
    // destroyed
    //
    // bsl::print() << "Your host is not in a vm";
    return;
}

bsl::exit_code main() noexcept
{
    libvmm::set_vcpu_init_handler(handle_vcpu_init);
    libvmm::set_vcpu_fini_handler(handle_vcpu_fini);
    // bsl::print() << "Root virtual machine initialized";

    return libvmm::start_vmm();
}
