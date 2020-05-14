cmake_minimum_required(VERSION 3.13)
project(libvmm CXX ASM-ATT)
include(${CMAKE_CURRENT_LIST_DIR}/cmake/init_build.cmake)

add_library(libvmm)

target_include_directories(libvmm PUBLIC
    include
)

target_include_directories(libvmm PRIVATE
    src
)

target_link_libraries(libvmm bsl pal)

target_compile_options(libvmm PUBLIC
    "-fpie"
    "$<$<OR:$<COMPILE_LANGUAGE:ASM>,$<COMPILE_LANGUAGE:ASM-ATT>>:-c>"
    "$<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-fno-builtin>"
    "$<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-fno-common>"
    "$<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-ffreestanding>"
    "$<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-std=c++17>"
    "$<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-fno-exceptions>"
    "$<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-fno-rtti>"
    "$<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-nostdlib>"
    "$<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-nostdlibinc>"
    "$<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-mno-red-zone>"
    "$<$<STREQUAL:${LIBVMM_TARGET_ARCH},x86_64>:--target=x86_64-elf>"
    "$<$<STREQUAL:${LIBVMM_TARGET_ARCH},AMD64>:--target=amd64-elf>"
    "$<$<STREQUAL:${LIBVMM_TARGET_ARCH},armv8a>:--target=aarch64-elf>"
)

target_link_options(libvmm PUBLIC
    "-static"
    "-nostdlib"
)

set_target_properties(libvmm PROPERTIES
    PREFIX ""
)

add_subdirectory(src libvmm)
add_subdirectory(example)
add_subdirectory(test)

install(TARGETS libvmm DESTINATION lib/libvmm)
install(DIRECTORY include/ DESTINATION include)
