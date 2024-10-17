#include <cmath>
#include <iostream>

int main() {
	double angle;
    std::cout << "Введите угол:" << std::endl;
    std::cin >> angle;
	
    if (cos(2 * angle) != 1) {
		doble value_f_x1
        doble value_f_x1 = (1 + sin(2 * angle)) / (1 - cos(2 * angle));
        std::cout << "F(x1)=" << value_f_x1 << std::endl;
    } else if (cos(2 * angle) == 1) {
		std::cout << "Неверный ввод для F(x1) " << std::endl;
	}

    if (tan(angle) != 1) {
		double value_f_x2
        value_f_x2 = 
			(1 + tan(angle) * tan(angle)) 
			/ 
			(1 - tan(angle) * tan(angle));
        std::cout << "F(X2)=" << value_f_x2 << std::endl;
    } else if (tan(angle) == 1) {
        std::cout << "Неверный ввод для F(x2) " << std::endl;
	}

    return 0;
}
