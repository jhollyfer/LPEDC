// 0076 · Eficiência: contar passos
// Exercício E451 · ★☆☆
//
// Antes de rodar, preveja quantos passos cada trecho conta. Anote os quatro
// números, depois rode e confira.
//
//   a) for (i = 0; i < 6; i++)  for (j = 0; j < 4; j++)  passos++;
//   b) for (i = 0; i < 6; i++)  for (j = i; j < 6; j++)  passos++;
//   c) for (i = 1; i < 100; i = i * 2)  passos++;
//   d) for (i = 0; i < 10; i++)  if (i % 3 == 0) passos++;
//
// Dicas:
// 1. Em a), o laço de dentro roda inteiro a cada volta do de fora.
// 2. Em b), o laço de dentro encolhe: começa em i. Faça a lista 6 + 5 + ...
// 3. Em c), escreva os valores de i: 1, 2, 4, ... até passar de 99.
// 4. Resposta esperada: a) 24; b) 21 (6 + 5 + 4 + 3 + 2 + 1); c) 7
//    (i = 1, 2, 4, 8, 16, 32, 64); d) 4 (i = 0, 3, 6, 9).
//
// Escreva sua resposta abaixo (as previsões como comentário):

#include <stdio.h>

int main(void) {
    int passos;

    passos = 0;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++)
            passos++;
    printf("a) %d\n", passos);

    passos = 0;
    for (int i = 0; i < 6; i++)
        for (int j = i; j < 6; j++)
            passos++;
    printf("b) %d\n", passos);

    passos = 0;
    for (int i = 1; i < 100; i = i * 2)
        passos++;
    printf("c) %d\n", passos);

    passos = 0;
    for (int i = 0; i < 10; i++)
        if (i % 3 == 0)
            passos++;
    printf("d) %d\n", passos);
    return 0;
}
