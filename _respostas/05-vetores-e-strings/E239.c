// 0040 · Caracteres
// Exercício E239 · ★★★
//
// Antes do conserto o programa mostra 7: o teste c >= 'A' && c <= 'z' aceita
// '_' (95), '[' (91) e '^' (94), que ficam entre 'Z' (90) e 'a' (97).
// Conserto com o ctype.h: if (isalpha(c)). Abaixo, a versão sem o ctype.h:
// os dois intervalos separados.

#include <stdio.h>

int main(void) {
    char senha[] = {'a', 'B', '_', '9', 'z', '[', 'Q', '^'};
    int n = sizeof(senha);
    int letras = 0;

    for (int i = 0; i < n; i++) {
        char c = senha[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            printf("contou: %c (%d)\n", c, c);
            letras++;
        }
    }
    printf("Letras na senha: %d\n", letras);
    return 0;
}
