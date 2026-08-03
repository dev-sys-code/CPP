#include <iostream>

int main() {
    int choice{};

    while (true) {
        std::cout 
        << "(1) Withdraw\n"
        << "(2) Deposit\n"
        << "(3) View Balance\n\n"
        << "(0) Exit\n>_";
        std::cin >> choice;
        switch (choice) {
            case 0:
            case 1: 
            case 2:
            case 3: 
            default:
        }
    }
}
