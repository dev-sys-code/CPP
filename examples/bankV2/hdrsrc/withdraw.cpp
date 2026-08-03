#include <iostream>
#include "withdraw.hpp"

void buy(double& money, double& card, const double amount) {
    card -= amount;
    std::cout << "Thanks for using us!\n";
}

void withdraw(double& money, double& card, const double amount) {
    int choice{};

    if (amount > card) {
        std::cout << "Insufficient balance: £" << card << " available\n";
    } else if (amount > card / 2) {
        while (true) {
            std::cout << "£" << amount << " is over 50% of your balance, are you sure? (1 - yes / 0 - no)";
            std::cin >> choice;
            if (choice == 0) {

            } else {
                buy(money, card, amount);
            }
        }
    }
}

