#include <iostream>
#include <random>

void askNums(int& numOne, int& numTwo);
int randomNumGen(const int numOne, const int numTwo);

int main()
{
    using std::cout;
    using std::endl;

    int numOne{}, numTwo{};
    askNums(numOne, numTwo);
    cout << "Random number (" << numOne << ", " << numTwo << "): " << randomNumGen(numOne, numTwo);
    return 0;
}

void askNums(int& numOne, int& numTwo) {
    std::cout << "\n======= Random number generator =======\n";
    std::cout << "Number one:\n> ";
    std::cin >> numOne;

    std::cout << "Number two:\n> ";
    std::cin >> numTwo;
}

int randomNumGen(const int numOne, const int numTwo) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> random(numOne, numTwo);

    return random(gen);
}
