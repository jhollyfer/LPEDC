// 0041 · Strings
// Exercício E242 · ★☆☆

#include <stdio.h>
#include <string.h>

void ordem(const char a[], const char b[]) {
    if (strcmp(a, b) < 0) {
        printf("%s vem antes de %s\n", a, b);
    } else if (strcmp(a, b) > 0) {
        printf("%s vem antes de %s\n", b, a);
    } else {
        printf("%s e %s são iguais\n", a, b);
    }
}

int main(void) {
    char s[10] = "pastel";

    printf("%s: strlen %zu, sizeof %zu\n", s, strlen(s), sizeof(s));
    printf("\"verde\" ocupa %zu bytes\n", sizeof("verde"));

    s[4] = '\0'; // o texto acaba aqui; "el" continua na memória
    printf("cortada: %s (%zu)\n", s, strlen(s));

    ordem("abc", "abd");
    ordem("Zebra", "abelha");
    ordem("casa", "casamento");
    return 0;
}
