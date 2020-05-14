add_executable(io_port_example)

target_sources(io_port_example PRIVATE
    io_port_example.cpp
)

target_link_libraries(io_port_example libvmm)

set_target_properties(io_port_example PROPERTIES
    SUFFIX ".vmm"
)
