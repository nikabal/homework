add_executable(test_bubble test_bubble.cpp)
target_link_libraries(test_bubble
    gtest_main
    gmock_main
    bubble_sort_lib
)

add_executable(test_long_number test_long_number.cpp)
target_link_libraries(test_long_number
    gtest_main
    gmock_main
    long_number_lib
)

add_test(test_bubble test_bubble)
add_test(test_long_number test_long_number)