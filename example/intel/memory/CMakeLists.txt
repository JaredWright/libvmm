add_executable(memory_example)

target_sources(memory_example PRIVATE
    memory_example.cpp
)

target_link_libraries(memory_example vmm)

set_target_properties(memory_example PROPERTIES
    SUFFIX ".vmm"
)
