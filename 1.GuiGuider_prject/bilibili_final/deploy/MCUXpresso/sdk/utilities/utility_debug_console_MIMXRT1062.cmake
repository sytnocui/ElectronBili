include_guard(GLOBAL)
message("utility_debug_console component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
${CMAKE_CURRENT_LIST_DIR}/fsl_str.c
${CMAKE_CURRENT_LIST_DIR}/fsl_debug_console.c
)


target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
${CMAKE_CURRENT_LIST_DIR}/
)


include(component_serial_manager_MIMXRT1062)

include(driver_common_MIMXRT1062)

