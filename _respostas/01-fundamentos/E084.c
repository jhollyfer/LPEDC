// 0014 · Atribuição, ++ e --
// Exercício E084 · ★★★
//
// Resposta: com valores perto de INT_MAX, casa += visitante pode estourar o
// int, o que é comportamento indefinido. A troca com variável auxiliar não
// tem esse risco e é mais fácil de ler.

#include <stdio.h>

int main(void) {
    int casa = 2;
    int visitante = 5;

    casa += visitante;            // casa = 7 (a soma dos dois)
    visitante = casa - visitante; // 7 - 5 = 2
    casa -= visitante;            // 7 - 2 = 5

    printf("Casa %d x %d Visitante\n", casa, visitante);
    return 0;
}
