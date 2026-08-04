#include <iostream>
#include "withdraw.hpp"
#include "deposit.hpp"

class Bank {
private:
    double money{50};
    double card{50};
    double amount{};

public:
    Bank(double m, double c, double a)
        : money{m}, card{c}, amount{a} {};

    void withdrawClass() {
        std::cout << "£";
        std::cin >> this->amount;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        withdraw(this->money, this->card, this->amount);
    }

    void depositClass() {
        std::cout << "£";
        std::cin >> this->amount;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        deposit(this->money, this->card, this->amount);
    }

    void balance() {
        std::cout << "\n\nCash: £" << this->money << " | Card: £" << this->card << "\n"; 
    }
};

void error(const std::string msg) { std::cout << "[Error] " << msg << "\n"; }

int main() {
    int choice{}, temp{};
    Bank bankOne(50, 50, 0);

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
            case 1: bankOne.depositClass(); break;
            case 2: bankOne.withdrawClass(); break;
            case 3: bankOne.balance(); break;
        }
    }
    return 0;
}
