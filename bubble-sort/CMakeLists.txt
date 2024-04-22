cmake_minimum_required(VERSION 3.27)
project(bubbleSort C)

set(CMAKE_C_STANDARD 11)
set(C_COMPILER_LAUNCHER "gcc")

set(UNITY_LIBRARY_PATH /usr/local/src/unity)
set(TEST_UTILS_PATH /usr/local/src/_test_data_utils)

include_directories(${UNITY_LIBRARY_PATH})
include_directories(${TEST_UTILS_PATH})

set(SOURCE_FILES
        bubbleSort.c
        testBubbleSort.c
        ${UNITY_LIBRARY_PATH}/unity.c
        ${TEST_UTILS_PATH}/data_utils.c
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
