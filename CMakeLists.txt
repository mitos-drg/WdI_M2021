cmake_minimum_required(VERSION 3.1)

project(WdI_MIM2021 C)

# Reduce the config types to only Debug and Release
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)
# Set project binary output (in source)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/libs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/libs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/libs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/libs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin)

# Use folders in project
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

### BASICS
add_executable(hello source/basics/hello.c)
set_target_properties(hello PROPERTIES FOLDER basics)

add_executable(eratostenes source/basics/eratostenes.c)
set_target_properties(eratostenes PROPERTIES FOLDER basics)

add_executable(files source/basics/files.c)
set_target_properties(files PROPERTIES FOLDER basics)


### SORTING
add_executable(quick source/sorting/quick_sort.c)
set_target_properties(quick PROPERTIES FOLDER sorting)

add_executable(merge source/sorting/merge_sort.c)
set_target_properties(merge PROPERTIES FOLDER sorting)

add_executable(heap source/sorting/heap_sort.c)
set_target_properties(heap PROPERTIES FOLDER sorting)

add_executable(heap2 source/sorting/heap_sort2.c)
set_target_properties(heap2 PROPERTIES FOLDER sorting)