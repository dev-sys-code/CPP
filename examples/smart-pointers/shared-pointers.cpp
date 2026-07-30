#include <iostream>
#include <memory>

int main() {
    auto num{std::make_shared<int>(42)};
    std::cout << "Number before scope: " <<  num.use_count() << "\n";
    {
        auto numTwo{num};
        std::cout << "Number in scope: " << numTwo.use_count() << "\n";
    }
    std::cout << "Number after scope: " << num.use_count() << "\n";
    return 0;
}
