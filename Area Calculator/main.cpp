#include <iostream>
#include <algorithm>
#include <cmath>

const float PI = 3.141592653f;

bool checkInputValidity() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
	return true;
}

int main() {
	std::string command = "";
	bool operationComplete = false;
	double area = 0;
	double perimiter = 0;

	double var1 = 0;
	double var2 = 0;
	while (true) {
		std::cout << "Input a shape! (C)ircle, (S)quare, (R)ectangle, Right Angle (T)riangle, (Q)uit!"
			<<std::endl;
		std::cin >> command;
		// make input lowercase
		std::transform(command.begin(), command.end(), command.begin(), std::tolower);
		char op = command[0];
		switch (op) {
		case 'c':
			while (true) {
				std::cout << "Input the radius of the circle! : " << std::endl;
				std::cin >> var1;
				if (!checkInputValidity()) {
					std::cout << "The input was not recognised. Try again." << std::endl;
					continue;
				}
				area = PI * std::pow(var1, 2);
				perimiter = 2 * PI * var1;
				break;
			}
			operationComplete = true;
			break;
		case 's':
			while (true) {
				std::cout << "Input the side length of the square! : " << std::endl;
				std::cin >> var1;
				if (!checkInputValidity()) {
					std::cout << "The input was not recognised. Try again." << std::endl;
					continue;
				}
				area = std::pow(var1, 2);
				perimiter = 4 * var1;
				break;
			}
			operationComplete = true;
			break;
		case 'r':
			while (true) {
				std::cout << "Input the first side of the rectangle! : " << std::endl;
				std::cin >> var1;
				if (!checkInputValidity()) {
					std::cout << "The input was not recognised. Try again." << std::endl;
					continue;
				}
				std::cout << "Input the second side of the rectangle! : " << std::endl;
				std::cin >> var2;
				if (!checkInputValidity()) {
					std::cout << "The input was not recognised. Try again." << std::endl;
					continue;
				}
				area = var1 * var2;
				perimiter = 2*(var1 + var2);
				break;
			}
			operationComplete = true;
			break;
		case 't':
			while (true) {
				std::cout << "Input the height of the triangle!" << std::endl;
				std::cin >> var1;
				if (!checkInputValidity()) {
					std::cout << "The input was not recognised. Try again." << std::endl;
					continue;
				}
				std::cout << "Input the corresponding sidelength! : " << std::endl;
				std::cin >> var2;
				if (!checkInputValidity()) {
					std::cout << "The input was not recognised. Try again." << std::endl;
					continue;
				}
				area = (var1 * var2)/2;
				perimiter = var1 + var2 + std::sqrt(std::pow(var1, 2) + std::pow(var2, 2));
				break;
			}
			operationComplete = true;
			break;
		case 'q':
			std::cout << "Goodbye!" << std::endl;
			return 0;
		default:
			std::cout << "Command " << op << " is not a recognised operation. Try again."
				<< std::endl;
			break;
		}

		if (operationComplete) {
			break;
		}
	}
	std::cout << "The area of your shape is : " << area << std::endl <<
		"The perimeter of your shape is : " << perimiter << std::endl;
	return 0;
}