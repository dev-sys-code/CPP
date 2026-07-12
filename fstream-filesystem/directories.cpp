#include <iostream>
#include <fstream>
#include <string>

void fileExample() {
    std::ofstream outFile("text.txt");

    if (outFile.is_open()) {
        outFile << "I am writing to a file";
    } else {
        std::cerr << "Error";
    }
}

int main() {
    fileExample();
    return 0;
}