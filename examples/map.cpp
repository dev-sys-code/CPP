#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> inventory;

    inventory["Apples"] = 10;
    inventory["Bananas"] = 5;
    inventory.insert({"Orange", 8});

    std::cout << "Apples: " << inventory["Apples"] << "\n";
    return 0;
}
