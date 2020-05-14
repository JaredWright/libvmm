include(${CMAKE_CURRENT_LIST_DIR}/color.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/function/libvmm_add_config.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/config/default.cmake)

include(FetchContent)
set(FETCHCONTENT_BASE_DIR ${CMAKE_BINARY_DIR}/depend)
set(FETCHCONTENT_QUIET ON)

include(${CMAKE_CURRENT_LIST_DIR}/depend/bsl.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/depend/pal.cmake)
