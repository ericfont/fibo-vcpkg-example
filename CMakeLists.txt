cmake_minimum_required(VERSION 3.15)

project(fibo CXX)

find_package(fmt REQUIRED)
find_package(range-v3 REQUIRED)
find_package(cxxopts REQUIRED)

add_executable(fibo src/main.cxx)
target_compile_features(fibo PRIVATE cxx_std_17)

target_link_libraries(fibo
  PRIVATE
    fmt::fmt
    range-v3::range-v3
    cxxopts::cxxopts)

set_target_properties( fibo
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/archive"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/library"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/runtime"
)

# store git log info
execute_process(
  COMMAND git log -1 --format=medium
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
  OUTPUT_FILE "VERSION"
)

add_custom_command(TARGET fibo
  POST_BUILD
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/runtime
  COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/README.md" .
  COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/LICENSE" .
  COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/VERSION" .
  COMMAND ${CMAKE_COMMAND} -E tar -cfv "${CMAKE_BINARY_DIR}/fibo.zip" --format=zip .
)
