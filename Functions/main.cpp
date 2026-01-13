#include <iostream>

// returntype function_name(parameters)
int add(int a, int b) { // pass by value - function gets a copy of the variable
	return a + b;
}

int passByValue(int a) {
	a += 5;
	return a;
}
int passByReferece(int& a) { // passing an alias to the value, the memory address
	a += 5;
	return a;
}

int passByConstReference(const int& a) {
	// variable cannot be modified within function
	// a += 5; doesnt work
	return a;
}

int passByPointer(int* a) {
	//pointers are not always valid
	if (a) {
		*a += 5;
	}

	return *a;
}

int main() {
	int one = add(0, 1);
	int two = add(1, 1);

	int a = 0;
	passByValue(a); // original a passed to the func doesnt change
	a = passByValue(a);
	std::cout << "The value of a is: " << a << std::endl;
	passByReferece(a); // cannot take const variable (such as just 5)
	std::cout << "The value of a is: " << a << std::endl;

	int b = 0;
	passByPointer(&b);
	std::cout << "b: " << b << std::endl;

	return 0;
}