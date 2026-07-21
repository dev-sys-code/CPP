#include <iostream>
#include <random>

int length();
std::string passwordMaker(const int length);

int main()
{   
    int len = length();
    std::cout << passwordMaker(len);

    return 0;
}

int length() {
    int length{};

    std::cout << "Length of password: \n";
    std::cin >> length;

    return length;
}

std::string passwordMaker(const int length)
{
    std::string chars{"ABCDEFGHIJKLMNOPQRSTUVWXZYabcdefhijklmnopqrstuvxyz123456789!?$"};
    std::string password{};

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> ran(0, chars.size() - 1);

    for (int i{}; i < length; i++) {
        password += chars[ran(gen)];
    }

    return password;
}
