#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::ofstream file("test.txt", std::ios::app);

    int age{};
    std::string name{};

    if (!file.is_open()) {
        std::cout << "Couldn't open file\n";
        return 1;
    }

    std::cout << "Enter age:\n  >_";
    std::cin >> age;

    std::cout << "Enter name:\n  >_";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max());
    std::getline(std::cin, name);

    file << "Age: " << age << "\n";
    file << "Name: " << name << "\n";

    file.close();
}
