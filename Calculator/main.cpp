#include <iostream>


int main() {
	enum class CalculatorState {
		On,
		Off
	};

	//define enum for keeping track of the state of the calculator
	CalculatorState state = CalculatorState::On;

	char command = '\0';
	while (state == CalculatorState::On) {
		std::cout << "What operation do you want to perform? (+, -, /, *, q)"
			<< std::endl;
		std::cin >> command;
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