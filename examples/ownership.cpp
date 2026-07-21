#include <iostream>
#include <memory>

void transferOwnership(std::unique_ptr<int> num);

int main() {
    std::unique_ptr<int> num = std::make_unique<int>(42);
    transferOwnership(std::move(num));
    std::cout << "Num: " << (num == nullptr ? "Null" : "Not null");

    return 0;
}

void transferOwnership(std::unique_ptr<int> num) {
    std::cout << "Ownership transferred: " << *num << "\n";
}
