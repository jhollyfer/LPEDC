// 0153 · Prim: a árvore que cresce
// Exercício E918 · ★★★
//
// Ache o bug. Uma rádio comunitária vai ligar a Torre a cinco pontos com
// cabo, gastando o mínimo de km. O Prim com heap abaixo tem um erro de
// lógica: ele marca o vértice como "na rede" no momento em que o coloca no
// heap, e não quando o tira. O total sai quase o dobro do mínimo:
//
//   Saída que aparece:
//   Torre - Escola: 3 km
//   Torre - Igreja: 7 km
//   Igreja - Mercado: 4 km
//   Mercado - Clube: 6 km
//   Torre - Posto: 9 km
//   Total: 29 km
//
//   Saída esperada:
//   Torre - Escola: 3 km
//   Escola - Igreja: 2 km
//   Igreja - Mercado: 4 km
//   Mercado - Posto: 1 km
//   Posto - Clube: 5 km
//   Total: 15 km
//
// Conserte o programa e confira a saída.
//
// Dicas:
// 1. Quando a Torre entra, Igreja (7), Escola (3) e Posto (9) vão para o
//    heap e já ficam marcadas. Depois a Escola descobre um cano de 2 km até
//    a Igreja, mas a Igreja "já está na rede" e o cano melhor é ignorado.
// 2. Estar no heap é só ter um candidato. Marque na_rede[it.v] quando o
//    item SAI do heap e, nessa hora, descarte o item se o vértice já
//    estiver marcado (item velho).
// 3. Resposta esperada: tire as duas marcações (a da Torre antes do laço e
//    a do laço dos vizinhos); depois de "Item it = tira();", ponha
//    "if (na_rede[it.v]) continue; na_rede[it.v] = true;". Consertado,
//    mostra a saída esperada.
//
// Escreva sua resposta abaixo (conserte o código):

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
    const char *nomes[V] = {"Torre", "Igreja", "Escola", "Mercado", "Posto", "Clube"};
    int km[V][V] = {0};
    int trechos[][3] = {{0, 1, 7}, {0, 2, 3}, {1, 2, 2}, {1, 3, 4}, {2, 4, 8},
                        {3, 4, 1}, {3, 5, 6}, {4, 5, 5}, {0, 4, 9}};
    for (int k = 0; k < 9; k++) {
        km[trechos[k][0]][trechos[k][1]] = trechos[k][2];
        km[trechos[k][1]][trechos[k][0]] = trechos[k][2];
    }

    bool na_rede[V] = {false};
    int total = 0;
    insere((Item){0, 0, -1});
    na_rede[0] = true;
    while (n > 0) {
        Item it = tira();
        total += it.chave;
        if (it.de >= 0) printf("%s - %s: %d km\n", nomes[it.de], nomes[it.v], it.chave);
        for (int w = 0; w < V; w++)
            if (km[it.v][w] && !na_rede[w]) {
                na_rede[w] = true; // já conta como ligado
                insere((Item){km[it.v][w], w, it.v});
            }
    }
    printf("Total: %d km\n", total);
    return 0;
}
