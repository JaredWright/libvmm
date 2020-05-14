add_executable(msr_example)

target_sources(msr_example PRIVATE
    msr_example.cpp
)

target_link_libraries(msr_example libvmm)

set_target_properties(msr_example PROPERTIES
    SUFFIX ".vmm"
)
