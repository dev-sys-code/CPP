#include <stdio.h>

int main() {
    char name[20];
    printf("Name: ");
    scanf("%s", &name);
    printf("Hello %s%s", name, "!");
}
