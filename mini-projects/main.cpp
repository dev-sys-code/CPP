// BROKEN

#include <iostream>
#include <vector>
#include <string>

int main() {
    using std::cout;
    using std::cin;
    using std::vector;

    vector<double> numbers{};
    double temp{};

    for (int i{}; i < 5; i++) {
        cout << "Number:\n>_";
        cin >> temp;
        numbers.push_back(temp);
    }

    temp = 0;
    std::string alltogther{};

    for (int i : numbers) {
        temp += i;

        alltogther += std::to_string(numbers[i]);

        if (i < numbers.size() - 1) {
            alltogther += " + ";
        }
    }

    cout << alltogther << " = " << temp;
}
