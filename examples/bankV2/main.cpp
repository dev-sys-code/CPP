#include <iostream>
#include "withdraw.hpp"
#include "deposit.hpp"

void error(const std::string msg) {
    std::cout << "[Error] " << msg << "\n";
}

int main() {
    int choice{};
    double money{}, card{}, amount{};

    while (true) {
        std::cout 
        << "(1) Withdraw\n"
        << "(2) Deposit\n"
        << "(3) View Balance\n\n"
        << "(0) Exit\n>_";

        std::cin >> choice;

        switch (choice) {
            case 0: return 0;
            case 1: withdraw(money, card, amount);
            case 2:
            case 3: 
            default: error("Not in range");
        }
        
        std::cout << "£";
        std::cin >> amount;

    }
    return 0;
}
