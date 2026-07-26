#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string code{};
    std::cout << "Code: ";
    std::getline(std::cin, code);\

    size_t equalPos{code.find('=')};

    std::string varName{code.substr(0, equalPos)};

    while (!varName.empty() && varName.back() == ' ') {
        varName.pop_back();
    }

    std::string valStr{code.substr(equalPos + 1)};

    int val{std::stoi(valStr)};

    std::unordered_map<std::string, int> memory;
    memory[varName] = val;

    std::cout << "Variable: '" << varName << "' is stored with value: " << val;

    return 0;
}
