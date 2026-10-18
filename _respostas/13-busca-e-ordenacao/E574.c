// 0096 · Bubble sort
// Exercício E574 · ★★☆

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char nome[16];
    int pontos;
    int vitorias;
} Time;

// a vem DEPOIS de b na tabela?
bool vem_depois(const Time *a, const Time *b) {
    if (a->pontos != b->pontos) {
        return a->pontos < b->pontos;   // menos pontos: mais para baixo
    }
    return a->vitorias < b->vitorias;   // empate: menos vitórias desce
}

int main(void) {
    Time tabela[] = {
        {"Fortaleza", 68, 19},
        {"Flamengo", 70, 20},
        {"Botafogo", 79, 23},
        {"Palmeiras", 70, 21},
        {"Inter", 65, 18},
    };
    int n = 5;

    for (int passada = 1; passada < n; passada++) {
        bool trocou = false;
        for (int j = 0; j < n - passada; j++) {
            if (vem_depois(&tabela[j], &tabela[j + 1])) {
                Time aux = tabela[j];           // struct se copia inteira com =
                tabela[j] = tabela[j + 1];
                tabela[j + 1] = aux;
                trocou = true;
            }
        }
        if (!trocou) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%dº %-10s %2d pts %2d vit\n", i + 1, tabela[i].nome,
               tabela[i].pontos, tabela[i].vitorias);
    }
    return 0;
}
