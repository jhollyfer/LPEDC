// 0132 · Inversões e subvetor de soma máxima
// Exercício E790 · ★★☆
//
// O insertion sort (assunto 0093) desloca um elemento para a direita a cada
// vez que acha alguém maior antes do valor que está inserindo. Cada
// deslocamento desfaz exatamente uma inversão. Então o número de
// deslocamentos do insertion sort É o número de inversões do vetor.
//
// Confira isso no computador. Escreva:
// - long long insercao(int v[], int n): insertion sort que devolve quantos
//   deslocamentos fez;
// - o merge sort que conta inversões, do texto (sem os printf).
// Rode os dois, cada um na sua cópia do vetor (use memcpy), com os pesos
// de 12 encomendas, em kg:
//
//   31 12 45 27 8 39 19 50 4 23 36 15
//
//   Saída esperada:
//   Deslocamentos do insertion sort: 36
//   Inversões pelo merge sort: 36
//
// Dicas:
// 1. memcpy(a, pesos, sizeof pesos) copia o vetor inteiro de uma vez
//    (string.h). Sem a cópia, o segundo algoritmo receberia o vetor já
//    ordenado e contaria 0.
// 2. No insertion sort, conte dentro do while que faz v[j + 1] = v[j].
// 3. Resposta esperada: a saída acima. Daí sai uma conclusão de custo: o
//    insertion sort gasta O(n + inversões). Vetor quase ordenado, poucas
//    inversões, insertion sort rápido.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    int pesos[] = {31, 12, 45, 27, 8, 39, 19, 50, 4, 23, 36, 15};
    (void)pesos;

    return 0;
}
