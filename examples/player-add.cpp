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
    names.pop_back();
    {
        int j{};
        for (auto i : names) {
            cout << j + 1 << ": " << i << "\n";
            j++;
        }
    }

    return 0;
}
