#include <iostream>

class Enemy {
private:
    int* enemys{};

public:
    Enemy(int e) : enemys(&e) {};

    void addEnemy() {
        enemys += 1;
    }

    void shout() {
        if (!enemys) {
            std::cout << "NULL";
        } else {
            std::cout << *enemys << " enemys!";
        }
    }
};

int main() {
    int* ptr{nullptr};
    Enemy e1(*ptr);

    e1.shout();
    return 0;
}
