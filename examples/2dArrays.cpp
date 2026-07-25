#include <iostream>

int main() {
    int grid[3][4] {{1, 2, 3}, {4, 5, 6}};


    for (int i{}; i < 2; i++) {
        for (int j{}; j < 3; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
