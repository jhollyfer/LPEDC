// 0153 · Prim: a árvore que cresce
// Exercício E914 · ★☆☆
//
// A prefeitura vai ligar seis estações de bicicleta compartilhada com
// ciclofaixa (distâncias em quarteirões). O heap de mínimo já está pronto.
// Complete o laço do Prim preguiçoso no main, nos três pontos marcados.
//
//   Saída esperada:
//   Rodoviária - Feira: 3
//   Rodoviária - Praça: 5
//   Praça - Museu: 4
//   Museu - Orla: 2
//   Orla - Estádio: 8
//   Ciclofaixa total: 22 quarteirões
//
// Dicas:
// 1. O item tirado do heap pode ser velho: se na_rede[it.v] já é true,
//    continue sem fazer nada.
// 2. Senão: na_rede[it.v] = true, total += it.chave e, se it.de >= 0,
//    mostre "de - v: chave". Depois, para cada w fora da rede com
//    dist[it.v][w] != 0, insere((Item){dist[it.v][w], w, it.v}).
// 3. Resposta esperada: a saída acima. A Praça entra pela Rodoviária (5), e
//    não pela Feira (6).
//
// Escreva sua resposta abaixo (complete o laço do main):

#include <stdbool.h>
#include <stdio.h>

#define V 6
#define CAP 40

typedef struct {
    int chave, v, de;
} Item;

Item heap[CAP];
int n = 0;

void troca(int i, int j) {
    Item t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}

void insere(Item x) {
    int i = n++;
    heap[i] = x;
    while (i > 0 && heap[(i - 1) / 2].chave > heap[i].chave) {
        troca(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

Item tira(void) {
    Item menor = heap[0];
    heap[0] = heap[--n];
    int i = 0;
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && heap[f + 1].chave < heap[f].chave) f++;
        if (heap[i].chave <= heap[f].chave) break;
        troca(i, f);
        i = f;
    }
    return menor;
}

int main(void) {
    const char *estacoes[V] = {"Rodoviária", "Praça", "Museu", "Orla", "Feira", "Estádio"};
    int dist[V][V] = {0};
    int trechos[][3] = {{0, 1, 5}, {0, 4, 3}, {1, 2, 4}, {1, 4, 6}, {2, 3, 2},
                        {4, 3, 7}, {3, 5, 8}, {2, 5, 9}, {4, 5, 10}};
    for (int k = 0; k < 9; k++) {
        dist[trechos[k][0]][trechos[k][1]] = trechos[k][2];
        dist[trechos[k][1]][trechos[k][0]] = trechos[k][2];
    }

    bool na_rede[V] = {false};
    int total = 0;
    insere((Item){0, 0, -1});
    while (n > 0) {
        Item it = tira();
        // 1) item velho? descarte
        // 2) it.v entra na rede: marque, some e mostre
        // 3) os vizinhos de it.v fora da rede entram no heap
        (void)it; // apague estas quatro linhas
        (void)estacoes;
        (void)na_rede;
        (void)dist;
    }
    printf("Ciclofaixa total: %d quarteirões\n", total);
    return 0;
}
