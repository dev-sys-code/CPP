#include <iostream>
#include <vector>
#include <string>

class Passwords {
private:
    std::vector<std::string> password{};
    std::vector<std::string> apps{};

public:
    Passwords(std::vector<std::string> p, std::vector<std::string> a) {
        this->password = p;
        this->apps = a;
    }
};

void setPassword(std::vector<std::string>& password, std::vector<std::string>& app, int& iterator);

int main() {
    std::vector<std::string> password{"s"};
    std::vector<std::string> app{"s"};
    int iterator{0};

    while (true) {
        Passwords user1(password, app);
        setPassword(password, app, iterator);
    }

    return 0;
}

void setPassword(std::vector<std::string>& password, std::vector<std::string>& app, int& iterator) {
    std::string temp{};
    std::cout << "Enter app:\n    >_";
    std::cin >> temp;
    app.push_back(temp);

    std::cout << "Enter password:\n    >_";
    std::cin >> temp;
    password.push_back(temp);
    iterator++;
    std::cout << "Current count: " << iterator << std::endl;
}
