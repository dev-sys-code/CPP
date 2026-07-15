#include "withdraw.h"
#include <iostream>

void withdraw(float& balance, float& amount)
{
    using std::cout;
    using std::cin;

    cout << "\nEnter amount to withdraw:\n    > ";
    cin >> amount;

    float warning{(amount / balance) * 100};

    if (amount > balance)
    {
        cout << "\nInvalid amount | Max: " << balance << "\n";
    }
    else if (warning > 50)
    {
        try
        {
            std::string confirm{};
            cout << "This transaction is over 50\% of your balance. Are you sure (y/n)\n    >_";
            cin >> confirm;

            if (confirm != "y" && confirm != "n" && confirm != "Y" && confirm != "N")
            {
                throw std::invalid_argument(confirm + " is not recognised");
            }

            else if (confirm == "y" || confirm == "Y")
            {
                balance -= amount;
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
    }
}

void add() {

}
