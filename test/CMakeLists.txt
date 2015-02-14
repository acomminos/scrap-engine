enable_testing ()

set (TEST_SOURCES
    test_obj_loader.cc
    )

add_subdirectory (gtest-1.7.0)
include_directories (${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable (tests ${TEST_SOURCES})
target_link_libraries (tests gtest gtest_main)
add_test (tests tests)
