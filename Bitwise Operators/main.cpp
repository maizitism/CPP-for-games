#include <iostream>
#include <cstdint>
#include <bitset>


int main() {
	int8_t a = 0b01010101;
	int8_t b = 0b11111111;

	uint8_t mask = 0b111;

	std::cout << "a: " << std::bitset<8>(a) << std::endl;
	std::cout << "b: " << std::bitset<8>(b) << std::endl;

	std::cout << "NOT a: " << std::bitset<8>(~a) << std::endl;
	std::cout << "a AND b: " << std::bitset<8>(a & b) << std::endl;
	std::cout << "a AND NOT a: " << std::bitset<8>(a & ~a) << std::endl;
	std::cout << "a OR NOT a: " << std::bitset<8>(a | ~a) << std::endl;

	std::cout << "a XOR b: " << std::bitset<8>(a ^ b) << std::endl;

	std::cout << "a << 1: " << std::bitset<8>(a << 1) << std::endl;
	std::cout << "a << 8: " << std::bitset<8>(a << 8) << std::endl;
	std::cout << "a >> 6: " << std::bitset<8>(a >> 6) << std::endl;

	std::cout << "a & mask: " << std::bitset<8>(a & mask) << std::endl;

	return 0;
}