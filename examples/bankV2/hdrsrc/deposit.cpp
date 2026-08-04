#include <iostream>
#include "deposit.hpp"

static void buy(double& money, double& card, const double amount) {
    money -= amount;
    card += amount;
    std::cout << "Thanks for using us!\n";
}

void deposit(double& money, double& card, const double amount) {
    int choice{};

    if (amount > money) {
        std::cout << "Insufficient balance: £" << money << " available\n";
    } else if (amount > money / 2) {
        while (true) {
            std::cout << "£" << amount << " is over 50% of your balance, are you sure? (1 - yes / 0 - no\n";
            std::cin >> choice;
            if (choice == 0) {
                std::cout << "\nYou have not been charged";
            } else {
                buy(money, card, amount);
            }
            break;
        }
    }
    else {
        buy(money, card, amount);
    }
}
