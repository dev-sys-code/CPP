#include <iostream>
#include "withdraw.h"
#include "deposit.h"

int main()
{
    using std::cout;
    using std::cin;

    int choice{};
    float balance{100}, amount{30};

    while (true)
        {
        try
        {
            cout << "\nBalance: £" << balance << "\n\n(1) Withdraw\n(2) Deposit\n\n\n(0) Exit\n    >_ ";
            cin.clear();
            cin >> choice;

            switch (choice)
            {   
                case 0: return 0;
                case 1: withdraw(balance, amount); break;
                default: throw std::out_of_range("Keep between (0-3)");
            }
        }
        catch (const std::out_of_range& e)
        {
            std::cerr << "Error: " << e.what();
        }
    }
}
