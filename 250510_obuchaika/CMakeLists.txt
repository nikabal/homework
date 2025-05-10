project(obuchaika)

add_executable(${PROJECT_NAME} main.cpp)

target_sources(obuchaika
    PRIVATE
        menu_functions.cpp
        menu_functions.hpp
        menu_items.cpp
        menu_items.hpp
        menu.hpp
)

target_include_directories(obuchaika PUBLIC
    "${PROJECT_SOURCE_DIR}/"
)