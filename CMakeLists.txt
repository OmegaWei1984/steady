cmake_minimum_required(VERSION 3.28)

SET(CMAKE_C_COMPILER clang)
project(steady C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")
find_package(CUnit REQUIRED)

file(GLOB SOURCES "src/*.c")
file(GLOB TEST_SUITES "tests/suite*")

include_directories(include)
add_executable(test
    tests/main.c
    ${TEST_SUITES}
    ${SOURCES}
)

target_link_libraries(test ${CUNIT_LIBRARIES})

