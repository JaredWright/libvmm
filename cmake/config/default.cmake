if(LIBVMM_TARGET_ARCH)
    set(_LIBVMM_TARGET_ARCH ${LIBVMM_TARGET_ARCH})
else()
    set(_LIBVMM_TARGET_ARCH ${CMAKE_HOST_SYSTEM_PROCESSOR})
endif()
libvmm_add_config(
    CONFIG_NAME LIBVMM_TARGET_ARCH
    CONFIG_TYPE STRING
    DEFAULT_VAL ${_LIBVMM_TARGET_ARCH}
    DESCRIPTION "The target architecture for the build"
    OPTIONS x86_64 AMD64 armv8a
)

libvmm_add_config(
    CONFIG_NAME LIBVMM_BUILD_EXAMPLES
    CONFIG_TYPE BOOL
    DEFAULT_VAL ON
    DESCRIPTION "Set true to build the examples"
)

libvmm_add_config(
    CONFIG_NAME LIBVMM_BUILD_TESTS
    CONFIG_TYPE BOOL
    DEFAULT_VAL ON
    DESCRIPTION "Set true to build tests"
)
