cmake_minimum_required(VERSION 3.1)

project(Exercises C)

### 1st term
add_executable(e081221 exercises-08.12.21.c)
add_executable(e151221 exercises-15.12.21.c)

add_executable(e140322 exercises-14.03.22.c)
target_link_libraries(e140322 cstd::data)

add_executable(e110422 exercises-11.04.22.c)
target_link_libraries(e110422 cstd::data)

add_executable(e250422 exercises-25.04.22.c)
target_link_libraries(e250422 cstd::data)

add_executable(e300522 exercises-30.05.22.c)
target_link_libraries(e250422 cstd::data)