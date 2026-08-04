#include <iostream>
#include "renameBank.hpp"

void renameBank(std::vector<std::string>& banks) {
    {
        int j{};
        for (auto i : banks) {
            std::cout << "()" << j << ") " << i ;
        }
    }
}
