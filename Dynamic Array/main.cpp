#include <iostream>

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
			continue;
		}
		if (size <= 0 && size > 10) {
			state = AllocatorState::SizeFail;
			std::cout << "Allocated size must be greater then 0 and"
				<< " smaller then or equal to 10. Try again." << std::endl;
			continue;
		}
		// if user passes through both if statements then were good to
		// allocate some memory
		state = AllocatorState::Good;
	}
	

	return 0;
}