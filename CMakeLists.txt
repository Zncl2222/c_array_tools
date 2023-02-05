cmake_minimum_required(VERSION 2.4.0)
enable_testing()

# example
project(example)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(example example.c)

if(UNIX)
    target_link_libraries(example PRIVATE m)
endif()

if(WIN32)
    set_target_properties(example PROPERTIES SUFFIX ".exe")
else()
    set_target_properties(example PROPERTIES SUFFIX ".out")
endif()

# make sure example can run
add_test(
    example
    ${CMAKE_COMMAND}
    --build ${CMAKE_BINARY_DIR}
    --target example
)

# unittest
project(unittest)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test)

add_executable(unittest ./test/test.c)
add_test(
    unittest
    ${CMAKE_COMMAND}
    --build ${CMAKE_BINARY_DIR}
    --target unittest
)

if(UNIX)
    target_link_libraries(unittest PRIVATE m)
endif()

# memory check (valgrind)
find_program(VALGRIND "valgrind")

if(VALGRIND)
	add_custom_target(
        memcheck
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:example>
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest>
	)
endif()
