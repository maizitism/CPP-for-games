#include <iostream>
#include <vector>

int main() {
	std::vector<int> nums = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto not_odd = std::remove_if(nums.begin(), nums.end(),
		[](int x) {
			return x % 2 != 0;
		});
	nums.erase(not_odd, nums.end());

	for (int n : nums) {
		std::cout << n << " ";
	}
	std::cout << std::endl;
	return 0;
}