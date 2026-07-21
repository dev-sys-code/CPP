#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers{2, 3, 1, 4};

    numbers.push_back(5);                   // push_back(val) -> Adds 5 to the end
    numbers.pop_back();                     // pop_back() -> Deletes last element, 5 in this case
    numbers.insert(numbers.begin() + 4, 5); // insert(pos, val) -> Drops 5 at index 4
    numbers.erase(numbers.begin() + 5);     // erase(pos, val) -> Erase the 5th element

    for (int i : numbers) {
        std::cout << i << " ";
    }
}
