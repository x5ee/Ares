cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)

add_library(Ares SHARED)
target_sources(Ares PRIVATE Ares.cpp)

add_subdirectory(Client)
add_subdirectory(Includes)

target_link_libraries(Ares PRIVATE minhook)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})