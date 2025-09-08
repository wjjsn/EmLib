cmake_minimum_required(VERSION 3.22)
enable_language(C CXX)

add_library(eLOG OBJECT)
target_sources(eLOG PRIVATE "${CMAKE_CURRENT_LIST_DIR}/elog.cpp")
target_include_directories(eLOG PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

target_link_libraries(${CMAKE_PROJECT_NAME} eLOG)