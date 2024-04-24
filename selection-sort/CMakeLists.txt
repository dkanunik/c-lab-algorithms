cmake_minimum_required(VERSION 3.27)
project(selectionSort C)

set(CMAKE_C_STANDARD 11)
set(C_COMPILER_LAUNCHER "gcc")

include_directories(${UNITY_LIBRARY_PATH})

set(SOURCE_FILES
        selectionSort.c
        testSelectionSort.c
        ${UNITY_LIBRARY_PATH}/unity.c
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC ${TEST_DATA_UTILS})