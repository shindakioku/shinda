set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(reader_source_files
        Json.cpp
        Json.h
        Reader.cpp
        Reader.h
        )
add_library(reader ${reader_source_files})

target_link_libraries(reader core)