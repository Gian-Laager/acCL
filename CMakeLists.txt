cmake_minimum_required(VERSION 3.17)
project(acCL)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCL)
include_directories(${OpenCL_INCLUDE_DIRS})
link_libraries(${OpenCL_LIBRARIES})

set(SRC
        ${CMAKE_CURRENT_LIST_DIR}/src/acCL.cpp
        )

set(PCH ${CMAKE_CURRENT_LIST_DIR}/include/pch.h)

set(HEAD
        ${CMAKE_CURRENT_LIST_DIR}/include/acCL.h
        )
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_library(${PROJECT_NAME} SHARED ${SRC} ${HEAD})
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX _d)
target_precompile_headers(${PROJECT_NAME} PRIVATE ${PCH})

set(TEST_DIR
        ${CMAKE_CURRENT_LIST_DIR}/test
        )

set(TEST_SRC
        ${TEST_DIR}/src/test_main.cpp
        )

set(TEST_PCH ${TEST_DIR}/include/test_pch.h)

set(TEST_HEAD
        )

set(UNIT_TEST_TARGET unit_tests)

add_executable(${UNIT_TEST_TARGET} ${TEST_SRC} ${TEST_HEAD})
target_precompile_headers(${UNIT_TEST_TARGET} PRIVATE ${TEST_PCH})
set_target_properties(${UNIT_TEST_TARGET} PROPERTIES DEBUG_POSTFIX _d)
target_include_directories(${UNIT_TEST_TARGET} PRIVATE ${TEST_DIR}/include)

target_link_libraries(${UNIT_TEST_TARGET} ${PROJECT_NAME})
target_include_directories(${UNIT_TEST_TARGET} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/deps/googletest/googletest/include)
target_link_libraries(${UNIT_TEST_TARGET} ${CMAKE_CURRENT_LIST_DIR}/deps/googletest/build/lib/libgtest.a)
