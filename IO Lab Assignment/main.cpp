#include <iostream>
#include <string>
#include <limits>


int main() {
	std::string name;
	int age;

	std::cout << "What is your name?" << std::endl;
	std::cin >> name;

	std::cout << "What is your age?" << std::endl;
	std::cin >> age;

	// if user doesnt input number for age, failstate will be set for cin.
	while (std::cin.fail()) {
		std::cout << "Error! An number was expected when prompted for your age.\nInput your age again." << std::endl;
		std::cin.clear(); // clear the error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore all characters in current input stream until the newline character
		std::cin >> age; // prompt user for age again
	}

	if (age > 0 && age < 25) {
		std::cout << "Hello " << name << ", you are only " << age << " years old." << std::endl;
	}
	else if (age >= 25 && age < 50) {
		std::cout << "Hello " << name << ", you are already " << age << " years old." << std::endl;
	}
	else if (age >= 50) {
		std::cout << "Hello " << name << ". You are very wise for your age." << std::endl;
	}
	else {
		std::cout << "Hello " << name << ". You have not been born yet." << std::endl;
	}

	std::cout << "Press enter to exit." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	return 0;
}