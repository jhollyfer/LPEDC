// 0040 · Caracteres
// Exercício E239 · ★★★
//
// Resposta: mostra 7. O teste c >= 'A' && c <= 'z' aceita '_' (95), '['
// (91) e '^' (94), que ficam entre 'Z' (90) e 'a' (97) na tabela ASCII.
// Conserto: isalpha(c), ou os dois intervalos separados (veja abaixo).

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char senha[] = {'a', 'B', '_', '9', 'z', '[', 'Q', '^'};
    int n = sizeof(senha);
    int letras = 0;
    int letras_sem_ctype = 0;

    for (int i = 0; i < n; i++) {
        char c = senha[i];
        if (isalpha(c)) {
            letras++;
        }
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            letras_sem_ctype++;
        }
    }
    printf("Letras na senha: %d\n", letras);
    printf("Sem o ctype.h: %d\n", letras_sem_ctype);
    return 0;
}
