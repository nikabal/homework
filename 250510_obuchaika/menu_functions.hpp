#pragma once
#include "menu.hpp"

namespace ban {
    const MenuItem*  show_menu(const MenuItem* current);
    const MenuItem*  exit(const MenuItem* current);

    const MenuItem* first_class(const MenuItem* current);
    const MenuItem* second_class(const MenuItem* current);
    const MenuItem* third_class(const MenuItem* current);
    const MenuItem* class_go_back(const MenuItem* current);

    const MenuItem* first_class_rus(const MenuItem* current);
    const MenuItem* first_class_literature(const MenuItem* current);
    const MenuItem* first_class_math(const MenuItem* current);
    const MenuItem* first_class_physical_culture(const MenuItem* current);
    const MenuItem* first_class_go_back(const MenuItem* current);
}