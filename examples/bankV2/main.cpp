#include <iostream>
#include <iomanip>
#include <vector>
#include "withdraw.hpp"
#include "deposit.hpp"
#include "createBank.hpp"
#include "deleteBank.hpp"
#include "renameBank.hpp"

class Bank {
private:
    std::string name{};
    double money{50};
    double card{50};
    double amount{};

public:
    Bank(double m, double c, double a, std::string n)
        : money{m}, card{c}, amount{a}, name(n) {};

    std::string getName() { return name; }

    void withdrawClass() {
        std::cout << "£";
        std::cin >> amount;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        withdraw(money, card, amount);
    }

    void depositClass() {
        std::cout << "£";
        std::cin >> amount;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        deposit(money, card, amount);
    }

    void balance() {
        std::cout << "\n\nCash: £" << std::fixed << std::setprecision(2) << money << " | Card: £" << card << "\n"; 
    }

    void viewBanks(const std::vector<std::string> banks) {
        for (auto i : banks) {
            std::cout << "- " << i << "\n";
        }
    }

};

void error(const std::string msg) { std::cout << "[Error] " << msg << "\n"; }

int main() {
    int choice{}, temp{};

    std::vector<std::string> banks{};
    Bank bankOne(50, 50, 0, "Untitled Bank");

    banks.push_back(bankOne.getName());

    while (true) {
        std::cout 
            << "______________________\n"
            << "|        Bank        |\n"
            << "|                    |\n"
            << "| (1) Withdraw       |\n"
            << "| (2) Deposit        |\n"
            << "| (3) View Balance   |\n"
            << "|                    |\n"
            << "| (4) Create Bank    |\n"
            << "| (5) Delete Bank    |\n"
            << "| (6) View Banks     |\n"
            << "| (7) Rename a Bank  |\n"
            << "|                    |\n"
            << "| (0) Exit           |\n"
            << "|____________________|\n>_ ";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 0: return 0;
            case 1: bankOne.withdrawClass(); break;
            case 2: bankOne.depositClass(); break;
            case 3: bankOne.balance(); break;
            case 4: break;
            case 5: break;
            case 6: bankOne.viewBanks(banks); break;
            case 7: break;
            default: error("Out of range (0-7 Only)");
        }
    }
    return 0;
}
