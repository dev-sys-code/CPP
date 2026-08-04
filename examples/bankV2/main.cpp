#include <iostream>
#include "withdraw.hpp"
#include "deposit.hpp"

class Person {
private:
    double money{50};
    double card{50};
    double amount{};

public:
    Person(double m, double c, double a) {
        this->money = m;
        this->card = c;
        this->amount = a;
    }

    void withdrawClass() {
        std::cout << "£";
        std::cin >> amount;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        withdraw(this->money, this->card, this->amount);
    }
};

void error(const std::string msg) { std::cout << "[Error] " << msg << "\n"; }

int main() {
    int choice{}, temp{};
    double money{50}, card{50}, amount{};

    while (true) {
        std::cout 
            << "\n======= Bank =======\n"
            << "(1) Withdraw\n"
            << "(2) Deposit\n"
            << "(3) View Balance\n\n"
            << "(0) Exit\n>_";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 0: return 0;
            case 1:
                std::cout << "£";
                std::cin >> amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                withdraw(money, card, amount); break;

            case 2:
                std::cout << "£";
                std::cin >> amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                deposit(money, card, amount); break;

            case 3: 
                std::cout << "\n\nCash: £" << money << " | Card: £" << card << "\n"; 
                continue;

            default: error("Not in range"); break;
        }
    }
    return 0;
}
