// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2020 · ★★☆ · A fila do cartório
//
// Seis pessoas chegaram juntas ao cartório e há um atendente só. Os
// serviços levam 12, 3, 8, 1, 20 e 5 minutos, na ordem de chegada. A
// espera de cada um é a soma das durações de quem foi atendido antes. O
// guloso que minimiza a ESPERA MÉDIA é atender primeiro o serviço mais
// curto. O programa abaixo já calcula a espera média na ordem de chegada.
// Estenda-o: ordene as durações (qsort) e mostre a nova ordem e a nova
// espera média.
//
//   Saída esperada:
//   Ordem de chegada: 12 3 8 1 20 5 -> espera média 19.67 min
//   Mais curto primeiro: 1 3 5 8 12 20 -> espera média 10.00 min
//
// Dicas:
// 1. Reaproveite a função espera_media, chamando-a de novo depois do qsort.
// 2. Por que o mais curto primeiro? O serviço na posição i (contando de 0)
//    entra na espera dos n - 1 - i que vêm depois: o mais curto deve ser o
//    que "pesa" mais vezes.
// 3. Resposta esperada: de 19.67 para 10.00 minutos.
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>
#include <stdlib.h>

#define N 6

double espera_media(const int d[]) {
    int espera = 0, total = 0;
    for (int i = 0; i < N; i++) {
        total += espera;
        espera += d[i];
    }
    return (double)total / N;
}

void mostra(const char *titulo, const int d[]) {
    printf("%s:", titulo);
    for (int i = 0; i < N; i++) {
        printf(" %d", d[i]);
    }
    printf(" -> espera média %.2f min\n", espera_media(d));
}

int main(void) {
    int d[N] = {12, 3, 8, 1, 20, 5};
    mostra("Ordem de chegada", d);
    return 0;
}
