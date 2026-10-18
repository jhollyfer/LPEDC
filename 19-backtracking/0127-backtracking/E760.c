// 0127 · Backtracking
// Exercício E760 · ★★☆
//
// Na banca, os pacotes de figurinhas vêm com quantidades diferentes: 25,
// 20, 15, 12, 10, 8 e 5 figurinhas (um pacote de cada). Você precisa de
// exatamente 60 figurinhas para completar o álbum. O programa abaixo já
// mostra todas as combinações. Estenda-o para, no fim, mostrar também a
// combinação com MENOS pacotes (se houver empate, fique com a primeira
// encontrada).
//
//   Saída esperada:
//   25 20 15
//   25 20 10 5
//   25 15 12 8
//   25 12 10 8 5
//   20 15 12 8 5
//   menos pacotes: 25 20 15 (3 pacotes)
//
// Dicas:
// 1. Passe a quantidade de pacotes escolhidos como parâmetro (k), do mesmo
//    jeito que a soma: assim ela se desfaz sozinha na volta.
// 2. Na solução, se k for menor que o melhor até agora, copie leva[0..i-1]
//    para um vetor melhor[] (e zere o resto dele).
// 3. Resposta esperada: as 6 linhas acima.
//
// Escreva sua resposta abaixo (estenda o programa):

#include <stdbool.h>
#include <stdio.h>

#define N 7
#define ALVO 60

const int pacotes[N] = {25, 20, 15, 12, 10, 8, 5};
bool leva[N];

void mostra(const bool escolha[], int ate) {
    int primeiro = 1;
    for (int j = 0; j < ate; j++) {
        if (escolha[j]) {
            printf(primeiro ? "%d" : " %d", pacotes[j]);
            primeiro = 0;
        }
    }
}

void tenta(int i, int soma) {
    if (soma > ALVO) {
        return;
    }
    if (soma == ALVO) {
        mostra(leva, i);
        printf("\n");
        return;
    }
    if (i == N) {
        return;
    }
    leva[i] = true;
    tenta(i + 1, soma + pacotes[i]);
    leva[i] = false;
    tenta(i + 1, soma);
}

int main(void) {
    tenta(0, 0);
    return 0;
}
