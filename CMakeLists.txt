cmake_minimum_required(VERSION 3.5)
project(shinda)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CURL REQUIRED)

add_subdirectory(core)
add_subdirectory(github)
add_subdirectory(reader)

add_executable(shinda main.cpp)
target_link_libraries(shinda core github reader ${CURL_LIBRARIES})
