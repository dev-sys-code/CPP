#include <iostream>
#include <memory>

auto takeOwnerReturn(std::unique_ptr<int> ptr) {
    *ptr = 42;
    std::cout << "In function: " << *ptr << "\n";
    return ptr;
}

int main() {
    auto p{std::make_unique<int>(100)};
    std::cout << "Before function: " << *p << "\n";
    p = takeOwnerReturn(std::move(p));
    std::cout << "After function: " << *p << "\n";
    return 0;
}
