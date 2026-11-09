// Lista · Módulo 04 · Funções e modularização
// Exercício P0415 · ★★☆ · O app de treinos refatorado
//
// O programa abaixo mostra a duração de três treinos, mas repete a mesma conta
// três vezes. Refatore: escreva "int minutos(int hora, int minuto)", que
// converte um horário em minutos desde a meia-noite, e "void mostrar(int
// duracao)", que mostra a duração em h e min. O main deve ficar curto, e a
// saída tem que continuar a mesma:
//
//   Saída esperada:
//   Treino 1: 1 h 15 min
//   Treino 2: 0 h 50 min
//   Treino 3: 2 h 5 min
//   Total: 4 h 10 min
//
// Dicas:
// 1. A duração de um treino é minutos(fim) - minutos(início).
// 2. mostrar recebe a duração e faz o / 60 e o % 60.
// 3. Resposta esperada: a mesma saída do programa original.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int d1 = (7 * 60 + 45) - (6 * 60 + 30);
    printf("Treino 1: %d h %d min\n", d1 / 60, d1 % 60);

    int d2 = (19 * 60 + 10) - (18 * 60 + 20);
    printf("Treino 2: %d h %d min\n", d2 / 60, d2 % 60);

    int d3 = (10 * 60 + 5) - (8 * 60 + 0);
    printf("Treino 3: %d h %d min\n", d3 / 60, d3 % 60);

    int total = d1 + d2 + d3;
    printf("Total: %d h %d min\n", total / 60, total % 60);
    return 0;
}
