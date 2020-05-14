add_executable(vmcall_example)

target_sources(vmcall_example PRIVATE
    vmcall_example.cpp
)

target_link_libraries(vmcall_example libvmm)

set_target_properties(vmcall_example PROPERTIES
    SUFFIX ".vmm"
)
