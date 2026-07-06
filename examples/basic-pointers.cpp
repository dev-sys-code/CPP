#include <iostream>

void addBoth(int* numOne, int* numTwo, int* result)
{
    *result = *numOne + *numTwo;
}

int main()
{
    using std::cout;

    int numOne{10};
    int numTwo{15};
    int sum{0};

    addBoth(&numOne, &numTwo, &sum);
    cout << sum;
}
