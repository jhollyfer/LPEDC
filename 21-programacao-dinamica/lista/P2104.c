// Lista · Módulo 21 · Programação dinâmica
// Exercício P2104 · ★☆☆ · As fichas do fliperama
//
// O fliperama vende fichas em pacotes de 1, 5, 6 e 9 fichas, e você quer
// exatamente 11 fichas com o menor número de pacotes. O guloso pega 9 + 1
// + 1 (3 pacotes), mas dá para fazer melhor. Complete a tabela do troco
// mínimo, min[v] = 1 + o menor min[v - p] entre os pacotes p que cabem, e
// guarde em ult[v] o pacote usado no ótimo, para reconstruir a compra.
//
//   Saída esperada:
//   Mínimo para 11 fichas: 2 pacotes
//   Compra: 5 6
//
// Dicas:
// 1. min[0] = 0 e, para v de 1 a 11, comece com um valor enorme (INF) e
//    teste cada pacote p <= v com min[v - p] + 1 < min[v].
// 2. Para reconstruir: v = 11; enquanto v > 0, mostre ult[v] e faça v -=
//    ult[v].
// 3. Resposta esperada: 2 pacotes, 6 + 5 (ou 5 + 6: a ordem depende de
//    como você testa).
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define T 4
#define ALVO 11
#define INF 1000000

int main(void) {
    const int pacote[T] = {1, 5, 6, 9};
    int min[ALVO + 1], ult[ALVO + 1];
    min[0] = 0;
    ult[0] = 0;
    for (int v = 1; v <= ALVO; v++) {
        min[v] = INF;
        ult[v] = 0;
        (void)pacote;
        // COMPLETE AQUI
    }
    printf("Mínimo para %d fichas: %d pacotes\n", ALVO, min[ALVO]);
    printf("Compra:");
    for (int v = ALVO; v > 0 && ult[v] > 0; v -= ult[v]) {
        printf(" %d", ult[v]);
    }
    printf("\n");
    return 0;
}
