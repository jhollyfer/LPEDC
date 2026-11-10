// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1911 · ★★☆ · Pintando o mapa do Norte
//
// O professor de geografia quer pintar os 7 estados da região Norte com
// só 3 cores (verde, amarelo e azul) de modo que estados com fronteira
// nunca tenham a mesma cor. As fronteiras estão na matriz viz do programa
// (sem contar o Mato Grosso e os outros vizinhos de fora da região). Este é
// o problema da COLORAÇÃO DE GRAFO. Escreva pinta(e): tente cada cor no
// estado e, pule a cor se um vizinho já pintado tem a mesma, desça para
// e + 1 e desfaça. Guarde a primeira coloração achada e conte todas.
//
//   Saída esperada:
//   Primeira coloração:
//     AC: verde
//     AM: amarelo
//     RR: verde
//     RO: azul
//     PA: azul
//     AP: verde
//     TO: verde
//   Colorações com 3 cores: 48
//
// Dicas:
// 1. pode(e, c): para todo v < e com viz[e][v] == 1, cor[v] != c. Os
//    estados acima de e ainda não têm cor.
// 2. Quando e == N, some 1 no total; se for a primeira, copie cor[] para
//    primeira[].
// 3. Resposta esperada: a primeira coloração é a de cima e há 48 jeitos
//    de pintar. O 48 é múltiplo de 3! = 6: trocar as cores entre si
//    sempre dá outra coloração válida.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define N 7
#define CORES 3

const char *uf[N] = {"AC", "AM", "RR", "RO", "PA", "AP", "TO"};
const char *nome_cor[CORES] = {"verde", "amarelo", "azul"};
const int viz[N][N] = {
    // AC AM RR RO PA AP TO
    {0, 1, 0, 1, 0, 0, 0}, // AC
    {1, 0, 1, 1, 1, 0, 0}, // AM
    {0, 1, 0, 0, 1, 0, 0}, // RR
    {1, 1, 0, 0, 0, 0, 0}, // RO
    {0, 1, 1, 0, 0, 1, 1}, // PA
    {0, 0, 0, 0, 1, 0, 0}, // AP
    {0, 0, 0, 0, 1, 0, 0}, // TO
};
int cor[N], primeira[N];
int total = 0;

void pinta(int e) {
    (void)e;
    // COMPLETE AQUI (e escreva a função pode, se quiser)
}

int main(void) {
    for (int i = 0; i < N; i++) {
        cor[i] = -1;
    }
    pinta(0);
    printf("Primeira coloração:\n");
    for (int i = 0; i < N; i++) {
        printf("  %s: %s\n", uf[i], nome_cor[primeira[i]]);
    }
    printf("Colorações com 3 cores: %d\n", total);
    return 0;
}
