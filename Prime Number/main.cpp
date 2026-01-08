#include <iostream>
#include <cmath>
#include <vector>

enum class State {
	On,
	Off
};

bool checkInputValidity() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
	return true;
}

bool primeCheck(int n) {
	if (n <= 1) {return false;}
	if (n <= 3) { return true; } 
	if (n % 2 == 0) { return false; }
	for (int i = 3; i*i < n; i+=2) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

std::vector<int> primeCheckInRange(int l, int u) {
	std::vector<int> primes;
	if (u < 2) { return primes; }
	if (l < 2) { l = 2; }

	if (l <= 2 && 2 <= u) {
		primes.push_back(2);
	}
	int start;
	if (l % 2 == 0) {
		start = l + 1;
	}
	else {
		start = l;
	}
	for (int n = start; n <= u; n += 2) {
		if (primeCheck(n)) { primes.push_back(n); }
	}

	return primes;

}

int main() {
	State CalculatorState = State::On;
	int command = 0;
	while (CalculatorState == State::On) {
		std::cout << "What would you like to do?" << std::endl
			<< "1. Check if a number is prime" << std::endl
			<< "2. Print all prime numbers in a range" << std::endl
			<< "3. Quit" << std::endl;
		std::cin >> command;
		if (!checkInputValidity()) {
			std::cout << "Input command was not valid. Try again." << std::endl;
			continue;
		}
		int val1 = 0;
		int val2 = 0;
		std::vector<int> primes;
		switch (command) {
		case 1:
			// check is number is prime
			std::cout << "Input a number!" << std::endl;
			std::cin >> val1;
			if (!checkInputValidity()) {
				std::cout << "Input number was not valid. Try again." << std::endl;
				break;
			}
			if (primeCheck(val1)) {
				std::cout << val1 << " is prime." << std::endl;
			}
			else {
				std::cout << val1 << " is not prime." << std::endl;
			}

			break;
		case 2:
			std::cout << "Input a lower bound!" << std::endl;
			std::cin >> val1;
			if (!checkInputValidity()) {
				std::cout << "Input lower bound was not valid. Try again." << std::endl;
				break;
			}
			std::cout << "Input a upper bound (inclusive)!" << std::endl;
			std::cin >> val2;
			if (!checkInputValidity()) {
				std::cout << "Input upper bound was not valid. Try again." << std::endl;
				break;
			}
			if (val1 >= val2) {
				std::cout << "Lower bound must be smaller then upper bound." << std::endl;
			}
			else if (val2 < val1){
				std::cout << "Upper bound must be bigger then lower bound." << std::endl;
			}
			primes = primeCheckInRange(val1, val2);
			if (primes.empty()) {
				std::cout << "No primes were found in the range." << std::endl;
			}
			else {
				std::cout << "Primes found in range:" << std::endl;
				for (int prime : primes) {
					std::cout << prime << " ";
				}
				std::cout << std::endl;
			}
			break;
		case 3:
			std::cout << "Goodbye!" << std::endl;
			CalculatorState = State::Off;
			break;
		}
	}
	return 0;
}