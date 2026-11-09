// Lista · Módulo 25 · Estruturas especiais
// Exercício P2504 · ★☆☆ · As horas extras do mês
//
// A empresa registra as horas extras de 5 funcionários nos 30 dias do mês,
// mas quase ninguém faz hora extra. Escreva do zero uma matriz esparsa com
// uma lista encadeada por funcionário (em ordem de dia):
// - define(f, dia, horas): se a célula do dia já existe, troca as horas;
//   senão, cria a célula no lugar certo da lista;
// - o main faz os lançamentos abaixo, mostra cada funcionário com os dias
//   e o total, conta as células e libera tudo.
//
//   Lançamentos (funcionário, dia, horas):
//   (0, 12, 2) (3, 5, 1) (0, 3, 3) (2, 28, 4) (0, 20, 1) (3, 5, 2)
//   (4, 9, 2) (4, 1, 1) (0, 12, 3)
//
//   Saída esperada:
//   Ana    dia 3: 3h; dia 12: 3h; dia 20: 1h; total 7h
//   Bruno  total 0h
//   Carla  dia 28: 4h; total 4h
//   Diego  dia 5: 2h; total 2h
//   Elisa  dia 1: 1h; dia 9: 2h; total 3h
//   Células: 7 de 150
//
// Dicas:
// 1. Com um ponteiro para ponteiro (Celula **p = &linha[f]) você anda até
//    o lugar e insere sem tratar o começo da lista à parte.
// 2. Os lançamentos (0, 12) e (3, 5) aparecem duas vezes: vale o último,
//    e a célula não é duplicada.
// 3. Resposta esperada: Ana com 7h, Bruno sem nada; 7 células de 150.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *nomes[5] = {"Ana", "Bruno", "Carla", "Diego", "Elisa"};
    printf("%s\n", nomes[0]);
    return 0;
}
