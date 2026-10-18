// 0159 · Horspool
// Exercício E949 · ★☆☆
//
// Complete monta_saltos(p, m, salto): todas as 256 casas começam com m e,
// para cada letra p[j] com j de 0 até m - 2, salto[p[j]] = m - 1 - j. O main
// mostra a tabela de "PIPOCA" e de "ARARA":
//
//   Saída esperada:
//   P=3 I=4 O=2 C=1 A=6 outras=6
//   A=2 R=1 outras=5
//
// Dicas:
// 1. O índice da tabela é a letra convertida: salto[(unsigned char) p[j]].
// 2. Como j cresce, uma letra repetida fica com o valor da ocorrência mais à
//    direita: o 'P' de PIPOCA aparece em 0 e em 2, e vale 6 - 1 - 2 = 3.
// 3. A última letra não entra no laço (senão o salto dela seria 0). Por isso
//    o 'A' de PIPOCA, que só aparece no fim, vale 6. Já o 'A' de ARARA vale 2:
//    ele também aparece na posição 2.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete monta_saltos):

#include <stdio.h>
#include <string.h>

#define ALFABETO 256

void monta_saltos(const char *p, int m, int salto[]) {
    (void)p; // apague estas linhas
    (void)m;
    for (int c = 0; c < ALFABETO; c++) {
        salto[c] = 0;
    }
}

int main(void) {
    int salto[ALFABETO];
    monta_saltos("PIPOCA", 6, salto);
    printf("P=%d I=%d O=%d C=%d A=%d outras=%d\n",
           salto['P'], salto['I'], salto['O'], salto['C'], salto['A'], salto['X']);
    monta_saltos("ARARA", 5, salto);
    printf("A=%d R=%d outras=%d\n", salto['A'], salto['R'], salto['X']);
    return 0;
}
