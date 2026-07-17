#include <iostream>
#include <memory>

int main() {
    auto myNumber{std::make_shared<int>(10)};
    *myNumber = 50;

    std::cout << *myNumber;
}
