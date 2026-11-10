// Lista · Módulo 12 · Pilhas e filas
// Exercício P1214 · ★★☆ · O jogo das cartas nas pontas
//
// As cartas 3, 9, 1, 2, 7 e 5 estão enfileiradas na mesa. Ana e Beto jogam
// alternados, Ana primeiro: na sua vez, cada um pega a carta de UMA DAS
// PONTAS, sempre a maior das duas (no empate, a da esquerda). Ponha as
// cartas num deque de int sobre vetor circular e simule com primeiro,
// ultimo, retira_inicio e retira_fim. Mostre cada jogada e os totais.
//
//   Saída esperada:
//   Ana pega 5 (direita)
//   Beto pega 7 (direita)
//   Ana pega 3 (esquerda)
//   Beto pega 9 (esquerda)
//   Ana pega 2 (direita)
//   Beto pega 1 (esquerda)
//   Ana: 10 pontos, Beto: 17 pontos
//
// Dicas:
// 1. primeiro(d) é v[inicio] e ultimo(d) é v[(inicio + n - 1) % CAP];
//    as duas só olham, sem tirar.
// 2. Use int vez = 0 e troque com vez = 1 - vez a cada jogada.
// 3. Pegar sempre a maior ponta NÃO é a melhor estratégia: Ana
//    perdeu porque, ao pegar o 3, deixou o 9 para o Beto. (A estratégia
//    ótima é assunto de programação dinâmica.)
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define CAP 16

typedef struct {
    int v[CAP];
    int inicio, n;
} Deque;

int main(void) {

    return 0;
}
