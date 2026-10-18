// 0124 · Juntando tudo
// Exercício E744 · ★★★
//
// A pergunta do texto: nenhum Pix passa de R$ 9999,99, então o byte 3 de
// todos os valores é zero, e a quarta passada do radix copia 12 MB à toa.
// Escreva int radix_esperto(Pix v[], Pix aux[], int n), um radix em base
// 256 pelo valor que, em cada passada, conta os bytes e, se TODOS caírem no
// mesmo balde (algum c[x] == n), pula a passada. Devolva quantas passadas
// fez. O programa compara com o pix_por_valor (os ids têm que sair na mesma
// ordem, porque os dois são estáveis) em dois casos.
//
//   Saída esperada:
//   valores do dia:      3 passadas de 4, igual ao pix_por_valor? sim
//   valores até R$ 2,55: 1 passada de 4, igual ao pix_por_valor? sim
//
// Dicas:
// 1. Pular uma passada é seguro: se todo mundo tem o mesmo byte, um counting
//    sort estável por ele deixaria o vetor exatamente como está.
// 2. A contagem precisa vir antes da decisão: conte, confira, e só então
//    acumule e distribua.
// 3. Use dois ponteiros, origem e destino, e troque os dois depois de cada
//    passada feita. Com um número ímpar de passadas (3 ou 1), o resultado
//    termina no aux: copie de volta com memcpy.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (escreva radix_esperto):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pix.h"

#define N 1000000

// radix pelo valor que pula as passadas inúteis. Devolve quantas fez
int radix_esperto(Pix v[], Pix aux[], int n) {
    (void) v; // apague estas três linhas e escreva a função
    (void) aux;
    (void) n;
    return 0;
}

bool mesmos_ids(const Pix a[], const Pix b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i].id != b[i].id) {
            return false;
        }
    }
    return true;
}

void testa(const char *nome, Pix a[], Pix b[], Pix aux[], int n) {
    memcpy(b, a, n * sizeof(Pix));
    int feitas = radix_esperto(a, aux, n);
    pix_por_valor(b, aux, n);
    printf("%s %d passada%s de 4, igual ao pix_por_valor? %s\n", nome, feitas,
           feitas == 1 ? "" : "s", mesmos_ids(a, b, n) ? "sim" : "não");
}

int main(void) {
    Pix *a = malloc(N * sizeof(Pix));
    Pix *b = malloc(N * sizeof(Pix));
    Pix *aux = malloc(N * sizeof(Pix));
    if (a == NULL || b == NULL || aux == NULL) {
        free(a);
        free(b);
        free(aux);
        return 1;
    }
    pix_gera(a, N, 2024);
    testa("valores do dia:     ", a, b, aux, N);

    pix_gera(a, N, 2024);
    for (int i = 0; i < N; i++) {
        a[i].centavos %= 256;   // só até R$ 2,55: cabe num byte
    }
    testa("valores até R$ 2,55:", a, b, aux, N);
    free(a);
    free(b);
    free(aux);
    return 0;
}
