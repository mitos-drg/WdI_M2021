cmake_minimum_required(VERSION 3.1)

project(Graphs C)

# Add data structure library
add_library(graphs graph_d.c)

# Add include directories
target_include_directories(graphs PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(graphs PRIVATE ${CMAKE_SOURCE_DIR}/include/cstd)

# link libraries
target_link_libraries(graphs PUBLIC cstd::data)

# Add convinient alias target
add_library(cstd::graphs ALIAS graphs)