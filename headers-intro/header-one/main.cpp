#include <iostream>
#include "add.h"

int main() {
    int result{add(5, 7)};
    std::cout << "Sum: " << result << "\n";
    return 0;
}
