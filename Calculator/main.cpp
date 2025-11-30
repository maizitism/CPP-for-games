#include <iostream>
#include <tuple>
#include <limits>

std::tuple<double, double, bool> obtainAndCheckInputValues() {
	double num1 = 0;
	double num2 = 0;
	std::cout << "Enter the first number!" << std::endl;
	std::cin >> num1;
	std::cout << "Enter the second number!" << std::endl;
	std::cin >> num2;
	
	if (std::cin.fail()) {
		std::cout << "One of the numbers was not valid. Try again."
			<< std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return { 0, 0, false };
	}

	return {num1, num2 , true};
}

double evaluate(double rhs, double lhs, char command) {
	switch (command) {
	case '+':
		return rhs + lhs;
	case '-':
		return rhs - lhs;
	case '/':
		if (lhs == 0) {
			return NULL;
		}
		return rhs / lhs;
	case '*':
		return rhs * lhs;
	}
	return NULL;
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
		// check if quit command issued
		if (command == 'q') {
			std::cout << "Goodbye!" << std::endl;
			state = CalculatorState::Off;
			continue;
		}

		auto [num1, num2, ok] = obtainAndCheckInputValues();
		if (!ok) {
			continue;
		}

		double result = evaluate(num1, num2, command);
		if (result == NULL) {
			std::cout << "The result could not be evaluated." << std::endl;
			continue;
		}
		
		std::cout << "The result is " << result << "." << std::endl;

	}
	return 0;
}