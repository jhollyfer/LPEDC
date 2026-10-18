// 0140 · Mochila 0/1
// Exercício E836 · ★☆☆
//
// Você vai fazer uma trilha de dois dias e a mochila aguenta 9 kg. O
// programa abaixo já monta a tabela da mochila 0/1 com a "importância" de
// cada item e mostra o valor máximo. Falta a RECUPERAÇÃO: complete o trecho
// marcado com COMPLETE AQUI para mostrar quais itens levar (do último item
// para o primeiro, como sai naturalmente da volta pela tabela) e o peso
// total usado.
//
//   Saída esperada:
//   Valor máximo: 32
//   Leva:
//     câmera (1 kg)
//     comida (3 kg)
//     fogareiro (3 kg)
//     saco de dormir (2 kg)
//   Peso usado: 9 kg
//
// Dicas:
// 1. Comece com c = W e ande com i de N até 1.
// 2. Se t[i][c] != t[i - 1][c], o item i entrou: mostre, desconte o peso de
//    c e some ao peso total.
// 3. A barraca é o item mais "importante" sozinho (12), mas fica de fora: os
//    4 kg dela rendem mais em outros itens.
// 4. Resposta esperada: a saída acima (5 + 10 + 9 + 8 = 32).
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define N 5
#define W 9

int main(void) {
    const char *nome[N + 1] = {"", "barraca", "saco de dormir", "fogareiro",
                               "comida", "câmera"};
    int peso[N + 1] = {0, 4, 2, 3, 3, 1};
    int valor[N + 1] = {0, 12, 8, 9, 10, 5};
    int t[N + 1][W + 1];

    for (int c = 0; c <= W; c++) {
        t[0][c] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int c = 0; c <= W; c++) {
            t[i][c] = t[i - 1][c];
            if (peso[i] <= c && valor[i] + t[i - 1][c - peso[i]] > t[i][c]) {
                t[i][c] = valor[i] + t[i - 1][c - peso[i]];
            }
        }
    }
    printf("Valor máximo: %d\n", t[N][W]);

    int c = W, peso_total = 0;
    printf("Leva:\n");
    // COMPLETE AQUI: volte pela tabela, mostrando "  nome (peso kg)" de cada
    // item que entrou, e atualize c e peso_total

    printf("Peso usado: %d kg\n", peso_total);
    (void) c;    // tire estas duas linhas quando usar
    (void) nome; // o c e o nome na recuperação
    return 0;
}
