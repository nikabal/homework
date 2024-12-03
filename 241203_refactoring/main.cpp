#include "sliyanie2.hpp"

#include <iostream>

int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = arr.size();

    ban::merge_sort(arr, 0, arr_size - 1);

    std::cout << "Сортированный массив: ";

    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
