// 0071 · Juntando tudo: o cardápio
// Exercício E425 · ★★★
//
// Uma agenda de tarefas. Cada Tarefa tem título, Prioridade (enum BAIXA,
// MEDIA, ALTA), prazo (dia do mês) e tags em bits: TRABALHO, CASA, URGENTE.
// Aloque o vetor com malloc, preencha com as 6 tarefas abaixo, ordene com
// qsort (prioridade mais alta primeiro; empate: prazo menor primeiro) e
// mostre a lista inteira e depois só as tarefas de TRABALHO.
//
//   título            prioridade  prazo  tags
//   Pagar aluguel     ALTA        5      CASA | URGENTE
//   Revisar PR        MEDIA       3      TRABALHO
//   Comprar ração     BAIXA       8      CASA
//   Deploy da API     ALTA        2      TRABALHO | URGENTE
//   Reunião 1:1       MEDIA       3      TRABALHO
//   Lavar o carro     BAIXA       12     CASA
//
//   Saída esperada:
//   [alta] dia 2: Deploy da API
//   [alta] dia 5: Pagar aluguel
//   [média] dia 3: Reunião 1:1
//   [média] dia 3: Revisar PR
//   [baixa] dia 8: Comprar ração
//   [baixa] dia 12: Lavar o carro
//   Trabalho:
//   [alta] dia 2: Deploy da API
//   [média] dia 3: Reunião 1:1
//   [média] dia 3: Revisar PR
//
// Dicas:
// 1. Com BAIXA = 0, MEDIA = 1, ALTA = 2, "mais alta primeiro" é
//    y.prioridade - x.prioridade na comparadora.
// 2. Revisar PR e Reunião 1:1 empatam em tudo. O qsort não garante a ordem
//    de empates (não é estável): para a saída ser sempre a mesma, desempate
//    também pelo título com strcmp ("Reunião" vem antes de "Revisar").
// 3. Filtro: (t.tags & TRABALHO) != 0.
// 4. Resposta esperada: a saída acima, e free no fim.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
