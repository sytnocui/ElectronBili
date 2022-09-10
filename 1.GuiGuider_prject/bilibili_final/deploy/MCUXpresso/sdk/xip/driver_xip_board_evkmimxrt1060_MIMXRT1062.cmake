include_guard(GLOBAL)
message("driver_xip_board_evkmimxrt1060 component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
${CMAKE_CURRENT_LIST_DIR}/evkmimxrt1060_flexspi_nor_config.c
)


target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
${CMAKE_CURRENT_LIST_DIR}/
)


include(driver_common_MIMXRT1062)
