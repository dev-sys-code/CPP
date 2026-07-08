// Windows only due to system

#include <iostream>
#include <string>
#include <random>
#include <array>
#include <cstdlib>

using std::string;

void randomNumberGenerator(int & number);
string computerGuess(const int number);

int main() {
    using std::array;
    using std::cout;
    using std::cin;
    using std::endl;
    using std::system;

    array<string, 3> choices{"Rock", "Paper", "Scissors"};
    string user_input{};
    int computerNum{};
    while (user_input != "0") {
        randomNumberGenerator(computerNum);
        string computerGuess{choices[computerNum]};
        
        cout << "Enter a choice (rock-paper-scissors)" << endl;
        cin >> user_input;
        system("cls");

        bool win = (computerGuess == "Rock" && (user_input == "Paper" || user_input == "paper")) ||
           (computerGuess == "Paper" && (user_input == "Scissors" || user_input == "scissors")) ||
           (computerGuess == "Scissors" && (user_input == "Rock" || user_input == "rock"));

        if (win) {
            cout << "Win | Computer guess: " << computerGuess << endl;
        } else if (user_input == computerGuess) {
            cout << "Draw | Computer guess: " << computerGuess << endl;
        } else {
            cout << "Lose | Computer guess: " << computerGuess << endl;
        }
    }
    return 0;
}

void randomNumberGenerator(int & number)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random(0, 2);
    number = random(gen);
}

string computerGuess(const int number)
{
    switch(number) {
        case 0: return "Rock";
        case 1: return "Scissors";
        case 2: return "Paper";
    }
}
