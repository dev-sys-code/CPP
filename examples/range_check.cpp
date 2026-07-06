// few logic errors

#include <iostream>
#include <exception>


using std::endl;

void validateNumber(int* size) {
    using std::out_of_range;
    using std::invalid_argument;
    using std::cerr;
    using std::cout;
    using std::cin;

    bool valid{false};
    do
    {
        try {
            cout << "Enter number: ";
            cin >> *size;
            if (*size > 100) {
                throw out_of_range("Size cannot be bigger than 100");
            } else if (*size < 1) {
                throw out_of_range("Size cannot be negative");
            } else {
                valid = true;
            }
        } catch (const invalid_argument& e) {
            cerr << "Must be an integer" << endl;
            valid = false;
        } catch (...) {
            cerr << "Unexpected error occurred" << endl;
        }
    } while (!valid);
}

int main()
{
    int user_number{};

    validateNumber(&user_number);

    std::cout << "Test passed";
    return 0;
}
