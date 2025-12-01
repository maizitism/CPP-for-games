#include <iostream>
#include <limits>

float computeMaximum(int* arr, int size) {
	float max = arr[0];
	for (int i = 0; i <= size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

float computeMinimum(int* arr, int size) {
	float min = arr[0];
	for (int i = 0; i <= size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

float computeAverage(int* arr, int size) {
	float sum = 0;
	for (int i = 0; i <= size; i++) {
		sum += arr[i];
	}
	return sum/size;
}

int main() {
	enum class AllocatorState {
		Good,
		CinFail,
		SizeFail,
		Bad
	};

	int size = 0;
	AllocatorState state = AllocatorState::Bad;
	std::cout << "What size array do you want to allocate?" << std::endl;
	
	while (state != AllocatorState::Good) {
		std::cin >> size;
		if (std::cin.fail()) {
			state = AllocatorState::CinFail;
			std::cout << "Input number is not an integer.\nTry again."
				<< std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (size <= 0 || size > 10) {
			state = AllocatorState::SizeFail;
			std::cout << "Allocated size must be greater then 0 and"
				<< " smaller then or equal to 10. Try again." << std::endl;
			continue;
		}
		// if user passes through both if statements then were good to
		// allocate some memory
		state = AllocatorState::Good;
	}
	
	int* arr = new int[size] {};
	// now, user has to fill the allocated int array with some numbers
	int input = 0;
	for (int i = 0; i < size; i++) {
		std::cout << "Enter the " << i+1 << "th value of the array!" << std::endl;
		std::cin >> input;
		// check if inputted number is valid
		while (std::cin.fail()) {
			std::cout << "Inputted number is not valid. Try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> input;
		}
		arr[i] = input;
	}

	float max = computeMaximum(arr, size);
	float min = computeMinimum(arr, size);
	float avg = computeMinimum(arr, size);

	std::cout << "The maximum value of the array is: " << max << std::endl <<
		"The minimum value of the array is: " << min << std::endl <<
		"The average of the values in the array is: " << avg << std::endl;

	//after were finished, array must be freed :smile:
	delete[] arr;

	// reflecting back on what i have wrote, this couldve been written way
	// better with less copy paste, but eh what are you going to do
	return 0;
}