#include <iostream>

class Base {
public:
	virtual ~Base() = default;
};

class Derived : public Base { // publically inherits from Base
public:
	~Derived() override = default;
};

class Derived2 : public Base {
public:
	~Derived2() override = default;
};

int main() {
	unsigned char c = 'A';
	int i = c;
	// this brings no problems, as its a widening cast 8b -> 32b

	c = static_cast<unsigned char>(i);
	// this is now a narrowing conversion

	unsigned int ui = 3;
	i = static_cast<int>(ui); // signed has 31 bits of precision, unsigned has 32. narrowing conversion.

	ui = static_cast<unsigned int>(i); // were losing the sign of i variable

	float f = 3.14f;
	double d = f; // implicit conversion
	f = static_cast<float>(d); // narrowing conversion, requires explicit cast

	f = static_cast<float>(i); // narrowing conversion. 31 bits into 23 bits of fraction + exponent
	d = i; // double can store full precision of normal int

	i = static_cast<int>(f); //loss of decimal point

	// rule of thumb:
	// signed -> unsigned require explicit cast
	// widening -> narrowing require explicit cast
	// widening does not require an explicit cast

	// c style casts
	f = (float)i;
	i = (int)f;
	// less explicit then c++ style casts and much harder to find in code
	// although they allow you to do any cast to any type

	const float cf = 3.14f; // the value of the variable cannot be changed in lifetime of developers
	// we can cast away the const-ness
	float* pf = const_cast<float*>(&cf);
	*pf = 6.28f;

	// dynamic cast
	// allows you to cast from base typed to derived types

	Base* b = new Derived(); // create base pointer from derived class

	// at some point we want to convert the base pointer to the derived type
	Derived* der = dynamic_cast<Derived*>(b);
	// if we try to dynamic cast to an invalid type, d2 will be NULL
	Derived2* der2 = dynamic_cast<Derived2*>(b);

	if (der != nullptr) {
		std::cout << "b is Derived" << std::endl;
	}
	if (der2 == nullptr) {
		std::cout << "b is not Derived2" << std::endl;
	}

	return 0;
}