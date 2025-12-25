#include <iostream>
#include <string>
#include <unordered_set>
#include <cmath>

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

std::string obtainExpression() {
	std::string input = "\0";
	//read in expression as standard string
	std::cout << "Input the expression! Make sure it has no errors!" << std::endl;
	std::cin >> input;
	return input;
}

int precedence(char op) {
	switch (op) {
	case '+': case '-':
		return 1;
	case '*': case '/': case '%':
		return 2;
	case '(':
		return 0;
	case ')':
		return 3;
	default:
		return -1;
	}
}

char* convertExpressionToRPN(const char* exp) {
	int size = sizeof(exp) / sizeof(exp[0]);
	char* holdingStack = new char[size+1]();
	char* output = new char[size+1]();
	int hSidx = 0;
	int oidx = 0;

	for (size_t i = 0; exp[i] != '\0'; ++i) {
		// determine precendence
		int pr = precedence(i);
		// integer literal, append to output queue
		if (pr == -1) {
			output[oidx] = i;
			oidx++;
		}
		//open parenthesis, append to holding stack no matter what
		if (pr == 0) {
			holdingStack[hSidx] = i;
			hSidx++;
		}
		// closed parenthesis, drain holding stack until open bracket
		if (pr == 3) {
			while (precedence(holdingStack[hSidx]) != 0) {
				output[oidx] = holdingStack[hSidx];
				holdingStack[hSidx] = '\0';
				oidx++;
				hSidx--;
			}
			//remove open bracket
			hSidx--;
		}
		// if other symbol, perform RPN procedure
		else{
			while (hSidx > 0 || (precedence(holdingStack[hSidx]) > pr) ) {
				output[oidx] = holdingStack[hSidx];
				holdingStack[hSidx] = '\0';
				oidx++;
				hSidx--;
			}
			holdingStack[hSidx] = i;
		}
	}
	// drain the holding stack
	while (hSidx >= 0) {
		output[oidx] = holdingStack[hSidx];
		holdingStack[hSidx] = '\0';
		oidx++;
		hSidx--;

	}

	delete[] holdingStack;
	delete[] output;
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
			std::string expression = obtainExpression();
			const char* splitExpression = expression.c_str();
			// convert expression to reverse polish notation
			char* RPN = convertExpressionToRPN(splitExpression);
			//convertExpressionToRPN
			//shuntingYard
			//printResult
		}
		
	}


	return 0;
}