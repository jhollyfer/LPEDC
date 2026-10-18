// 0066 · Vetor de structs
// Exercício E395 · ★★★
//
// Resposta: a troca movia só o nome; pontos e nível ficavam no lugar. Trocar
// a struct inteira resolve e ainda dispensa o strcpy.

#include <stdio.h>

typedef struct {
    char nome[20];
    int pontos;
    int nivel;
} Jogador;

int main(void) {
    Jogador v[] = {
        {"Teo", 410, 5},
        {"Lia", 950, 12},
        {"Bento", 720, 9},
    };
    int n = sizeof v / sizeof v[0];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j].pontos < v[j + 1].pontos) {
                Jogador tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d. %s - %d pontos, nível %d\n", i + 1, v[i].nome, v[i].pontos, v[i].nivel);
    }
    return 0;
}
