cmake_minimum_required(VERSION 3.24)
project(rt)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -pedantic -g")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Wextra -pedantic -O3")

# add application
add_subdirectory(rt_app)

# add library
add_subdirectory(rt_library)

# add tests
enable_testing()
add_subdirectory(rt_tests)