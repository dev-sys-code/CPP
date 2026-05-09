#include <stdio.h>

int main() {
    int age = 19;
    if (age < 18) {
        printf("Too young to vote!");
    } else if (age >= 18) {
        printf("You can vote!");
    }
    return 0;
}
