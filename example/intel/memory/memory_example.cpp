#include <libvmm/libvmm.hpp>
#include <libvmm/platform/memory.hpp>

constexpr const uint32_t SIZE_4KB = 0x1000;
constexpr const uint32_t SIZE_16KB = 0x4000;
constexpr const uint32_t SIZE_4MB = 0x400000;

bsl::exit_code main() noexcept
{
    // Allocate a virtual address space of 16 KB that is mapped to the physical
    // address 0xF00D0000, using the default 4 KB page granularity.
    char * bytes_1 = libvmm::alloc_hva_map<char>(0xF00D0000, SIZE_16KB);

    // Allocate a virtual address space of 4 MB that is mapped to the physical
    // address 0xBEEF0000, using 2 MB page granularity.
    uint32_t * bytes_2 = libvmm::alloc_hva_map<uint32_t>(
                             0xBEEF0000,
                             SIZE_4MB,
                             libvmm::page_size::page_2m
                         );

    // Allocate a virtual address space of 4 KB that is mapped to uncacheable
    // (device) memory at the physical address 0xCAFE0000, using 4 KB page
    // granularity.
    uint32_t * bytes_3 = libvmm::alloc_hva_map<uint32_t>(
                             0xCAFE0000,
                             SIZE_4KB,
                             libvmm::page_size::page_4k,
                             libvmm::memory_type::uncacheable
                         );

    // Resolve the host physical address that "bytes_1" is mapped to, which
    // will give 0xF00D0000
    uintptr_t bytes_2_host_phys_addr = libvmm::hva_to_hpa(bytes_1);

    return libvmm::start_vmm();
}
