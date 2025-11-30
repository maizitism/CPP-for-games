#include <iostream>

int main() {

	int i = 3;
	// any time you want to use a string literal in your code it should be
	// a const char
	const char* name = "Marks"; // this pointer refers to the first letter of
								// the name

	// to create a pointer
	// its a type name with a star, to get address of variable in memory, use &
	int* pi = &i;
	// were not storing the number, rather the address in memory where its
	// located.

	// lets say we want to output the contents of the pointer
	std::cout << "Address of i: " << pi << std::endl;
	std::cout << "Value of i: " << *pi << std::endl;

	*pi = 4;
	std::cout << "Value of i after modification: " << *pi << std::endl;

	if (*pi == i) {
		std::cout << "Values of i and the reference of i match in value."
				<< std::endl;
	}

	std::cout << "The first letter of " << name << " is " << name[0] << std::endl;
	// or we can dereference the first value by doing
	std::cout << "The first letter of " << name << " is " << *name << std::endl;

	//one can also declar a constant pointer to a constant value
	const char* const lastName = "Maizitis";
	// we now cant change what it points to nor the pointed to data

	// we can also perform pointer arithmetic
	const int values[] = { 1, 2, 3, 4 };
	// we can index the elements by
	std::cout << *(values + 1) << std::endl;

	// pointers are used for dynamic memory allocation
	int* arr = new int[100];
	// individual elements can be accessed by
	arr[0] = 0;
	arr[99] = 99;
	// or by using dereferecing
	*(arr + 0) = 0;
	*(arr + 99) = 99;
	// both operations are functionally the same
	delete[] arr;

	// to declare a reference
	int& ri = i; // an alias of the original variable
	ri = 5;
	std::cout << "The value of i, modified from ri is: " << i << std::endl;
	// what a reference points to cannot be changed after the fact

	return 0;
}