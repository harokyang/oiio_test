cmake_minimum_required (VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

project(oiio_test CXX)

add_executable (test "test.cpp")

find_package(OpenImageIO REQUIRED)
add_library(OpenImageIO::OpenImageIO UNKNOWN IMPORTED)
set_target_properties(OpenImageIO::OpenImageIO PROPERTIES IMPORTED_LOCATION ${OPENIMAGEIO_LIBRARIES})
set_target_properties(OpenImageIO::OpenImageIO PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${OPENIMAGEIO_INCLUDE_DIR})
target_link_libraries(test OpenImageIO::OpenImageIO)
