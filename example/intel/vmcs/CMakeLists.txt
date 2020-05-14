add_executable(vmcs_example)

target_sources(vmcs_example PRIVATE
    vmcs_example.cpp
)

target_link_libraries(vmcs_example libvmm)

set_target_properties(vmcs_example PROPERTIES
    SUFFIX ".vmm"
)
