# CROSS COMPILER SETTING
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_MINIMUM_REQUIRED (VERSION 3.10.0)

# THE VERSION NUMBER
SET (Tutorial_VERSION_MAJOR 1)
SET (Tutorial_VERSION_MINOR 0)

# ENABLE ASM
ENABLE_LANGUAGE(ASM)

SET(CMAKE_STATIC_LIBRARY_PREFIX)
SET(CMAKE_STATIC_LIBRARY_SUFFIX)

SET(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
SET(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

# CURRENT DIRECTORY
SET(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})

SET(EXECUTABLE_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})
SET(LIBRARY_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})


project(lvgl_guider)

set(MCUX_SDK_PROJECT_NAME lvgl_guider.elf)

include(${ProjDirPath}/./flags.cmake)

include(${ProjDirPath}/./config.cmake)

file(GLOB SOURCES
${ProjDirPath}/custom/*.c
${ProjDirPath}/custom/*.h
${ProjDirPath}/generated/*.c
${ProjDirPath}/generated/*.h
${ProjDirPath}/generated/images/*.c
${ProjDirPath}/generated/images/*.h
${ProjDirPath}/generated/guider_fonts/*.c
${ProjDirPath}/generated/guider_fonts/*.h
${ProjDirPath}/generated/guider_customer_fonts/*.c
${ProjDirPath}/generated/guider_customer_fonts/*.h
)

add_executable(${MCUX_SDK_PROJECT_NAME}
"${ProjDirPath}/board/board.c"
"${ProjDirPath}/board/board.h"
"${ProjDirPath}/board/clock_config.c"
"${ProjDirPath}/board/clock_config.h"
"${ProjDirPath}/board/dcd.c"
"${ProjDirPath}/board/dcd.h"
"${ProjDirPath}/board/lvgl_support.c"
"${ProjDirPath}/board/lvgl_support.h"
"${ProjDirPath}/board/pin_mux.c"
"${ProjDirPath}/board/pin_mux.h"
"${ProjDirPath}/source/FreeRTOSConfig.h"
"${ProjDirPath}/source/lv_conf.h"
"${ProjDirPath}/source/lvgl_guider.c"
${SOURCES}
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
${ProjDirPath}/source
${ProjDirPath}/board
${ProjDirPath}/generated
${ProjDirPath}/custom
${ProjDirPath}/generated/guider_customer_fonts
${ProjDirPath}/generated/guider_fonts
${ProjDirPath}/evkmimxrt1060/lvgl_examples/lvgl_guider
)

set(CMAKE_MODULE_PATH
${ProjDirPath}/.
${ProjDirPath}/CMSIS
${ProjDirPath}/component/lists
${ProjDirPath}/component/serial_manager
${ProjDirPath}/component/uart
${ProjDirPath}/device
${ProjDirPath}/drivers
${ProjDirPath}/freertos/freertos_kernel
${ProjDirPath}/lvgl
${ProjDirPath}/startup
${ProjDirPath}/touchpanel
${ProjDirPath}/utilities
${ProjDirPath}/video
${ProjDirPath}/xip
)

# include modules
include(driver_elcdif_MIMXRT1062)

include(driver_lpi2c_MIMXRT1062)

include(driver_ft5406_rt_MIMXRT1062)

include(driver_pxp_MIMXRT1062)

include(driver_cache_armv7_m7_MIMXRT1062)

include(driver_gt911_MIMXRT1062)

include(driver_video-common_MIMXRT1062)

include(middleware_freertos-kernel_heap_4_MIMXRT1062)

include(driver_common_MIMXRT1062)

include(driver_clock_MIMXRT1062)

include(middleware_lvgl_MIMXRT1062)

include(device_MIMXRT1062_CMSIS_MIMXRT1062)

include(utility_debug_console_MIMXRT1062)

include(component_lpuart_adapter_MIMXRT1062)

include(component_serial_manager_MIMXRT1062)

include(component_lists_MIMXRT1062)

include(component_serial_manager_uart_MIMXRT1062)

include(driver_lpuart_MIMXRT1062)

include(device_MIMXRT1062_startup_MIMXRT1062)

include(driver_iomuxc_MIMXRT1062)

include(utility_assert_MIMXRT1062)

include(driver_igpio_MIMXRT1062)

include(driver_xip_device_MIMXRT1062)

include(driver_xip_board_evkmimxrt1060_MIMXRT1062)

include(CMSIS_Include_core_cm_MIMXRT1062)

include(middleware_freertos-kernel_MIMXRT1062)

include(middleware_freertos-kernel_extension_MIMXRT1062)

include(utilities_misc_utilities_MIMXRT1062)

include(device_MIMXRT1062_system_MIMXRT1062)


TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE m)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE c)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE gcc)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE nosys)

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)


