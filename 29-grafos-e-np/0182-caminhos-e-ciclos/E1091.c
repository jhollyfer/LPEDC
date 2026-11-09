// 0182 · Caminhos e ciclos
// Exercício E1091 · ★★★
//
// Ache o bug. Este Hierholzer roda no bairro do texto, que tem 8 ruas de
// mão dupla, mas o circuito sai com o dobro do tamanho e passa duas vezes
// pela mesma rua (repare em G P G logo no começo):
//
//   Saída que aparece:
//   Circuito: G P G F P F I F S P E I E P S F G
//   Ruas percorridas: 16 de 8
//
//   Saída esperada:
//   Circuito: G P F I E P S F G
//   Ruas percorridas: 8 de 8
//
// O programa compila e roda sem erro do sanitizer; o problema é de lógica.
// Conserte-o.
//
// Dicas:
// 1. Numa matriz de grafo NÃO dirigido, cada rua ocupa duas casas.
// 2. Quando o caminhão passa de u para v, qual casa é apagada? E a outra?
// 3. Resposta esperada: a saída acima. Basta apagar também rua[v][u].
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define V 6
#define MAX_PILHA 40

const char letra[V] = {'G', 'P', 'F', 'E', 'I', 'S'};
int rua[V][V];

int main(void) {
    int ruas[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 5}, {2, 4}, {2, 5}, {3, 4}};
    int e = 8;
    for (int k = 0; k < e; k++) {
        rua[ruas[k][0]][ruas[k][1]] = 1;
        rua[ruas[k][1]][ruas[k][0]] = 1;
    }

    int pilha[MAX_PILHA], topo = 0, circuito[MAX_PILHA], n = 0;
    pilha[topo++] = 0;
    while (topo > 0) {
        int u = pilha[topo - 1], v = 0;
        while (v < V && rua[u][v] == 0) v++;
        if (v < V) {
            rua[u][v] = 0; // apaga a rua
            pilha[topo++] = v;
        } else {
            circuito[n++] = u;
            topo--;
        }
    }
    printf("Circuito:");
    for (int i = n - 1; i >= 0; i--) printf(" %c", letra[circuito[i]]);
    printf("\nRuas percorridas: %d de %d\n", n - 1, e);
    return 0;
}
