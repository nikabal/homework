#pragma once

namespace  ban {
struct MenuItem {
const char* const title;
void (*func)(const MenuItem* current);

const MenuItem* const *children;
const int children_count;

const MenuItem* parent;

const MenuItem* const *first_class_children;
const int first_class_children_count;
const MenuItem* parent; 
};
}