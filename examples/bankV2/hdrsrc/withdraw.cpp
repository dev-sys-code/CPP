#include <iostream>
#include "withdraw.hpp"

void buy(double& money, double& card, const double amount) {
    card -= amount;
    money += amount;
    std::cout << "Thanks for using us!\n";
}

void withdraw(double& money, double& card, const double amount) {
    int choice{};

    if (amount > card) {
        std::cout << "Insufficient balance: £" << card << " available\n";
    } else if (amount > card / 2) {
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
