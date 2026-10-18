// 0091 · Bubble sort
// Exercício E544 · ★★☆
//
// Monte a tabela do campeonato. Cada time é uma struct:
//
//   typedef struct { char nome[16]; int pontos; int vitorias; } Time;
//
//   {"Fortaleza", 68, 19}, {"Flamengo", 70, 20}, {"Botafogo", 79, 23},
//   {"Palmeiras", 70, 21}, {"Inter", 65, 18}
//
// Ordene com bubble sort: mais pontos primeiro; empatou nos pontos, mais
// vitórias primeiro. Escreva uma função bool vem_depois(const Time *a,
// const Time *b) com o critério e use-a no lugar do ">" do bubble.
//
//   Saída esperada:
//   1º Botafogo   79 pts 23 vit
//   2º Palmeiras  70 pts 21 vit
//   3º Flamengo   70 pts 20 vit
//   4º Fortaleza  68 pts 19 vit
//   5º Inter      65 pts 18 vit
//
// Dicas:
// 1. Primeiro compare os pontos; só se forem iguais, compare as vitórias.
// 2. Struct se copia inteira com =: Time aux = tabela[j]; funciona.
// 3. Para alinhar: printf("%dº %-10s %2d pts %2d vit\n", ...).
// 4. Resposta esperada: a saída acima (Palmeiras passa o Flamengo pelas
//    vitórias).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
