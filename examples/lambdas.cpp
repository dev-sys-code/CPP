#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    using std::vector;
    using std::sort;

    vector<int> nums{5, 2, 8, 1};
    sort(nums.begin(), nums.end(), [](int a, int b)
    {
        return a > b;
    });

    for (int i : nums) std::cout << i << " ";
    return 0;
}
