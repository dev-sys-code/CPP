#include <iostream>
#include "withdraw.hpp"
#include "deposit.hpp"

void error(const std::string msg) {
    std::cout << "[Error] " << msg << "\n";
}

int main() {
    int choice{};
    double money{50}, card{50}, amount{};

    while (true) {
        std::cout 
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

            case 3: 
                std::cout << "Cash: £" << money << "\nCard: £" << card; continue;

            default: error("Not in range"); break;
        }
    }
    return 0;
}
