#include <iostream>
#include <string>
#include <fstream>

class User{
private:
    std::string name{};
    int age{};
    bool coding{false};

public:
    User(std::string n, int a, bool c) {
        this->name = n;
        this->age = a;
        this->coding = c;
    }

    void shout() {
        std::string temp{};
        if (this->coding) temp = "Yes";
        else temp = "No"; 
        std::cout << 
        "Name: " << this->name << " | "
        "Age: " << this->age << " | "
        "Coding: " << temp << "\n\n";
    }
};

void getName(std::string& name);
int getAge(int age);
bool getCoding(bool coding);

int main() {
    using std::string;
    using std::cin;
    using std::cout;
    
    string name{}, verify{};
    

    getName(name);
    int age{getAge(age)};
    bool coding{getCoding(coding)};

    User u1(name, age, coding);
    u1.shout();

    do {
        cout << "Would you like to save to file: (y/n)\n  >_";
        cin >> verify;
        if (verify == "y" || verify == "Y") {
            std::ofstream file("data.txt");

            if (!file.is_open()) cout << "Unexpected error\n";

            string temp{};
            if (coding) temp = "Yes";
            else temp = "No";
            file << 
            "Name: " << name << " | "
            "Age: " << age << " | "
            "Coding: " << temp;
            return 0;
        } else {
            return 0;
        }
    } while(true);
}

void getName(std::string& name) {
    std::cout << "Name:\n  >_";
    std::getline(std::cin, name);
}

int getAge(int age) {
    std::cout << "Age:\n  >_";
    std::cin >> age; 
    return age;
}

bool getCoding(bool coding) {
    std::string temp{};
    do {
        std::cout << "Coding: (y/n)\n  >_";
        std::cin >> temp; 
    if (temp == "y" || temp == "Y") return true;
    else if (temp == "n" || temp == "N") return false;
    } while (true);

    return 0;
}
