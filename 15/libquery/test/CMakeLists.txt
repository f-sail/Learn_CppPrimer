cmake_minimum_required(VERSION 3.10)
project(libquery_test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(TEST_OUT_PATH
    ${PROJECT_SOURCE_DIR}/bin
)
# set(TEST_INCLUDE_DIR
#     ${PROJECT_SOURCE_DIR}/../include
#     ${PROJECT_SOURCE_DIR}/../include/query
# )

# libquery
add_library(libquery STATIC IMPORTED)
set_target_properties(libquery PROPERTIES
    IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/../lib/libquery.a
    INTERFACE_INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/../include
)

set(TEST_SRC
  ${PROJECT_SOURCE_DIR}/src/test.cc
)

add_executable(test.out
    ${TEST_SRC}
)
# target_include_directories(test.out PUBLIC
#     ${TEST_INCLUDE_DIR}
# )
target_link_libraries(test.out PRIVATE
    libquery
)
set_target_properties(test.out 
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${TEST_OUT_PATH}
)
