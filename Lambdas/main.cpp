#include <iostream>


int main() {
	auto f = [](int a, int b) -> int { return a + b; };
	// [] - lambda initialiser
	// [=] captures the enviroment by value
	int c = f(5, 10);
	
	int a = 5;
	int b = 10;
	// doesnt take any variables because a and b are captured from the enviroment [=]
	// can also capture variables by reference [&] - beware of potential problems with scoping
	// captured variables can also be named by name [a , b]
	// named variables can also be captured by reference [&a, &b]
	// [=, &a, &b] captures everything by value, but a and b are captured by reference
	auto g = [=] {return a + b; };
	
	a = 10;
	b = 15;
	
	int d = g();
	std::cout << "g(): " << d << std::endl;

	// generic lambdas
	auto h = [](auto a, auto b) { return a + b; };

	auto i = h(5, 10);
	auto j = h(5.0f, 10.0f);

	
}