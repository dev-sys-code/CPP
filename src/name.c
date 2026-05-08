#include <stdio.h>

int main() {
    char name[5];
    printf("Name: ");
    scanf("%s", &name);
    printf("Hello %s%s", name, "!");
}
