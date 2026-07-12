/* 
    (1) Number guessing game
    (2) Naughts and crosses
    (3) Hangman
*/  

#include <iostream>
#include <string>
#include <random>
#include <cstdlib>

int main() {
    using std::cout;
    using std::cin;
    using std::cerr;

    int choice{}, number{};

    do
    {
        try
        {
            cout << "(1) Number Guessing Game\n"
                 << "(2) Naughts and Crosses\n"
                 << "(3) Hang man\n";
            
            cin >> choice;
            switch (choice)
            {   
                case 1:
                    number = chooseDifficulty(number);
                    randomNumberGenerator(number);
                default: throw std::out_of_range("Out of range");
            }

        } catch (const std::invalid_argument& e) {
            cerr << "Error: " << e.what() << "\n";
        } catch (...) {
            cerr << "Unknown error occurred\n";
        }
    } while (choice != 0);
}

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
        default: std::cout << "Unknown error occured\n";
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