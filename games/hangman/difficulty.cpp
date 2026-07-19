#include <iostream>
#include "difficulty.h"

void difficulty(int& tries){
    try {
        std::cout << "(1) Easy   [10 tries]\n(2) Medium [8 tries]\n(3) Hard   [6 tries]\n  >_";
        std::cin >> tries;
        if (tries < 1 || tries > 3) {
            throw std::out_of_range("Choice must be in range of 1-3");
        } 
        switch (tries) {
            case 1: tries = 10; break;
            case 2: tries = 8; break;
            case 3: tries = 6; break;
            default: tries = 8;
        }
    } catch (const std::out_of_range& e) {
        std::cerr << "\nError: [" << e.what() << "]\n";
        tries = 8;
    } catch (...) {
        std::cerr << "\nError: [Unknown]";
    }
}
