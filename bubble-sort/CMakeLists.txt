cmake_minimum_required(VERSION 3.27)
project(bubbleSort C)

set(CMAKE_C_STANDARD 11)
set(C_COMPILER_LAUNCHER "gcc")

set(unity_LIBRARY_DIR /usr/local/lib)
set(test_data_utils_LIBRARY_DIR /usr/local/lib)

set(SOURCE_FILES
        bubbleSort.c
        testBubbleSort.c
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC test_data_utils unity)
