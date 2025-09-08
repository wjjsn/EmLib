cmake_minimum_required(VERSION 3.22)
enable_language(C)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
#通过注释和解除注释来使用外部库
add_subdirectory(CherryRB)
add_subdirectory(SEGGER_RTT)
add_subdirectory(HAL)
add_subdirectory(Hardware)
add_subdirectory(eLOG)