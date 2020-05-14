set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

if(NOT CMAKE_C_COMPILER)
    if(CMAKE_HOST_SYSTEM_NAME STREQUAL Darwin)
        set(CMAKE_C_COMPILER llvm-clang)
    else()
        set(CMAKE_C_COMPILER clang)
    endif()
endif()

if(NOT CMAKE_CXX_COMPILER)
    if(CMAKE_HOST_SYSTEM_NAME STREQUAL Darwin)
        set(CMAKE_CXX_COMPILER llvm-clang++)
    else()
        set(CMAKE_CXX_COMPILER clang++)
    endif()
endif()

if(NOT CMAKE_ASM-ATT_COMPILER)
    if(CMAKE_HOST_SYSTEM_NAME STREQUAL Darwin)
        set(CMAKE_ASM-ATT_COMPILER llvm-clang)
    else()
        set(CMAKE_ASM-ATT_COMPILER clang)
    endif()
endif()

if(NOT CMAKE_ASM_COMPILER)
    if(CMAKE_HOST_SYSTEM_NAME STREQUAL Darwin)
        set(CMAKE_ASM_COMPILER llvm-clang)
    else()
        set(CMAKE_ASM_COMPILER clang)
    endif()
endif()

if(NOT CMAKE_AR)
    set(CMAKE_AR llvm-ar)
endif()

if(NOT LIBVMM_LINKER)
    set(LIBVMM_LINKER ld.lld)
endif()

string(CONCAT LIBVMM_LINK_FLAGS
    "-z max-page-size=0x1000 "
    "-z noexecstack "
)

set(CMAKE_C_LINK_EXECUTABLE
    "${LIBVMM_LINKER} ${LIBVMM_LINK_FLAGS} <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>"
)

set(CMAKE_CXX_LINK_EXECUTABLE
    "${LIBVMM_LINKER} ${LIBVMM_LINK_FLAGS} <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>"
)

set(CMAKE_C_ARCHIVE_CREATE
    "${CMAKE_AR} qc <TARGET> <OBJECTS>"
)

SET(CMAKE_C_ARCHIVE_FINISH
    ""
)

set(CMAKE_CXX_ARCHIVE_CREATE
    "${CMAKE_AR} qc <TARGET> <OBJECTS>"
)

SET(CMAKE_CXX_ARCHIVE_FINISH
    ""
)
