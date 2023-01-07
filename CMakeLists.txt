cmake_minimum_required(VERSION 2.4.0)

project(unittest)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include header files
include_directories(src/)

# compile unit test
add_executable(unittest ./test/test.c)

set_target_properties(unittest PROPERTIES SUFFIX ".out")
