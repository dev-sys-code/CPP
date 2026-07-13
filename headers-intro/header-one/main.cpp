#include <iostream>
#include "functions.h"

int main() {
    int number{10}, numberTwo{5}, result{};

    result = add(number, numberTwo);
    std::cout << number << " + " << numberTwo << " = " << result << "\n";

    result = sub(number, numberTwo);
    std::cout << number << " - " << numberTwo << " = " << result << "\n";

    result = mul(number, numberTwo);
    std::cout << number << " * " << numberTwo << " = " << result << "\n";
    return 0;
}
