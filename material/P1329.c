// Lista · Módulo 13 · Busca e ordenação
// Exercício P1329 · ★★★ · Que algoritmo deixou o vetor assim?
//
// Questão típica de prova: "o vetor 31 8 22 15 4 27 12 está sendo ordenado e,
// num certo momento, está assim. Qual algoritmo, e em que passo?". Escreva um
// programa que responde sozinho.
//
// Escreva três funções que ordenam uma CÓPIA de orig e guardam o vetor depois
// de cada passo em estados[k] (k = 0 é o passo 1), devolvendo quantos passos
// deram:
//
//   int bubble(const int orig[], int estados[][N])     passo = uma passada
//                                                      (sem parada antecipada)
//   int selection(const int orig[], int estados[][N])  passo = uma passada i
//   int insertion(const int orig[], int estados[][N])  passo = um encaixe j
//
// Depois, para cada pista, procure em qual algoritmo e passo ela aparece
// (pegue o primeiro passo de cada algoritmo que bate). Se nenhum bater,
// escreva "nenhum dos três".
//
//   Pistas:
//   4 8 12 15 31 27 22
//   8 15 22 31 4 27 12
//   8 15 4 22 12 27 31
//   8 22 4 15 27 31 12
//
//   Saída esperada:
//   pista 1: selection após o passo 3
//   pista 2: insertion após o passo 3
//   pista 3: bubble após o passo 2
//   pista 4: nenhum dos três
//
// Dicas:
// 1. Use #define N 7. Um vetor int estados[N][N] cabe todos os passos.
// 2. Assinaturas iguais deixam você pôr as três funções num vetor:
//    int (*alg[])(const int[], int[][N]) = {bubble, selection, insertion};
// 3. Para resolver de cabeça na prova: o selection deixa os k MENORES no
//    começo, o bubble deixa os k MAIORES no fim, o insertion deixa os k + 1
//    PRIMEIROS ordenados entre si (e o resto intacto).
// 4. A pista 4 parece bubble (31 no fim?), mas o 31 não está no fim.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

#define N 7

int main(void) {
    int orig[N] = {31, 8, 22, 15, 4, 27, 12};
    int pistas[][N] = {
        {4, 8, 12, 15, 31, 27, 22},
        {8, 15, 22, 31, 4, 27, 12},
        {8, 15, 4, 22, 12, 27, 31},
        {8, 22, 4, 15, 27, 31, 12},
    };
    (void)orig;
    (void)pistas;

    return 0;
}
