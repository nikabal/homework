#include "io.hpp"

#include <iostream>

void ban::print_array(const char* const comment,  std::vector<int>& arr, const int size) {
	const char format = ' ';
	std::cout << comment;
	for (int i = 0; i < size; i++) {
		std::cout << format << arr[i];
	}
	std::cout << std::endl;
}