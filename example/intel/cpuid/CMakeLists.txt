add_executable(cpuid_example)

target_sources(cpuid_example PRIVATE
    cpuid_example.cpp
)

target_link_libraries(cpuid_example libvmm)

set_target_properties(cpuid_example PROPERTIES
    SUFFIX ".vmm"
)
