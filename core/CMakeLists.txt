set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(core_source_files
        Checker.cpp
        Checker.h
        Core.cpp
        Core.h
        FileSystem.cpp
        FileSystem.h
        )
add_library(core ${core_source_files})

target_link_libraries(core github reader)