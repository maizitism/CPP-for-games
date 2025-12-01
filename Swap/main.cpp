#include <iostream>

void swap(int* a, int* b) {
	// swap the value of a and b around
	// so a == initial_b and b == initial_a
	int* temp = b;
	b = a;
	a = temp;
}

int main() {
	int a = 3;
	int b = 5;
	
	std::cout << "The initial values of a and b are: " << a << ", " 
		<< b << std::endl;
	swap(&a, &b);
	std::cout << "After swapping a and b by pointer, the values are" 
		<< a << ", " << b << std::endl;
	// call swap function
	// print values to console
	// note: since values are passed by reference it makes sense for the swap
	// function to not return anything, as its directly working with memory
}