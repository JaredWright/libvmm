add_executable(vmexit_example)

target_sources(vmexit_example PRIVATE
    vmexit_example.cpp
)

target_link_libraries(vmexit_example libvmm)

set_target_properties(vmexit_example PROPERTIES
    SUFFIX ".vmm"
)
