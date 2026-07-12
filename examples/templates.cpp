#include <iostream>

template <typename T, typename U>
auto add(T x, U y) { return x + y; }

template <typename T, typename U>
auto sub(T x, U y) { return x - y; }

template <typename T, typename U>
auto div(T x, U y) { return x / y; }

template <typename T, typename U>
auto tim(T x, U y) { return x * y; }

void choice(int& num);

int main()
{
    int numOne{5}, num{};
    double numTwo(1.3);
    choice(num);

    switch (num) {
        case 1: std::cout << add(numOne, numTwo); break;
        case 2: std::cout << sub(numOne, numTwo); break;
        case 3: std::cout << div(numOne, numTwo); break;
        case 4: std::cout << tim(numOne, numTwo); break;
    }
}

void choice(int& num) {
    try
    {
        std::cout << "(1) +\n(2) -\n(3) /\n(4) *\n> ";
        std::cin >> num;
        if (num < 1 || num > 4) {
            throw std::out_of_range("Out of range: 1-4 only");
        }
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what();
    }
}