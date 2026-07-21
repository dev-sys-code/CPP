#include <iostream>
#include <stdexcept>
#include <random>
#include <string>

int randomNumberGenerator(const int numOne, const int numTwo);
void difficulty(int& difficulty);
std::string game(int randomNum);
void winOrLose(const std::string& win);

int main()
{
    using std::cout;
    using std::cin;
    using std::string;

    int numOne{1}, numTwo{}, mode{};
    difficulty(mode); 
    switch (mode) {
        case 1: numTwo = 10; break;
        case 2: numTwo = 25; break;
        case 3: numTwo = 50; break;
        default: cout << "Unknown error";
    }
    int randomNum{randomNumberGenerator(numOne, numTwo)};
    string win{game(randomNum)};
    winOrLose(win);

    return 0;
}

int randomNumberGenerator(const int numOne, const int numTwo)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> random(numOne, numTwo);
    return random(gen);
}

void difficulty(int& difficulty)
{
    try {
        std::cout << "(1) Easy\n(2) Medium\n(3) Hard\n> ";
        std::cin >> difficulty;
        if (difficulty < 1 || difficulty > 3) {
            throw std::out_of_range("Out of range. 1-3 only\n");
        }
        std::cout << "Difficulty set\n\n";

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << "\n";
    } catch (...) {
        std::cerr << "Unknown error\n";
    }
}

std::string game(int randomNum)
{
    int guesses{3}, number{};
    while (guesses != 0) {
        guesses --; 
        std::cout << "Guess number: \n> ";
        std::cin >> number;
        if (number == randomNum) {
            return "1";
        } else if (number > randomNum) {
            std::cout << "Too high | " << guesses << " guesses remaining!\n\n";
        } else {
            std::cout << "Too low | " << guesses << " guesses remaining!\n\n";
        }
    }
    return "0";
}

void winOrLose(const std::string& win)
{
    if (win == "1") {
        std::cout << "You win!";
    } else {
        std::cout << "You lose!";
    }
}
