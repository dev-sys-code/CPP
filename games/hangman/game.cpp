#include <iostream>
#include "difficulty.h"
#include "game.h"

int main() {
    using std::cout;
    int tries{};
    bool win{false};
    difficulty(tries);
    
    game(tries, win);
}
