#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <cstdint>

double max(std::vector<float>& nums) {
	double max = 0;
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
double min(std::vector<float>& nums) {
	double min = 0;
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

double sum(std::vector<float>& nums) {
	if (nums.empty()) return 0.0f;
	double sum = 0;
	for (float n : nums) {
		sum += n;
	}
	return sum;
}

double mean(std::vector<float>& nums) {
	if (nums.empty()) return 0.0f;
	uint64_t length = nums.size();
	double total = sum(nums);
	
	return total / length;
}

double var(std::vector<float>& nums) {
	if (nums.empty()) return 0.0f;
	double num_mean = mean(nums);
	uint64_t length = nums.size();
	double result = 0;
	for (float n : nums) {
		result += std::pow((n - num_mean), 2); // population variance
	}
	return result/length;
}

double stdDev(std::vector<float>& nums) {
	if (nums.empty()) return 0.0f;
	double variance = var(nums);
	return std::sqrt(variance);
}

std::vector<float> sort(const std::vector<float>& nums) {
	std::vector<float> result = nums;
	// ill try to implement gnome sort by memory
	// essentially: encounter variable -> immediately move it to correct position
	std::size_t i = 1;
	while (i < result.size()) {
		if (i == 0 || result[i] >= result[i - 1]) {
			++i;                 // in order, move forward
		}
		else {
			std::swap(result[i], result[i - 1]);
			--i;                 // out of order, step back
		}
	}
	return result;
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
			continue;
		}
		if (elementCount <= 0) {
			std::cout << "The array cannot have 0 or negative amout of elements. Try again." << std::endl;
			continue;
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
		double maximum = max(arr);
		double minimum = min(arr);
		double num_mean = mean(arr);
		double variance = var(arr);
		double standard_deviation = stdDev(arr);
		std::vector<float> sorted_arr = sort(arr);

		std::cout << "The maximum value is: " << maximum << std::endl;
		std::cout << "The minimum value is: " << minimum << std::endl;
		std::cout << "The mean of the array is: " << num_mean << std::endl;
		std::cout << "The population variance of the array is: " << variance << std::endl;
		std::cout << "The population standard deviation is: " << standard_deviation << std::endl;

		std::cout << "-----------" << std::endl;
		std::cout << "The sorted array is: ";
		for (float n : sorted_arr) {
			std::cout << n << " ";
		}
		std::cout << std::endl;
		calculatorState = State::Exit;
	}

	return 1;
}