// 0151 · Ordenação topológica
// Exercício E906 · ★★★
//
// Quantas ordens diferentes existem para a rotina da manhã? As tarefas são
// café, banho, vestir, escovar e sair (índices 0 a 4), com as regras:
//
//   banho -> vestir   café -> escovar   vestir -> sair   escovar -> sair
//
// Escreva conta(): ela gera TODAS as ordenações topológicas com
// backtracking (assunto 0127), mostra cada uma quando mostrar é true e
// devolve quantas são. Depois o main acrescenta uma sexta tarefa, ler as
// mensagens (antes de sair), e pede só o total.
//
//   Saída esperada:
//   café, banho, vestir, escovar, sair
//   café, banho, escovar, vestir, sair
//   café, escovar, banho, vestir, sair
//   banho, café, vestir, escovar, sair
//   banho, café, escovar, vestir, sair
//   banho, vestir, café, escovar, sair
//   Total com 5 tarefas: 6
//   Total com 6 tarefas: 30
//
// Escreva sua resposta abaixo (escreva conta e o que mais precisar):

#include <stdbool.h>
#include <stdio.h>

#define MAX 6

const char *tarefas[MAX] = {"café", "banho", "vestir", "escovar", "sair", "mensagens"};
int n;              // quantas tarefas valem agora
int antes[MAX][MAX];
bool mostrar;

int conta(void) {
    return 0;
}

int main(void) {
    int regras[][2] = {{1, 2}, {0, 3}, {2, 4}, {3, 4}};
    for (int k = 0; k < 4; k++) antes[regras[k][0]][regras[k][1]] = 1;

    n = 5;
    mostrar = true;
    printf("Total com 5 tarefas: %d\n", conta());

    n = 6;
    antes[5][4] = 1; // ler as mensagens antes de sair
    mostrar = false;
    printf("Total com 6 tarefas: %d\n", conta());
    return 0;
}
