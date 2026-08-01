#include <iostream>
#include <vector>

int main() {
    using std::vector;
    using std::cout;
    using std::getline;
    using std::cin;
    using std::string;

    vector<std::string> names{};
    string temp{};
    

    do {
        cout << "Enter player (0 to list)\n  >_";
        getline(cin, temp);
        names.push_back(temp);
    } while (temp != "0");
    
    {
        int j{};
        for (auto i : names) {
            cout << j << ": " << i << "\n";
            j++;
        }
    }

    return 0;
}
