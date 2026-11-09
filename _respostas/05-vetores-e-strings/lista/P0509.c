// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0509 · ★☆☆ · Conserte o contador de letras

#include <stdio.h>

int conta(const char s[], char letra) {
    int total = 0;
    for (int i = 0; s[i] != '\0'; i++) { // para no '\0', não no sizeof
        if (s[i] == letra) {              // == compara; = atribuía
            total++;
        }
    }
    return total;
}

int main(void) {
    char rio[] = "Solimoes e Amazonas";

    printf("Letra o: %d\n", conta(rio, 'o'));
    printf("Letra a: %d\n", conta(rio, 'a'));
    printf("Letra z: %d\n", conta(rio, 'z'));
    return 0;
}
