#include "withdraw.h"
#include <iostream>

void withdraw(float& balance, float& amount)
{
    using std::cout;
    using std::cin;

    cout << "Enter amount to withdraw:\n    > ";
    cin >> amount;

    float warning{(amount / balance) * 100};

    if (amount > balance)
    {
        cout << "Invalid amount | Max: £" << balance << "\n";
    }
    else if (warning > 50)
    {
        try
        {
            char confirm{};
            cout << "This transaction is over 50\% of your balance. Are you sure (y/n)\n    >_";
            cin >> confirm;

            if (confirm != 'y' || confirm != 'n' || confirm != 'Y' || confirm != 'N')
            {
                throw std::invalid_argument(confirm + " is not recognised");
            }

            if (confirm == 'Y' || confirm == 'y')
            {
                balance -= amount;
                cout << "Have a great day\n";
            }
            else
            {
                cout << "Returning...\n"; 
            }
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << "Error: " << e.what();
        }
        catch (...)
        {
            std::cerr << "Unknown error occured";
        }
    }

    else
    {
        balance -= amount;
        cout << "Have a great day\n";
    }
}

void add() {

}
