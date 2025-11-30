#include <iostream>
#include <tuple>
#include <limits>

std::tuple<int, int, bool> obtainAndCheckInputValues() {
	int num1 = 0;
	int num2 = 0;
	std::cout << "Enter the first number!" << std::endl;
	std::cin >> num1;
	std::cout << "Enter the second number!" << std::endl;
	std::cin >> num2;
	
	if (std::cin.fail()) {
		std::cout << "One of the numbers was not valid. Try again."
			<< std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return {0, 0, false}
	}

	return {num1, num2, true}
}

int main() {
	enum class CalculatorState {
		On,
		Off
	};

	//define enum for keeping track of the state of the calculator
	CalculatorState state = CalculatorState::On;

	char command = '\0';
	std::string userInput;

	while (state == CalculatorState::On) {
		std::cout << "What operation do you want to perform? (+, -, /, *, q)"
			<< std::endl;
		std::cin >> userInput;
		// check if user input is exactly one character
		if (userInput.size() != 1) {
			std::cout << "You cannot perform multiple operations at once. " <<
				"Try again." << std::endl;
			continue;
		}
		command = userInput[0];

		int num1 = 0;
		int num2 = 0;
		switch (command) {
		case '+':
			break;

		case 'q':
			std::cout << "Goodbye!" << std::endl;
			state = CalculatorState::Off;
			break;
		default:
			std::cout << "Command was not detected as valid. Try again."
				<< std::endl;
			break;
		}

	}
	return 0;
}