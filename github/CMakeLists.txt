FIND_PACKAGE(CURL REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(GCC_COVERAGE_COMPILE_FLAGS "-lcurl")

set(github_source_files
        Github.cpp
        Github.h
        )
add_library(github ${github_source_files})

target_link_libraries(github core ${CURL_LIBRARIES})