// Lista · Módulo 12 · Pilhas e filas
// Exercício P1229 · ★★★ · De quem é a vez no Uno?
//
// Ana, Bia, Caio e Davi jogam Uno, sentados nessa ordem em roda. A vez anda
// no sentido horário até alguém jogar "inverte" (a vez passa a andar no
// sentido contrário) ou "pula" (o próximo perde a vez). Guarde os jogadores
// num DEQUE (vetor circular de int, com os índices dos nomes) em que o da
// FRENTE é quem joga agora:
//
//   - andar no horário: tire da frente e ponha no fim;
//   - andar no anti-horário: tire do fim e ponha na frente.
//
// As cartas jogadas, uma por vez, são: normal, normal, inverte, normal,
// pula, normal, inverte, normal. Mostre cada jogada e de quem é a vez
// depois dela.
//
//   Saída esperada:
//   Ana joga normal; vez de Bia
//   Bia joga normal; vez de Caio
//   Caio joga inverte; vez de Bia
//   Bia joga normal; vez de Ana
//   Ana joga pula; vez de Caio
//   Caio joga normal; vez de Bia
//   Bia joga inverte; vez de Caio
//   Caio joga normal; vez de Davi
//
// Dicas:
// 1. Com o deque [Ana Bia Caio Davi] e a vez no horário, "andar" deixa
//    [Bia Caio Davi Ana]. No anti-horário, deixa [Davi Ana Bia Caio].
// 2. inverte: troque o sentido e ande uma vez (no sentido novo). pula: ande
//    duas vezes. normal: ande uma vez.
// 3. Por que um deque: no horário você mexe nas duas pontas de um jeito, no
//    anti-horário do outro. Uma fila só não dá conta do segundo caso.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define CAP 8

typedef struct {
    int v[CAP];
    int inicio, n;
} Deque;

int main(void) {

    return 0;
}
