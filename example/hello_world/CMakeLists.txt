add_executable(hello_world_example)

target_sources(hello_world_example PRIVATE
    hello_world_example.cpp
)

target_link_libraries(hello_world_example libvmm)

set_target_properties(hello_world_example PROPERTIES
    SUFFIX ".vmm"
)
