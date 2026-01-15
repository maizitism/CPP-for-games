#include <iostream>
#include <functional>

using add_func = std::function<int(int, int)>;


int callFunc(add_func f, int a, int b) {
	// with auto f, we dont quite know the type of f
	// this way, it isnt explicit what type the function is
	// we can either use a function pointer, making the func. signature
	// callFunc(int(*f)(int, int))
	// but this looks a little messy so we can typedef it and then add it 
	// into the list of arguments.

	return f(a, b);
}


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
	//lambdas can also have explicit template parameters
	//auto h = []<typename T> (T a, T b) { return a + b; };
	// allows for forcing of types, where with auto they would not be guaranteed


	auto i = h(5, 10);
	auto j = h(5.0f, 10.0f);

	
}