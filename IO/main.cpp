#include <iostream>
#include <string>
#include <limits>

int main() {
	std::string name;
	int age;

	std::cout << "What is your name?: " << std::endl;
	std::cin >> name;

	std::cout << "What is your age?: " << std::endl;
	std::cin >> age;
	
	// if user doesnt input number for age, failstate will be set for cin.
	while (std::cin.fail()) {
		std::cout << "Error! An number was expected when prompted for your age.\nInput your age again." << std::endl;
		std::cin.clear(); // clear the error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore all characters in current input stream until the newline character
		std::cin >> age; // prompt user for age again
	}

	std::cout << "Hello, " << name << ". ";
	std::cout << "You are " << age << " years old!" << std::endl;

	std::cout << "Press enter to exit." << std::endl;
	// when enabling "Automatically Close Console When Debugging Stops", there might still be a couple characters
	// in the input stream, which will get consumed by std::cin.get().
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();

	return 0;
}