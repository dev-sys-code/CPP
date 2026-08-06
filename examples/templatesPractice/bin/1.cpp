#include <iostream>

template<typename T, typename U>
auto add(T a, U b) {
    return a + b;
}

int main() {
    std::cout << add<int, double>(3, 4.5);
}
