#include <iostream>
#include <string>
#include <unordered_set>

// define enum for calculator state
enum class CalculatorState {
	On,
	Off
};

std::string askForCommand() {
	std::string command;
	std::unordered_set<std::string> allowedCommands = { "+", "-", "/", "*", "%", "^", "m", "q" };
	std::cout << "What operation do you want to perform? (+, -, /, *, %, ^, m, q)"
		<< std::endl;
	std::cin >> command;

	if (command.size() != 1) {
		std::cout << "To perform multiple operations, try the Multiple " <<
			"Operation mode, by inputting letter \"m\"." << std::endl;
		return "\0";
	}

	if (!allowedCommands.contains(command)) {
		std::cout << "Inputted character is not a permitted command. Try again." <<
			std::endl;
		return "\0";
	}

	return command;
}

int main() {
	auto state = CalculatorState::On; // turn on calculator
	while (state == CalculatorState::On) {
		// keep prompting user for input until sucessful
		std::string command = "\0";
		while (command == "\0") {
			command = askForCommand();
		}
		
	}


	return 0;
}