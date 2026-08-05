#include <iostream>
#include "renameBank.hpp"

void renameBank(std::vector<std::string>& banks) {
    int choice{};
    {
        int j{};
        for (auto i : banks) {
            std::cout << "(" << j << ") " << i ;
        }
    }
    std::cout << "Which Bank are you renaming?\n>_ ";
    std::cin >> choice;
}
