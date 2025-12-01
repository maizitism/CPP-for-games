#include <iostream>

void swapByPointer(int* a, int* b) {
	// were dereferencing the COPIES of the pointers given,
	// then changing their values around, to affect change in int main()

	int temp = *b;
	*b = *a;
	*a = temp;
}

void swapByReference(int& a, int& b) {
	// now in this case were getting access to the actual
	// variable in the main function

	int temp = b;
	b = a;
	a = temp;
}

int main() {
	int a = 3;
	int b = 5;
	
	std::cout << "The initial values of a and b are: " << a << ", " 
		<< b << std::endl;
	swapByPointer(&a, &b);
	std::cout << "After swapping a and b by pointer, the values are: " 
		<< a << ", " << b << std::endl;
	swapByReference(a, b);
	std::cout << "After swapping a and b by reference, the values are: "
		<< a << ", " << b << std::endl;

	return 0;
}