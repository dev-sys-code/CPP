// windows native 

#include <iostream>
#include <stdlib.h>
#include "withdraw.h"
#include "deposit.h"

int main()
{
    using std::cout;
    using std::cin;
    using std::system;

    int choice{};
    float balance{100}, amount{}, cash{100};

    while (true)
        {
        try
        {   
            cout
                << "\nBalance: " << balance << "\nCash: " << cash
                << "\n\n(1) Withdraw\n(2) Deposit\n\n(0) Exit\n    >_ ";

            cin.clear();
            cin >> choice;

            switch (choice)
            {   
                case 0: return 0;
                case 1: withdraw(balance, amount, cash); break;
                case 2: deposit(balance, amount, cash); break;
                default: throw std::out_of_range("Keep between (0-2)");
            }
        }
        catch (const std::out_of_range& e)
        {
            std::cerr << "Error: " << e.what();
        }
    }
}
