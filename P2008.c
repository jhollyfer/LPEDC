// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2008 · ★☆☆ · Os consertos da oficina
//
// O mecânico faz um conserto por dia e tem 6 pedidos. Cada pedido tem um
// prazo (até que dia o cliente aceita esperar) e um valor; se ficar para
// depois do prazo, o cliente vai embora. Os pedidos JÁ estão em ordem
// decrescente de valor:
//
//   pedido   A    B    C    D    E    F
//   valor   300  250  200  150  100   80
//   prazo    2    1    2    3    3    1
//
// O guloso do AGENDAMENTO COM PRAZOS pega os pedidos do mais valioso para
// o menos e põe cada um no ÚLTIMO dia livre que ainda está dentro do prazo
// dele (deixando os dias cedo para quem tem prazo curto). Se não há dia
// livre, o pedido é recusado. Complete o laço que procura o dia.
//
//   Saída esperada:
//   Recusado: C (R$ 200)
//   Recusado: E (R$ 100)
//   Recusado: F (R$ 80)
//   Dia 1: B (R$ 250)
//   Dia 2: A (R$ 300)
//   Dia 3: D (R$ 150)
//   Total: R$ 700
//
// Dicas:
// 1. Os dias vão de 1 a 3 (o maior prazo). dia[d] guarda o índice do
//    pedido do dia d, ou -1.
// 2. for (int d = prazo[i]; d >= 1; d--) if (dia[d] == -1) { dia[d] = i;
//    break; }
// 3. Resposta esperada: dia 1 B, dia 2 A, dia 3 D, total R$ 700.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define N 6
#define DIAS 3

const char nome[N] = {'A', 'B', 'C', 'D', 'E', 'F'};
const int valor[N] = {300, 250, 200, 150, 100, 80};
const int prazo[N] = {2, 1, 2, 3, 3, 1};

int main(void) {
    int dia[DIAS + 1];
    for (int d = 1; d <= DIAS; d++) {
        dia[d] = -1;
    }
    for (int i = 0; i < N; i++) {
        int achou = 0;
        // COMPLETE AQUI
        if (!achou) {
            printf("Recusado: %c (R$ %d)\n", nome[i], valor[i]);
        }
    }
    int total = 0;
    for (int d = 1; d <= DIAS; d++) {
        if (dia[d] >= 0) {
            printf("Dia %d: %c (R$ %d)\n", d, nome[dia[d]], valor[dia[d]]);
            total += valor[dia[d]];
        }
    }
    printf("Total: R$ %d\n", total);
    return 0;
}
