#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;
};

Person getStuff() {
    std::string name{};
    int age{};
    std::cout << "Name:\n  >_";
    std::getline(std::cin, name);

    std::cout << "Age:\n  >_";
    std::cin >> age;

    return {name, age};
}

int main() {
    Person p1 = getStuff();

    std::cout << p1.name << " is " << p1.age << " years old!";
    return 0;
}
