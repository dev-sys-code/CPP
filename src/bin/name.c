#include <stdio.h>

int main() {
    int age;
    char name[20];

    printf("Age: ");
    scanf("%d", &age);

    printf("Name: ");

    scanf(" %s", name); 

    printf("Hello %s, you are %d!\n", name, age);

    return 0;
}
