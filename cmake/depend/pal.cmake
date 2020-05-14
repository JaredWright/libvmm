message(STATUS "Adding dependency: pal")

FetchContent_Declare(
    pal
    GIT_REPOSITORY  https://github.com/bareflank/pal.git
    GIT_TAG         20.04.1
)

FetchContent_GetProperties(pal)

if(NOT pal_POPULATED)
    set(PAL_QUIET_CMAKE ON)
    set(PAL_TARGET_LANGUAGE c++11)
    set(PAL_OUTPUT_DIR ${CMAKE_BINARY_DIR}/depend/pal-generated-output)

    # TODO: Add a PAL print mechanism for bsl::print. Unil then, turn printing
    # (i.e. dump functions) off in the PAL
    set(PAL_PRINT_MECHANISM none)

    if(${LIBVMM_TARGET_ARCH} STREQUAL x86_64)
        set(PAL_TARGET_ARCH intel_x64)
        set(PAL_ACCESS_MECHANISM gas_att)
    elseif(${LIBVMM_TARGET_ARCH} STREQUAL AMD64)
        set(PAL_TARGET_ARCH intel_x64)
        set(PAL_ACCESS_MECHANISM gas_att)
    elseif(${LIBVMM_TARGET_ARCH} STREQUAL armv8a)
        set(PAL_TARGET_ARCH armv8a)
        set(PAL_ACCESS_MECHANISM gas_aarch64)
    endif()

    FetchContent_Populate(pal)

    add_subdirectory(${pal_SOURCE_DIR} ${pal_BINARY_DIR})
endif()
