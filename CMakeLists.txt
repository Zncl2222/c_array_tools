cmake_minimum_required(VERSION 2.4.0)
enable_testing()

# example
project(example)
include(Dart)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
set(CTEST_COVERAGE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/coverage")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(example ${CMAKE_CURRENT_SOURCE_DIR}/src/c_array.c example.c)

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

set(TEST_FILES
    ./tests/test_short.c
    ./tests/test_int.c
    ./tests/test_long.c
    ./tests/test_float.c
    ./tests/test_double.c
)

set(TEST_LABELS
  unittest_short
  unittest_int
  unittest_long
  unittest_float
  unittest_double
)

list(LENGTH TEST_FILES NUM_TESTS)
math(EXPR NUM_TESTS "${NUM_TESTS}-1")

foreach(TEST_INDEX RANGE ${NUM_TESTS})
    list(GET TEST_FILES ${TEST_INDEX} TEST_FILE)
    list(GET TEST_LABELS ${TEST_INDEX} TEST_LABEL)
    add_executable(${TEST_LABEL} ${CMAKE_CURRENT_SOURCE_DIR}/src/c_array.c ${TEST_FILE})
    add_test(
        ${TEST_LABEL}
        ${CMAKE_COMMAND}
        --build ${CMAKE_BINARY_DIR}
        --target ${TEST_LABEL}
    )
    target_link_libraries(${TEST_LABEL} PRIVATE m)
endforeach()

add_executable(
    unittest_mt
    ${CMAKE_CURRENT_SOURCE_DIR}/src/c_array_mt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/c_array.c
    ./tests/test_mt.c
)

add_test(
    unittest_mt
    ${CMAKE_COMMAND}
    --build ${CMAKE_BINARY_DIR}
    --target unittest_mt
)

if(UNIX)
    target_link_libraries(unittest_mt PRIVATE m)
endif()

set(CTEST_COVERAGE_EXCLUDE
  '/usr/include/*' # Exclude system headers
  '${CMAKE_CURRENT_SOURCE_DIR}/tests/utest.h' # Exclude a specific file
)
add_custom_target(
    coverage
    COMMAND ctest -T Coverage
)

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
        $<TARGET_FILE:unittest_int>
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_short>
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_long>
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_float>
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_double>
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_mt>
	)
endif()
