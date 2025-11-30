#include <iostream>
#include <vector>

int main() {
	// auto allows compiler to automatically deduce the type of the variable

	auto i = 0; // deduced type int
	auto ui = 0u; // deduced: unsigned int
	auto ull = 0ull; // unsigned long long

	auto d = 3.14; // double
	auto f = 3.14f; // single precision float

	auto c = 'A'; // character
	auto u8 = u8'A'; // unsigned char8
	auto u16 = u'A'; // 16 bit char
	auto u32 = U'A'; // 32 bit char

	auto code = 'CODE'; // deduced as signed integer, combined all values in hex

	std::vector<int> v = { 1, 2, 3, 4 };
	// to iterate over this, we may use an interator.
	// without the auto keyword, it must be defined as

	std::vector<int>::iterator iter = v.begin(); // this is quite verbose
	// can also be iterated in a for loop
	for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		std::cout << *iter << std::endl;
	}
	// ^^ this is not very nice to look at
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		std::cout << *iter << std::endl;
	}
	// ^^ this looks way nicer

	return 0;
}