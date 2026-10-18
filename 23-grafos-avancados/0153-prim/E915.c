// 0153 · Prim: a árvore que cresce
// Exercício E915 · ★★☆
//
// Mesmas seis estações de bicicleta do E914. A pergunta agora é: começar o
// Prim por outra estação muda alguma coisa? Escreva a função
// prim(origem), na versão sem heap (O(V²)), que mostra a origem, a ordem
// em que as estações entram na rede e o total, e chame-a para cada uma das
// seis origens.
//
//   Saída esperada:
//   Rodoviária: Rodoviária Feira Praça Museu Orla Estádio | 22
//   Praça: Praça Museu Orla Rodoviária Feira Estádio | 22
//   Museu: Museu Orla Praça Rodoviária Feira Estádio | 22
//   Orla: Orla Museu Praça Rodoviária Feira Estádio | 22
//   Feira: Feira Rodoviária Praça Museu Orla Estádio | 22
//   Estádio: Estádio Orla Museu Praça Rodoviária Feira | 22
//
// Dicas:
// 1. Os vetores chave[] e na_rede[] são locais da função: cada chamada
//    começa do zero, com chave[origem] = 0.
// 2. Mostre cada estação no momento em que ela entra (quando é escolhida
//    como u), não quando a chave dela cai.
// 3. Resposta esperada: a saída acima. A ordem muda, o total não: como os
//    pesos são todos diferentes, a árvore mínima é uma só, e as seis
//    execuções escolhem as mesmas cinco ciclofaixas.
//
// Escreva sua resposta abaixo (escreva prim):

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 6
#define INFINITO INT_MAX

const char *estacoes[V] = {"Rodoviária", "Praça", "Museu", "Orla", "Feira", "Estádio"};
int dist[V][V];

int prim(int origem) {
    (void)origem; // apague esta linha
    return 0;
}

int main(void) {
    int trechos[][3] = {{0, 1, 5}, {0, 4, 3}, {1, 2, 4}, {1, 4, 6}, {2, 3, 2},
                        {4, 3, 7}, {3, 5, 8}, {2, 5, 9}, {4, 5, 10}};
    for (int k = 0; k < 9; k++) {
        dist[trechos[k][0]][trechos[k][1]] = trechos[k][2];
        dist[trechos[k][1]][trechos[k][0]] = trechos[k][2];
    }
    for (int origem = 0; origem < V; origem++) prim(origem);
    return 0;
}
