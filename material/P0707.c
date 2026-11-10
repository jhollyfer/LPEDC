// Lista · Módulo 07 · Memória dinâmica
// Exercício P0707 · ★☆☆ · Faixas de idade do tamanho certo
//
// A campanha de vacinação registrou as idades abaixo e quer contar quantas
// pessoas há em cada faixa de 10 anos (0-9, 10-19, ...). O número de faixas
// depende da maior idade, então o vetor de contadores é criado com calloc
// DEPOIS de achar a maior:
//
//   int idades[12] = {67, 8, 34, 71, 15, 42, 88, 3, 59, 64, 27, 80};
//
// Mostre quantas faixas foram criadas e a contagem de cada uma (inclusive as
// vazias), e libere o vetor:
//
//   Saída esperada:
//   9 faixas
//    0- 9: 2
//   10-19: 1
//   20-29: 1
//   30-39: 1
//   40-49: 1
//   50-59: 1
//   60-69: 2
//   70-79: 1
//   80-89: 2
//
// Dicas:
// 1. faixas = maior / 10 + 1. Com maior 88, são 9 faixas (0-9 até 80-89).
// 2. int *cont = calloc(faixas, sizeof *cont); o calloc zera, então dá
//    para fazer cont[idades[i] / 10]++ direto.
// 3. Com malloc, os contadores começariam com lixo.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int idades[12] = {67, 8, 34, 71, 15, 42, 88, 3, 59, 64, 27, 80};
    (void) idades; // apague esta linha quando escrever

    return 0;
}
