#include <iostream>
#include <string>
#include <unordered_set> // remove either when rewriting askForCommand()
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <vector>

// define enum for calculator state
enum class CalculatorState {
	On,
	Off
};
// define all possible token types
enum class TokenType {
	Number,
	Operator,
	LeftParen,
	RightParen
};
// define enum for later tokenisation for Shunting-Yard
enum class Associativity {
	Left,
	Right
};
// define structure for token
struct Token {
	TokenType type;
	int precedence;
	Associativity associativity;
	std::string text;
};
// define all allowed operators
struct OperatorInfo {
	int precedence;
	Associativity associativity;
};
static const std::unordered_map<std::string, OperatorInfo> operators = {
	{"+", {1, Associativity::Left}},
	{"-", {1, Associativity::Left}},
	{"*", {2, Associativity::Left}},
	{"/", {2, Associativity::Left}},
	{"%", {2, Associativity::Left}},
	{"^", {3, Associativity::Right}}
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

void obtainNumbers(double& num1, double& num2, bool& signal) {
	double temp1 = 0;
	double temp2 = 0;
	std::cout << "Enter the first number!" << std::endl;
	std::cin >> temp1;
	std::cout << "Enter the second number!" << std::endl;
	std::cin >> temp2;

	if (std::cin.fail()) {
		std::cout << "One of the numbers was not valid. Try again."
			<< std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		signal = false;
		return;
	}
	num1 = temp1;
	num2 = temp2;
	signal = true;
}

double simpleEvaluate(double& lhs, double& rhs, std::string command) {
	//"+", "-", "/", "*", "%", "^",
	char op = command[0];
	switch (op) {
	case '+':
		return lhs + rhs;
	case '-':
		return lhs - rhs;
	case '/':
		return lhs / rhs;
	case '*':
		return lhs * rhs;
	case '%':
		return std::fmod(lhs, rhs);
	case '^':
		return std::pow(lhs, rhs);
	default:
		std::cout << "Something went massively wrong." << std::endl;
		return 0;
	}
}

bool isInteger(const std::string& s) {
	// string is empty
	if (s.empty()) {
		return false;
	}
	size_t i = 0;
	// check if string is only sign
	if (s[0] == '-' || s[0] == '+') {
		if (s.size() == 1) {
			return false;
		}
		i = 1;
	}
	// check if string is not number
	for (; i < s.size(); i++) {
		if (!std::isdigit(static_cast<unsigned char>(s[i]))){
			return false;
		}
	}
	return true;
}

std::vector<Token> obtainExpression() {

	std::cout << "Input the expression!" << std::endl <<
		"Seperate each element of the equation with a space!" << std::endl;

}


void printResult(double result) {
	std::cout << "The result is " << result << ". " << std::endl;
}

int main() {
	auto state = CalculatorState::On; // turn on calculator
	bool numberState = false;
	double num1 = 0;
	double num2 = 0;

	while (state == CalculatorState::On) {
		// reset numbers if multiple operations performed in one calc session
		num1 = 0;
		num2 = 0;
		numberState = false;

		// keep prompting user for input until sucessful
		std::string command = "\0";
		while (command == "\0") {
			command = askForCommand();
		}

		// check if quit command issued
		if (command == "q") {
			std::cout << "Goodbye!" << std::endl;
			state = CalculatorState::Off;
			continue;
		}
		
		//choose apropriate evaluation method for seleceted command
		if (command != "m") {
			// keep prompting for numbers from user
			while (numberState == false) {
				obtainNumbers(num1, num2, numberState);
			}
			
			double result = simpleEvaluate(num1, num2, command);
			printResult(result);
		} else {
			//obtain expression from user
			//std::string exp = obtainExpression();
			// tokenise input
			

			// process it according to the shunting yard algorithm

		}
		
	}


	return 0;
}