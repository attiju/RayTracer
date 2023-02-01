cmake_minimum_required(VERSION 3.24)
project(rt)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -Werror -pedantic -g -fopenmp")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Wextra -Werror -pedantic -O3 -fopenmp")

# add application
add_subdirectory(rt_app)

# add library
add_subdirectory(rt_library)

# add tests
enable_testing()
add_subdirectory(rt_tests)