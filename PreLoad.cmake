if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL Windows)
    find_program(LIBVMM_NINJA "ninja")
    if(NOT LIBVMM_NINJA)
        message(FATAL_ERROR "Unable to find ninja (required to build on Windows)")
    else()
        message(STATUS "Using CMake Generator: Ninja")
    endif()
    set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "")
endif()

if(NOT CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_LIST_DIR}/cmake/toolchain/clang.cmake CACHE INTERNAL "")
endif()
