// 0188 · Aproximação
// Exercício E1128 · ★★★
//
// Ache o bug. Esta cobertura 2-aproximada das câmeras (ruas na ordem 2 do
// E1125) põe câmera em todas as sete esquinas, e as ruas escolhidas têm
// pontas em comum (B aparece em B-F e em A-B):
//
//   Saída que aparece:
//   Ruas escolhidas: B-F C-E A-B C-D F-G
//   Câmeras em: A B C D E F G (7)
//
//   Saída esperada:
//   Ruas escolhidas: B-F C-E
//   Câmeras em: B C E F (4)
//
// O programa compila e roda sem erro; o problema é de lógica. Conserte-o.
//
// Dicas:
// 1. Quando uma rua já está vigiada? Basta uma das pontas ter câmera, ou
//    as duas precisam ter?
// 2. A prova do fator 2 depende de as ruas escolhidas não terem pontas em
//    comum. Com o bug, isso deixa de valer e a garantia vai embora.
// 3. Resposta esperada: a saída esperada acima. Troque && por ||.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

#define V 7
#define E 8

const char nome[V] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
const int rua[E][2] = {{1, 5}, {2, 4}, {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};

int main(void) {
    bool camera[V] = {false};
    printf("Ruas escolhidas:");
    for (int k = 0; k < E; k++) {
        int a = rua[k][0], b = rua[k][1];
        if (camera[a] && camera[b]) continue; // rua já vigiada
        printf(" %c-%c", nome[a], nome[b]);
        camera[a] = camera[b] = true;
    }
    int total = 0;
    printf("\nCâmeras em:");
    for (int v = 0; v < V; v++)
        if (camera[v]) printf(" %c", nome[v]), total++;
    printf(" (%d)\n", total);
    return 0;
}
