#include <iostream>

int main() {

	int size = 0;
	std::cout << "What size array do you want to allocate?" << std::endl;
	std::cin >> size;
	
	while (std::cin.fail()) {
		std::cout << "Input number is not an integer.\nTry again." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> size;
	}


	return 0;
}