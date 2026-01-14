#include <iostream>

template<typename T, typename U>
decltype(auto) max(const T& a, const U& b) {
	//decltype will deduce to a reference if both the T and U values are references and both of the same type
	// if theyre different types, it will be a return by value
	return a > b ? a : b;
}

int main() {
	
	// compiler will generate an int max function
	{
		int a = 5;
		int b = 10;

		int c = max(a, b);
	}
	// the compiler is not able to deduce the type of the argument because a and b are different types
	// also it cannot figure out what return type we want
	{
		int a = 5;
		double b = 10.0;

		auto c = max(a, b);
	}

	return 0;
}