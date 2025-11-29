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

	if (age > 0 && age < 25) {
		std::cout << "Hello " << name << ",you are only " << age << "years old.";
	}
	else if (age >= 25 && age < 50) {
		std::cout << "Hello " << name << ",you are already " << age << "years old.";
	}
	else if (age >= 50) {
		std::cout << "Hello " << name << ". You are very wise for your age.";
	}
	else {
		std::cout << "Hello " << name << ". You have not been born yet.";
	}

	return 0;
}