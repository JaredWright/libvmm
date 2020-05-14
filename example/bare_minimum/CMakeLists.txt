add_executable(bare_minimum_example)

target_sources(bare_minimum_example PRIVATE
    bare_minimum_example.cpp
)

target_link_libraries(bare_minimum_example libvmm)

set_target_properties(bare_minimum_example PROPERTIES
    SUFFIX ".vmm"
)
