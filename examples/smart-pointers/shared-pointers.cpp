#include <iostream>
#include <memory>

int main() {
    auto num{std::make_shared<int>(42)};
    std::cout << num.use_count();
    {
        auto numTwo{num};
        std::cout << numTwo.use_count();
    }
    std::cout << num.use_count();
    return 0;
}
