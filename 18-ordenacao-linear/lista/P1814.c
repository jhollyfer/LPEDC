// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1814 · ★★☆ · Mediana: quickselect contra ordenar tudo
//
// Para achar a mediana do tempo de espera de 1001 pacientes de uma UBS, não
// é preciso ordenar: o quickselect acha o elemento de posição 500 (a partir
// de 0) em tempo médio Θ(n). Confira contando comparações.
//
// Escreva o quickselect (Lomuto, pivô no último) e um merge sort, os dois
// contando comparações entre elementos, e mostre a mediana e as comparações
// de cada um em dois vetores:
//
// - os tempos sorteados do esqueleto;
// - os mesmos tempos JÁ ORDENADOS (o pior caso do pivô no último).
//
//   Saída esperada:
//   sorteado:
//     quickselect: mediana 118,   5351 comparações
//     merge sort:  mediana 118,   8693 comparações
//   ordenado:
//     quickselect: mediana 118,  90220 comparações
//     merge sort:  mediana 118,   5049 comparações
//
// Dicas:
// 1. Quickselect iterativo: particione [ini, fim]; se o pivô parou na posição
//    procurada, achou; senão continue só no lado que contém a posição.
// 2. Com o vetor ordenado, o pivô no último é sempre o maior do pedaço: cada
//    partição tira poucos elementos (os iguais ao pivô), e o quickselect
//    vira quadrático. O pivô sorteado (ou a mediana das medianas) evita isso.
// 3. O merge sort quase não liga para a ordem da entrada: ordenado ou não,
//    fica em Θ(n lg n).
// 4. Resposta esperada: a mesma mediana (118) nos quatro casos; no vetor
//    sorteado, o quickselect faz 5351 comparações contra 8693 do merge sort;
//    no ordenado, o quickselect sobe para 90220, e o merge sort cai para 5049.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define N 1001

unsigned semente = 13;

int sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente >> 16) % 240); // minutos de espera
}

int main(void) {
    int tempo[N];
    for (int i = 0; i < N; i++) tempo[i] = sorteia();

    printf("%d %d %d\n", tempo[0], tempo[1], tempo[2]);
    return 0;
}
