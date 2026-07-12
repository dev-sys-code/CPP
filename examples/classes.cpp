#include <iostream>
#include <string>

class User {
private:
    std::string username{};
    int age{};
public:
    User(std::string username, int age) {
        this->username = username;
        this->age = age;
    }
    void shout() {
        std::cout << "Name: " << this->username << " | Age: " << this->age;
    }
};

int main()
{
    using std::cout;
    using std::cin;
    using std::getline;
    using std::string;

    string name{};
    int age{};

    cout << "Name: \n> ";
    getline(cin, name);

    cout << "Age: \n> ";
    cin >> age; 

    User u1(name, age);
    u1.shout();
    return 0;
}
