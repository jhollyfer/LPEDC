// 0061 · Vetor de structs
// Exercício E365 · ★★★
//
// Este programa compila e roda, mas o ranking não sai em ordem de pontos,
// embora o bubble sort pareça certo. Rode, compare com a saída esperada, ache
// o bug e conserte (de preferência, deixando o código menor).
//
//   Saída esperada (depois de consertado):
//   1. Lia - 950 pontos, nível 12
//   2. Bento - 720 pontos, nível 9
//   3. Teo - 410 pontos, nível 5
//
// Dicas:
// 1. Olhe a troca dentro do laço: quais campos ela troca?
// 2. Uma struct inteira pode ser copiada com =.
// 3. Resposta esperada: a troca movia só o nome (com strcpy) e deixava pontos e
//    nível no lugar. Os nomes trocavam de dono e a comparação seguinte olhava
//    números que nunca andaram. Troque a struct inteira: Jogador tmp = v[j];
//    v[j] = v[j + 1]; v[j + 1] = tmp;
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

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

    // bubble sort: maior pontuação primeiro
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j].pontos < v[j + 1].pontos) {
                char tmp[20];
                strcpy(tmp, v[j].nome);
                strcpy(v[j].nome, v[j + 1].nome);
                strcpy(v[j + 1].nome, tmp);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d. %s - %d pontos, nível %d\n", i + 1, v[i].nome, v[i].pontos, v[i].nivel);
    }
    return 0;
}
