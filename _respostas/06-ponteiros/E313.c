// 0053 · Ponteiros e strings
// Exercício E313 · ★☆☆

#include <stdio.h>

int conta_vogais(const char *s) {
    int total = 0;
    while (*s != '\0') {
        switch (*s) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            total++;
            break;
        default:
            break;
        }
        s++;
    }
    return total;
}

int main(void) {
    printf("Vogais: %d\n", conta_vogais("promocao de pastel na feira de domingo"));
    return 0;
}
