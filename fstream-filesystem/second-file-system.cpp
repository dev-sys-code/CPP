#include <iostream>
#include <fstream>
#include <string>

void textForFile(std::string& text);
void fileWrite(const std::string& text);

int main() {
    std::string text{};

    textForFile(text);
    fileWrite(text);
    return 0;
}

void textForFile(std::string& text) {
    std::cout << "Enter text:\n> ";
    std::getline(std::cin, text);
}

void fileWrite(const std::string& text) {
    std::ofstream outFile("text.txt");

    if (outFile.is_open()) {
        outFile << text;
        std::cout << "Successfuly writen to file";
    } else {
        std::cerr << "Error";
    }
}