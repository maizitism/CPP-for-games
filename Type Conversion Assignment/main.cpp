#include <iostream>

int main() {
	double d = 42.99;
	std::cout << "Initial starting double value: " << d << std::endl;
	float f = static_cast<float>(d);
	std::cout << "Double explicitly casted to float gives: " << f << std::endl;
	int i = static_cast<int>(f);
	std::cout << "Float explicitly casted to int gives: " << i << std::endl;
	char c = static_cast<char>(i);
	std::cout << "Int explicitly casted to char gives: " << c << std::endl;
	bool b = static_cast<bool>(c);
	std::cout << "Char explicitly casted to bool gives: " << b << std::endl;
	return 0;
}