#include <iostream>
#include <random>
#include <iomanip>

double randomNumber(const double numOne, const double numTwo);
void getNumbers(double& numOne, double& numTwo);

int main() {
    double numOne{}, numTwo{}, result{};
    getNumbers(numOne, numTwo);
    result = randomNumber(numOne, numTwo);

    std::cout 
    << "\n\nRandom Number: "
    << std::fixed << std::setprecision(2)
    << result;
    return 0;
}

double randomNumber(const double numOne, const double numTwo) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> random(numOne, numTwo);
    double temp{random(gen)};
    return temp;
}

void getNumbers(double& numOne, double& numTwo) {
    do {
        std::cout << "Num one: (e.g. 5.12)\n>_";
        std::cin >> numOne;

        std::cout << "Num two: (e.g. 4.68)\n>_";
        std::cin >> numTwo;
    } while (numTwo < numOne);
}
