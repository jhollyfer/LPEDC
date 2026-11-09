// Lista · Módulo 12 · Pilhas e filas
// Exercício P1202 · ★☆☆ · Os índices da fila circular, passo a passo
//
// A fila do ponto de ônibus cabe num vetor de 5 posições usado em círculo,
// com três campos: inicio (quem sai primeiro), fim (a próxima vaga) e n
// (quantos estão na fila). Escreva insere e retira (devolvendo false quando
// a fila está cheia ou vazia) e uma função que mostra o estado. Faça, nesta
// ordem, mostrando o estado depois de cada uma: insere 10, 20 e 30; retira
// duas vezes; insere 40, 50, 60 e 70; insere 80.
//
//   Saída esperada:
//   insere 10: inicio=0 fim=1 n=1
//   insere 20: inicio=0 fim=2 n=2
//   insere 30: inicio=0 fim=3 n=3
//   retira 10: inicio=1 fim=3 n=2
//   retira 20: inicio=2 fim=3 n=1
//   insere 40: inicio=2 fim=4 n=2
//   insere 50: inicio=2 fim=0 n=3
//   insere 60: inicio=2 fim=1 n=4
//   insere 70: inicio=2 fim=2 n=5
//   insere 80: fila cheia
//
// Dicas:
// 1. insere: v[fim] = x; fim = (fim + 1) % CAP; n++. retira: x =
//    v[inicio]; inicio = (inicio + 1) % CAP; n--.
// 2. Com n você distingue cheia (n == CAP) de vazia (n == 0), mesmo quando
//    inicio == fim nos dois casos.
// 3. Repare em "insere 50": o fim deu a volta e foi para 0. E em
//    "insere 70": inicio == fim == 2 com a fila cheia.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define CAP 5

typedef struct {
    int v[CAP];
    int inicio, fim, n;
} Fila;

int main(void) {

    return 0;
}
