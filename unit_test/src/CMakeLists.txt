target_sources(bubble_sort_lib
    PRIVATE
        bubble_sort.cpp
    PUBLIC
        bubble_sort.hpp
)

target_include_directories(bubble_sort_lib PUBLIC
    "${PROJECT_SOURCE_DIR}/src"
)

target_sources(long_number_lib
    PRIVATE
        long_number.cpp
    PUBLIC
        long_number.hpp
)

target_include_directories(long_number_lib PUBLIC
    "${PROJECT_SOURCE_DIR}/src"
)