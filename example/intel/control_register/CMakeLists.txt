add_executable(control_register_example)

target_sources(control_register_example PRIVATE
    control_register_example.cpp
)

target_link_libraries(control_register_example libvmm)

set_target_properties(control_register_example PROPERTIES
    SUFFIX ".vmm"
)
