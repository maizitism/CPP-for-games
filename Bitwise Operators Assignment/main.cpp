#include <iostream>
#include <limits>
#include <cstdint>
#include <bitset>

bool checkInputValidity() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
	return true;
}

int main() {
	uint8_t number = 0;
	uint8_t bit = 0;
	int temp = 0;

	bool numberSet = false;
	bool bitChosen = false;
	while(!numberSet || !bitChosen){
		numberSet = false;
		bitChosen = false;

		std::cout << "Input a number between 0 and 255!" << std::endl;
		std::cin >> temp;
		// if number cannot be read into input, std::cin.fail() will be set
		if (!checkInputValidity()) {
			std::cout << "Something other then a number was input. Try again."
				<< std::endl;
			continue;
		}
		if (temp < 0 || temp > 255) {
			std::cout << "Number was too small or too large. Try again."
				<< std::endl;
			continue;
		}
		numberSet = true;
		number = static_cast<uint8_t>(temp);

		std::cout << "Enter a bit position! (0-7)" << std::endl;
		std::cin >> temp;
		if (temp > 7) {
			std::cout << "Chosen bit does not exist in the 8 bit number."
				<< std::endl;
			continue;
		}
		bitChosen = true;
		bit = static_cast<uint8_t>(temp);
		//display number in binary
		std::cout << "Inputted number in binary: " << std::bitset<8>(number) << std::endl;
		//display the number of bits in that number
		if (number == 0) {
			std::cout << "Number has 0 bits.";
		}
		else {
			int i = 1;
			while ((number >> i) != 0) {
				i++;
			}
			std::cout << "Number has " << i << " bits." << std::endl;
		}
		//output T/F depending on the users selected bit
		bool isBitSet = (number >> bit) & 1; // bitshift by bits and mask it
		if (isBitSet) {
			std::cout << "The " << static_cast<int>(bit) << "th bit of the number is set to true." << std::endl;
		}
		else {
			std::cout << "The " << static_cast<int>(bit) << "th bit of the number is set to false." << std::endl;
		}
		//set the nth bit and display the value in binary and decimal
		uint8_t number_cpy = number;
		number_cpy |= (1 << bit);
		std::cout << "The " << static_cast<int>(bit) << "th bit has been set." << std::endl <<
			"   The new value in Binary is " << std::bitset<8>(number_cpy) << std::endl <<
			"   The new value in Decimal is " << static_cast<int>(number_cpy) << std::endl;
		//clear the nth bit and display the value in binary and decimal
		number_cpy = number;
		number_cpy &= ~(1 << bit);
		std::cout << "The " << static_cast<int>(bit) << "th bit has been cleared." << std::endl <<
			"   The new value in Binary is " << std::bitset<8>(number_cpy) << std::endl <<
			"   The new value in Decimal is " << static_cast<int>(number_cpy) << std::endl;
		//invert the nth bit and display the value in binary and decimal
		number_cpy = number;
		number_cpy ^= (1 << bit);
		std::cout << "The " << static_cast<int>(bit) << "th bit has been toggled." << std::endl <<
			"   The new value in Binary is " << std::bitset<8>(number_cpy) << std::endl <<
			"   The new value in Decimal is " << static_cast<int>(number_cpy) << std::endl;
		//left and right shift the value by n bits and display the result in binary and decimal
		number_cpy = number;
		number_cpy = number_cpy << bit;
		std::cout << "The number has been bit shifted by " << static_cast<int>(bit)<< " bits to the left." << std::endl <<
			"   The new value in Binary is " << std::bitset<8>(number_cpy) << std::endl <<
			"   The new value in Decimal is " << static_cast<int>(number_cpy) << std::endl;
		number_cpy = number;
		number_cpy = number_cpy >> bit;
		std::cout << "The number has been bit shifted by " << static_cast<int>(bit) << " bits to the right." << std::endl <<
			"   The new value in Binary is " << std::bitset<8>(number_cpy) << std::endl <<
			"   The new value in Decimal is " << static_cast<int>(number_cpy) << std::endl;


	}


	return 0;
}