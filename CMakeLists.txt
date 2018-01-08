cmake_minimum_required(VERSION 2.8.4)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
include(${CMAKE_MODULE_PATH}/utils.cmake)

enable_language(Pascal)

add_library (pascalunit SHARED pascalunit.pas)

add_library (plugin   SHARED plugin.cpp)
target_link_libraries (plugin 
  pascalunit
)

add_executable (vtable coff.cpp)
target_link_libraries (vtable 
  plugin
)

