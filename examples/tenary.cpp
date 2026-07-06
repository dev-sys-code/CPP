#include <iostream>

int main()
{
    using std::cout;
    
    int grade{75};

    (grade >= 50) ? cout << "Pass" : cout << "Fail";
    return 0;
}
