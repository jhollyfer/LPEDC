// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1810 · ★☆☆ · Conserte o counting sort das notas
//
// Conserte o programa. Ele ordena as notas (inteiras, de 0 a 10) de 12 alunos
// com counting sort, mas tem DOIS erros de propósito, e os dois são de
// índice. Rode com ./rodar: o AddressSanitizer acusa leitura e escrita fora
// do vetor c (stack-buffer-overflow). Ache os dois, conserte e confira a
// saída:
//
//   Saída esperada:
//   0 3 4 5 5 6 7 7 8 9 10 10
//
// Dicas:
// 1. Se as notas vão de 0 a K, quantas posições o vetor de contagem precisa
//    ter? Um vetor int c[K] tem as posições 0 a K - 1.
// 2. Olhe o laço das somas acumuladas: na primeira volta, que posição ele
//    lê?
// 3. Os dois erros são clássicos de "fora por um". Em C, nada impede o
//    acesso fora do vetor: só o sanitizer (ou um resultado esquisito) avisa.
// 4. Resposta esperada: 0 3 4 5 5 6 7 7 8 9 10 10.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 12
#define K 10 // notas de 0 a K

int main(void) {
    int nota[N] = {7, 10, 3, 5, 8, 0, 10, 6, 4, 7, 9, 5};
    int saida[N], c[K] = {0};

    for (int i = 0; i < N; i++) c[nota[i]]++;
    for (int x = 0; x <= K; x++) c[x] += c[x - 1];
    for (int i = N - 1; i >= 0; i--) saida[--c[nota[i]]] = nota[i];

    for (int i = 0; i < N; i++) printf("%s%d", i ? " " : "", saida[i]);
    printf("\n");
    return 0;
}
