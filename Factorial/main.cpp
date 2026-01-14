#include <iostream>
#include <cstdint>
#include <limits>

enum class State {
	Working,
	Off
};

uint64_t factorial(uint64_t num) {
	if (num != 0) {
		return num * factorial(num - 1);
	}
	return 1;
}


int main() {
	double num = 0;
	State calculatorState = State::Working;

	while (calculatorState == State::Working) {
		std::cout << "Input a number! " << std::endl;
		std::cin >> num;
		if (std::cin.fail()) {
			std::cout << "Input value was not valid. Try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if(num < 0){
			std::cout << "The number has to be larger then 0." << std::endl;
			continue;
		}
		if (num > 20) {
			std::cout << "The factorial of this number will overflow the uint64_t type. "
				<< "Try again with a smaller number." << std::endl;
			continue;
		}
		uint64_t result = factorial(static_cast<uint64_t>(num));
		std::cout << "The evaluated factorial is: " << result << std::endl;

	}
	
}