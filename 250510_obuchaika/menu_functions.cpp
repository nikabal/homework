#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const ban::MenuItem*  ban::show_menu(const MenuItem* current) {

std::cout << "Главное меню" << std::endl;
for (int i = 1; i < current->children_count; i++) {
    std::cout << current->children[i]->title << std::endl;
}
std::cout << current->children[0]->title << std::endl;

int user_input;
std::cin >> user_input;
std::cout << std::endl;

return current->children[user_input];

}

const ban::MenuItem* ban::exit(const MenuItem* current) {
    std::exit(0);
}


const ban::MenuItem*  ban::first_class(const MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}

const ban::MenuItem*  ban::second_class(const MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}

const ban::MenuItem*  ban::third_class(const MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}

const ban::MenuItem* ban::class_go_back(const MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent->parent;
}




const ban::MenuItem*  ban::first_class_rus(const MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}
const ban::MenuItem*  ban::first_class_literature(const MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}
const ban::MenuItem*  ban::first_class_math(const MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}
const ban::MenuItem*  ban::first_class_physical_culture(const MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}
const ban::MenuItem* ban::first_class_go_back(const MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent->parent;
}