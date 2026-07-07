#include <iostream>

void showBalance(double& money);
void deposit(double& money);
void withdraw(double& money);

int main()
{
    using std::cout;
    using std::cin;
    int user_input{};
    double money{50.0};

    do {
        cout << "(1) Show balance\n(2) Deposit\n(3) Withdraw\n\n(0) End program";
        cin >> user_input;

        switch (user_input) {
            case 0: return 0;
            case 1: showBalance(money); break;
            case 2: deposit(money); break;
            case 3: withdraw(money); break;
            default: cout << "Out of range";
        }
    } while (user_input != 0);

    return 0;
}

void showBalance(double& money) 
{
    std::cout << "Balance: \u00A3" << money << std::endl;
}

void deposit(double& money)
{
    double deposit{};
    std::cout << "Deposit: " << std::endl;
    std::cin >> deposit;
    std::cout << "Sucessfully desposited \u00A3" << deposit << std::endl;
    money += deposit;
}

void withdraw(double& money)
{
    double withdraw{};
    std::cout << "Withdraw: " << std::endl;
    std::cin >> withdraw;
    std::cout << "Sucessfully withdrew \u00A3" << withdraw << std::endl;
    money -= withdraw;
}
