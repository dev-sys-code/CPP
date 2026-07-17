#include <iostream>
#include <thread>
#include <chrono>

void askUser(int& time);

int main() {
    int time{};
    askUser(time);

    std::this_thread::sleep_for(std::chrono::seconds(time));

    std::cout << time << "s has passed!";
}

void askUser(int& time) {
    std::cout << "Time:\n  >_";
    std::cin >> time;
}
