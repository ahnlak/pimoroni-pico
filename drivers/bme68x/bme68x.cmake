set(DRIVER_NAME bme68x)
add_library(${DRIVER_NAME} INTERFACE)

target_sources(${DRIVER_NAME} INTERFACE
  ${CMAKE_CURRENT_LIST_DIR}/src/bme68x.c
  ${CMAKE_CURRENT_LIST_DIR}/bme68x.cpp
)

target_include_directories(${DRIVER_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(${DRIVER_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src)

# Pull in pico libraries that we need
target_link_libraries(${DRIVER_NAME} INTERFACE pico_stdlib hardware_i2c pimoroni_i2c)

# We can't control the uninitialized result variables in the BME68X API
# so demote unitialized to a warning for this target.
target_compile_options(${DRIVER_NAME} INTERFACE -Wno-error=uninitialized)