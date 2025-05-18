cmake_minimum_required(VERSION 3.10)
project(libquery)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(LIBQUERY_OUT_PATH
    ${PROJECT_SOURCE_DIR}/lib
)
set(LIBQUERY_INCLUDE_DIR
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/query
)

file(GLOB LIBQUERY_SRC 
    "${PROJECT_SOURCE_DIR}/src/*.cc"
)

# static
add_library(libquery_static STATIC
    ${LIBQUERY_SRC}
)
target_include_directories(libquery_static PUBLIC
    ${LIBQUERY_INCLUDE_DIR}
)
set_target_properties(libquery_static PROPERTIES
    OUTPUT_NAME "query"
    ARCHIVE_OUTPUT_DIRECTORY ${LIBQUERY_OUT_PATH}
    POSITION_INDEPENDENT_CODE ON
)

# shared
add_library(libquery_shared SHARED
    ${LIBQUERY_SRC}
)
target_include_directories(libquery_shared PUBLIC
    ${LIBQUERY_INCLUDE_DIR}
)
set_target_properties(libquery_shared PROPERTIES
    OUTPUT_NAME "query"
    LIBRARY_OUTPUT_DIRECTORY ${LIBQUERY_OUT_PATH}
)

add_subdirectory(test)
