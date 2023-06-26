#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_string(const char *str) {
    printf("String: %s\n", str);
    printf("Visual Representation:\n");

    for (int i = 0; str[i] != '\0'; i++) {
        printf("'%c' ", str[i]);
    }
    printf("\n");

    for (int i = 0; str[i] != '\0'; i++) {
        printf("%2d  ", i);
    }
    printf("\n");
}

int main() {
    char *str = (char *)malloc(3);
    memset(str, 0, 3);

    print_string(str);

    free(str);

    return 0;
}
