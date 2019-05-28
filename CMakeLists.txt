cmake_minimum_required (VERSION 2.6)
project (DataProvider)

set (Tutorial_VERSION_MAJOR 0)
set (Tutorial_VERSION_MINOR 0)

include_directories("${PROJECT_BINARY_DIR}/src")
add_executable(Demo src/demo.cpp)