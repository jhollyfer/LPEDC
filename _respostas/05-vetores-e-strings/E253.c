// 0043 · Juntando tudo
// Exercício E253 · ★☆☆

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char frase[200];
    char vogais[] = "aeiou";
    int contagem[5] = {0};

    printf("Frase: ");
    if (fgets(frase, sizeof(frase), stdin) == NULL) {
        return 1;
    }
    frase[strcspn(frase, "\n")] = '\0';

    for (int i = 0; frase[i] != '\0'; i++) {
        int c = tolower((unsigned char) frase[i]);
        for (int k = 0; k < 5; k++) {
            if (c == vogais[k]) {
                contagem[k]++;
            }
        }
    }

    for (int k = 0; k < 5; k++) {
        printf("%c: %d\n", vogais[k], contagem[k]);
    }
    return 0;
}
