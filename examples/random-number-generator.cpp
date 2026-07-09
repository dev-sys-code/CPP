#include <iostream>
#include <random>

void randomNumberGenerator(const int numOne, const int numTwo, int & number);

int main() {
    using std::cout;
    using std::cin;

    int numOne{}, numTwo{}, number{};
    cout << "Number one: ";
    cin >> numOne;

    cout << "Number two: ";
    cin >> numTwo;
    randomNumberGenerator(numOne, numTwo, number);

    cout << "Random number: " << number;
    return 0;
}

void randomNumberGenerator(const int numOne, const int numTwo, int & number) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random(numOne, numTwo);
    number = random(gen);
}
