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

bool chooseDifficulty(const int number) {
    switch (number)
    {
        case 1: return true;
        case 2: return false;
        default: std::cout << "Unknown error occured\n";
    }
}