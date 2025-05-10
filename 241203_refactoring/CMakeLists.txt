project(second_refactoring)

add_executable(${PROJECT_NAME} main.cpp)

target_sources(second_refactoring
    PRIVATE
        io.cpp
        io.hpp
        sliyanie2.cpp
        sliyanie2.hpp
)

target_include_directories(second_refactoring PUBLIC
    "${PROJECT_SOURCE_DIR}/"
)