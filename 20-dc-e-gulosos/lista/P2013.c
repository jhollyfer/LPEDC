// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2013 · ★★☆ · A mediana sem ordenar tudo
//
// Na fila do banco, o gerente cronometrou o atendimento de 11 clientes, em
// minutos: 7 15 3 22 9 4 18 11 6 13 2. Ele quer a MEDIANA (o 6º menor) sem
// ordenar o vetor inteiro. O SELECT pela partição do quicksort faz isso:
// particione em volta de um pivô; se o pivô caiu na posição k, achou; se
// k está à esquerda, continue só na esquerda; senão, só na direita. Uma
// metade só, a cada passo. Complete seleciona(v, ini, fim, k), usando a
// particao (Lomuto, pivô = último) que já está no programa.
//
//   Saída esperada:
//    6º menor: 9 (partições: 3)
//    1º menor: 2 (partições: 1)
//   11º menor: 22 (partições: 5)
//
// Dicas:
// 1. int p = particao(v, ini, fim); if (p == k) return v[p];
// 2. Se k < p, chame para (ini, p - 1); senão, para (p + 1, fim). k é o
//    índice no vetor inteiro, não muda.
// 3. Resposta esperada: mediana 9; o 1º menor é 2 e o 11º é 22.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <string.h>

#define N 11

int particoes = 0;

int particao(int v[], int ini, int fim) {
    particoes++;
    int piv = v[fim], i = ini;
    for (int j = ini; j < fim; j++) {
        if (v[j] < piv) {
            int t = v[i];
            v[i] = v[j];
            v[j] = t;
            i++;
        }
    }
    int t = v[i];
    v[i] = v[fim];
    v[fim] = t;
    return i;
}

int seleciona(int v[], int ini, int fim, int k) {
    (void)v;
    (void)ini;
    (void)fim;
    (void)k;
    // COMPLETE AQUI
    return 0;
}

int main(void) {
    const int orig[N] = {7, 15, 3, 22, 9, 4, 18, 11, 6, 13, 2};
    const int ks[3] = {5, 0, 10};
    for (int i = 0; i < 3; i++) {
        int v[N];
        memcpy(v, orig, sizeof v);
        particoes = 0;
        int r = seleciona(v, 0, N - 1, ks[i]);
        printf("%2dº menor: %d (partições: %d)\n", ks[i] + 1, r, particoes);
    }
    return 0;
}
