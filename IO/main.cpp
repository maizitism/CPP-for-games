#include <iostream>
#include <string>

int main() {
	std::string name;
	int age;

	std::cout << "What is your name?: ";
	std::cin >> name;

	std::cout << "\nWhat is your age?: ";
	std::cin >> age;
	

	std::cout << "Hello, " << name << ". ";
	std::cout << "You are " << age << " years old!" << std::endl;

	return 0;
}