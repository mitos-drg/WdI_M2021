cmake_minimum_required(VERSION 3.1)

project(DataStructures C)

# Add data structure library
add_library(datastruct list.c queue.c stack.c)

# Add include directories
target_include_directories(datastruct PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(datastruct PRIVATE ${CMAKE_SOURCE_DIR}/include/cstd)

# Add convinient alias target
add_library(cstd::data ALIAS datastruct)