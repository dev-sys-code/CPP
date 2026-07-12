#include <iostream>
#include <random>
#include "num-guess.h"

void randomNumberGenerator(int& number)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> random(1, number);
    number = random(gen);
}

int chooseDifficulty(const int number)
{
    switch (number)
    {
        case 1: return 10;
        case 2: return 25;
        default: return 10;
    }
}

void numGuessGame(const int randomNum)
{
    int guesses{3}, number{};

    while (guesses != 0)
    {
        std::cout << "Guess the number:\n> ";
        std::cin >> number;
        if (number > randomNum) {
            guesses --;
            std::cout << "Too high! " << guesses << " guesses remaining!\n";
        } else if (number < randomNum) {
            guesses --;
            std::cout << "Too low! " << guesses << " guesses remaining!\n";
        } else {
            std::cout << "You win!\n";
        }
    }
}