#include <stdio.h>

int main() {
    int age;
    char name[20];

    printf("Age: ");
    scanf("%d", &age);

    printf("Name: ");
    // The space before %s skips the leftover 'Enter' from the previous input
    scanf(" %s", name); 

    // Use %s to print the full string
    printf("Hello %s, you are %d!\n", name, age);

    return 0;
}
