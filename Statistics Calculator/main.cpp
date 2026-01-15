#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

float max(std::vector<float>& nums) {
	float max = 0;
	int idx = 0;
	if (nums.empty()) return 0.0f;
	for (float n : nums) {
		if (idx == 0) {
			max = n;
			continue;
		}
		if (n > max) {
			max = n;
		}
		idx++;
	}
	return max;
}
float min(std::vector<float>& nums) {
	float min = 0;
	int idx = 0;
	if (nums.empty()) return 0.0f;
	for (float n : nums) {
		if (idx == 0) {
			min = n;
			continue;
		}
		if (n < min) {
			min = n;
		}
		idx++;
	}
	return min;
}

float sum(std::vector<float>& nums) {
	if (nums.empty()) return 0.0f;
	float sum = 0;
	for (float n : nums) {
		sum += n;
	}
	return sum;
}

float mean(std::vector<float>& nums) {
	if (nums.empty()) return 0.0f;
	int length = nums.size();
	float total = sum(nums);
	
	return total / length;
}

float var(std::vector<float>& nums) {
	if (nums.empty()) return 0.0f;
	float num_mean = mean(nums);
	float length = nums.size();
	float result = 0;
	for (float n : nums) {
		result += std::pow((n - num_mean), 2); // population variance
	}
	return result/length;
}

float stdDev(std::vector<float>& nums) {
	if (nums.empty()) return 0.0f;
	float variance = var(nums);
	return std::sqrt(variance);
}

int checkInput() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 1;
	}
	return 0;
}

enum class State {
	InputNumbers,
	Compute,
	Exit
};
int main() {

	State calculatorState = State::InputNumbers;

	int elementCount = 0;
	std::vector<float> arr; // physically, the user will not be entering anything close to needing pre-allocation
	while (calculatorState == State::InputNumbers) {
		std::cout << "How many elements does your array contain?" << std::endl;
		std::cin >> elementCount;
		if (checkInput()) {
			std::cout << "Input value is not a number. Try again." << std::endl;
		}

		float currentNumber = 0.0f;
		for (int i = 1; i <= elementCount; i++) {
			std::cout << "Input number " << i << " : " << std::endl;
			std::cin >> currentNumber;
			if (checkInput()) {
				std::cout << "Input value is not a number. Try again." << std::endl;
				i--; // go back a number so on the next increment were at the same position
				continue;
			}
			arr.push_back(currentNumber);
		}
		// all elements now added, we now switch into statistics mode
		calculatorState = State::Compute;
	}
	while (calculatorState == State::Compute) {
		
	}

	return 1;
}