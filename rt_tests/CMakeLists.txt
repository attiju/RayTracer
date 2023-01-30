add_executable(rt_library_tests tests.cpp)
target_link_libraries(rt_library_tests PRIVATE rt_library)
file(GLOB_RECURSE unit_test_files "rt_library_tests/*.cpp")
target_sources(
        rt_library_tests
        PRIVATE
        ${unit_test_files}
)
add_test(NAME rt_library_tests COMMAND $<TARGET_FILE:rt_library_tests>)
