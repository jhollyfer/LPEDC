// A244 · Baldes sem lista encadeada

#include <stdio.h>

#define NB 10 // faixas etárias: 0-9, 10-19, ..., 90-99

// insertion sort só no pedaço v[ini..fim-1]
void insertion(int v[], int ini, int fim) {
    for (int i = ini + 1; i < fim; i++) {
        int x = v[i];
        int j = i;
        while (j > ini && v[j - 1] > x) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = x;
    }
}

int main(void) {
    // idades dos voluntários da campanha do agasalho
    int idades[] = {34, 71, 19, 45, 38, 22, 67, 30, 18, 52, 41, 36, 25, 63, 33};
    int n = 15;
    int saida[15];

    // 1) conta quantos caem em cada balde e acha onde cada balde começa
    int comeco[NB + 1] = {0};
    for (int i = 0; i < n; i++) {
        comeco[idades[i] / 10 + 1]++;
    }
    for (int b = 1; b <= NB; b++) {
        comeco[b] += comeco[b - 1];   // balde b ocupa saida[comeco[b]..comeco[b+1]-1]
    }
    // 2) espalha: cada um vai para a próxima vaga livre do seu balde
    int vaga[NB];
    for (int b = 0; b < NB; b++) {
        vaga[b] = comeco[b];
    }
    for (int i = 0; i < n; i++) {
        int b = idades[i] / 10;
        saida[vaga[b]++] = idades[i];
    }
    // 3) ordena cada balde no lugar e mostra
    for (int b = 0; b < NB; b++) {
        insertion(saida, comeco[b], comeco[b + 1]);
        if (comeco[b + 1] > comeco[b]) {
            printf("%2d-%2d anos:", 10 * b, 10 * b + 9);
            for (int i = comeco[b]; i < comeco[b + 1]; i++) {
                printf(" %d", saida[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
// Saída:
// 10-19 anos: 18 19
// 20-29 anos: 22 25
// 30-39 anos: 30 33 34 36 38
// 40-49 anos: 41 45
// 50-59 anos: 52
// 60-69 anos: 63 67
// 70-79 anos: 71
//
// Nenhum malloc: a contagem diz de antemão o tamanho de cada balde, e os
// baldes viram pedaços vizinhos do mesmo vetor saida. É o counting sort do
// assunto 0120 com a chave "faixa" (idade / 10) no lugar da idade, seguido de
// um insertion sort em cada pedaço. O comeco[NB + 1] tem uma casa a mais
// para que comeco[b + 1] marque o fim do último balde.
