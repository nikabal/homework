cmake_minimum_required(VERSION 3.2...3.27.5)

project(homework)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(171024_cpp_compilation)
add_subdirectory(181024_refactoring)
add_subdirectory(241203_refactoring)
add_subdirectory(250510_obuchaika)
add_subdirectory(unit_test)

set(CMAKE_SUPPRESS_REGENERATION true)