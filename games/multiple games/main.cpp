/* 
    (1) Number guessing game
    (2) Naughts and crosses
    (3) Hangman
*/  

#include <iostream>
#include "num_guess.h"

int main() {
    int choice{}, difficultyChoice{}, number{};

    std::cout << "Select Difficulty: (1) Easy, (2) Hard\n> ";
    std::cin >> difficultyChoice;

    number = chooseDifficulty(difficultyChoice);
    randomNumberGenerator(number);
    numGuessGame(number);
}