#include <iostream>
#include "deposit.h"

void deposit(float& balance, float& amount, float& cash)
{
    using std::cout;
    using std::cin;



    try
    {
    cout << "\nEnter amount to deposit:\n    > ";
    cin >> amount;
        if (amount > cash)
        {   
            cout << "\nCash: " << cash << "\n";
            throw std::out_of_range("Invalid amount");
        }
        balance += amount;
        cash -= amount;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Error: " << e.what();
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Error: " << e.what();
    }
    catch (...)
    {
        std::cerr << "Unknown error occured";
    }
}
