#include <iostream>
#include <string>



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
		switch (command) {

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