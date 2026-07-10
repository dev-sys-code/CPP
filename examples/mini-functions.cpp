#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

void sortNumbers(vector<int>& nums, const size_t size);
void findNumber(vector<int>& nums);
void countNumbers(vector<int>& nums);

int main()
{   
    vector<int> nums{3, 2, 5, 1, 4};
    size_t size{nums.size()};
    sortNumbers(nums, size);
    findNumber(nums);
    countNumbers(nums);
    return 0;
}

void sortNumbers(vector<int>& nums, const size_t size){
    std::sort(nums.begin(), nums.end());
    std::cout << "Sorted list: ";
    for (int i : nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void findNumber(vector<int>& nums) {
    int number{};
    std::cout << "Enter number: \n> ";
    std::cin >> number;

    auto it{std::find(nums.begin(), nums.end(), number)};

    if (it != nums.end()) {
        std::cout << number << " found.";
    } else {
        std::cout << number << " not found.";
    }

    std::cout << std::endl;
}

void countNumbers(vector<int>& nums) {
    int number{};

    std::cout << "Enter number: \n> ";
    std::cin >> number;
    int amount{std::count(nums.begin(), nums.end(), number)};

    std::cout << "Number appeared: " << amount << " time(s)" << std::endl;
}
