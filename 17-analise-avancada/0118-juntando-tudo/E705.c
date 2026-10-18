// 0118 · Juntando tudo
// Exercício E705 · ★★☆
//
// O cadastro de 10 mil clientes da loja fica em ordem de código, mas todo
// dia umas poucas alterações bagunçam alguns vizinhos. Qual das quatro
// ordenações do ordena.h é a melhor para reordenar esse vetor QUASE
// ordenado? Escreva o programa:
//
// - monte base[i] = i para i de 0 a 9999;
// - faça 50 trocas de vizinhos: sorteie i = sorteia() % (N - 1) e troque
// base[i] com base[i + 1];
// - para cada algoritmo, copie base para v, zere a contagem, ordene, e
// mostre as comparações (confira com ord_confere que ordenou);
// - no fim, diga qual comparou menos.
//
//   Saída esperada:
//   insertion   10049 comparações
//   merge       64644 comparações
//   heap       244460 comparações
//   quick      113650 comparações
//   vencedor: insertion
//
// Dicas:
// 1. Guarde as funções num vetor de ponteiros para função:
//    void (*ordena[])(int[], int) = {ord_insertion, ord_merge, ...};
// 2. Vetores de 10 mil int dentro do main ocupam 40 KB cada: funciona,
//    mas static int base[N], v[N]; os tira da pilha.
// 3. Use o sorteia() já escrito, sem mudar a semente, para dar os mesmos
//    números da saída esperada.
// 4. Resposta esperada: a saída acima. O insertion faz n - 1 comparações
//    mais uma por inversão: Θ(n) num vetor quase ordenado. O pior caso
//    Θ(n²) não conta a história toda; o heapsort, ótimo no pior caso, é o
//    pior aqui.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include "ordena.h"

#define N 10000

unsigned semente = 3;
int sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return (int)(semente >> 8);
}

int main(void) {

    return 0;
}
