// 0041 · Strings
// Exercício E241 · ★☆☆

#include <stdio.h>
#include <string.h>

int main(void) {
    char cidade[] = "Manaus";

    for (size_t i = 0; i < sizeof(cidade); i++) {
        if (cidade[i] == '\0') {
            printf("[%zu] \\0 %d\n", i, cidade[i]);
        } else {
            printf("[%zu] %c %d\n", i, cidade[i], cidade[i]);
        }
    }
    printf("strlen = %zu, sizeof = %zu\n", strlen(cidade), sizeof(cidade));
    return 0;
}
