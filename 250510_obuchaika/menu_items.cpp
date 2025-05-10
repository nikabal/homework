#include "menu_items.hpp"
#include <cstddef>
#include "menu_functions.hpp"

const ban::MenuItem ban::FIRST_CLASS_RUS = {
    "1 - Русский язык", ban::first_class_rus, &ban::FIRST_CLASS, nullptr, 0
};
const ban::MenuItem ban::FIRST_CLASS_LITERATURE = {
    "2 - Русская литература", ban::first_class_literature, &ban::FIRST_CLASS, nullptr, 0
};
const ban::MenuItem ban::FIRST_CLASS_MATH = {
    "3 - Математика", ban::first_class_math, &ban::FIRST_CLASS, nullptr, 0
};
const ban::MenuItem ban::FIRST_CLASS_PHYSICAL_CULTURE = {
    "4 - Я люблю физкультуру", ban::first_class_physical_culture, &ban::FIRST_CLASS, nullptr, 0
};
const ban::MenuItem ban::FIRST_CLASS_GO_BACK = {
    "0 - Выйти в предыдущее меню", ban::first_class_go_back, &ban::FIRST_CLASS, nullptr, 0
};


namespace {
    const ban::MenuItem* const first_class_children[] = {
        &ban::FIRST_CLASS_GO_BACK,
        &ban::FIRST_CLASS_RUS,
        &ban::FIRST_CLASS_LITERATURE,
        &ban::FIRST_CLASS_MATH,
        &ban::FIRST_CLASS_PHYSICAL_CULTURE
    };
    const int first_class_size = sizeof(first_class_children)/sizeof(first_class_children[0]);
}

const ban::MenuItem ban::FIRST_CLASS = {
    "1 - Изучать предметы 1-го класса", ban::show_menu, &ban::CLASS, first_class_children, first_class_size
};
const ban::MenuItem ban::SECOND_CLASS = {
    "2 - Изучать предметы 2-го класса", ban::second_class, &ban::CLASS
};  
const ban::MenuItem ban::THIRD_CLASS = {
    "3 - Изучать предметы 3-го класса", ban::third_class, &ban::CLASS
};
const ban::MenuItem ban::CLASS_GO_BACK = {
    "0 - Выйти в главное меню", ban::class_go_back, &ban::CLASS
};

namespace {
    const ban::MenuItem* const class_children[] = {
        &ban::CLASS_GO_BACK,
        &ban::FIRST_CLASS,
        &ban::SECOND_CLASS,
        &ban::THIRD_CLASS
    };
    const int class_size = sizeof(class_children)/sizeof(class_children[0]);
}

const ban::MenuItem ban::CLASS = {
    "1 - Предметы какого класса вы хотите учить?", ban::show_menu, &ban::MAIN, class_children, class_size
};
const ban::MenuItem ban::EXIT = {
    "0 - Я уже закончил школу и все знаю", ban::exit, &ban::MAIN 
}; 

namespace {
    const ban::MenuItem* const main_children[] = {
        &ban::EXIT,
        &ban::CLASS
    };
    const int main_size = sizeof(main_children)/sizeof(main_children[0]);
}

const ban::MenuItem ban::MAIN = {
    nullptr, ban::show_menu, nullptr, main_children, main_size
};