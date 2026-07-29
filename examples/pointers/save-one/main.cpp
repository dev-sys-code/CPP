#include <iostream>

void takeNum(int* num) { std::cout << *num; }

int main() {
    int x{5};
    int* y{&x};
    takeNum(y);

    return 0;
}
