#include <iostream>
#include <compare>

int main() {
	{
		int a = 5;
		int b = 4;
		int c = a + b;
		c = a - b;
		c = a * b;
		c = a / b; // wont give 1.25, integers have no decimal
	}

	{
		int a = 5;
		int b = -a; // -5
		b = +a; // 5

		uint8_t c = 5;
		auto d = +c; // promoted to INT instead of char

		auto e = c + 1; // adding 32-bit int to 8-bit int = typeof(e) -> 32-bit
	}


	{
		for (int i = 0; i <= 20; ++i) {
			std::cout << i << " % 10 = " << (i % 10) << std::endl;
		}
	}

	{
		int a = 5;
		int b = ++a; // first increment, then return value
		int c = a++; // return value, and then increment (the a variable)
	
	}

	{
		bool a = true;
		bool b = false;

		bool c = a || b; // if either are true, c will be true
		bool d = a && b; // d is true only if a and b are true

		bool e = !a; // if a is true, e is false

	}


	{
		int a = 5;
		int b = 4;
		
		if (a < b) {
			std::cout << "a is less then b" << std::endl;
		}
		if (a > b) {
			std::cout << "a is greater then b" << std::endl;
		}
		if (a == b) {
			std::cout << "a is equal to b" << std::endl;
		}
	
	}

	{
		// cpp20 also has the three way operator (spaceship operator)
		int a = 5;
		int b = 4;

		auto c = a <=> b; // this indicates the ordering of the values

		if (c < 0) {
			std::cout << "a is less then b" << std::endl;
		}
		if (c > 0) {
			std::cout << "a is greater then b" << std::endl;
		}
		if (c == 0) {
			std::cout << "a is equal to b" << std::endl;
		}
	}

	return 0;
}