// Lista · Módulo 12 · Pilhas e filas
// Exercício P1221 · ★★★ · O banco em que o cliente desiste
//
// Simule a fila de uma agência com UM caixa. Cada cliente tem nome, minuto
// de chegada, minutos de atendimento e TOLERÂNCIA (quantos minutos aceita
// esperar). Quando o caixa fica livre, ele chama o primeiro da fila; se
// esse cliente já esperou MAIS que a tolerância, ele tinha ido embora: o
// caixa registra a desistência e chama o próximo, no mesmo minuto.
//
//   cliente  chegada  atendimento  tolerância
//   Ana         0          5           10
//   Beto        1          3            2
//   Caio        2          4           10
//   Duda        3          2            1
//   Edu         8          3            5
//   Fabi        9          1            0
//
// Use uma fila encadeada de structs e um relógio que avança de minuto em
// minuto: em cada minuto, primeiro entram na fila os que chegaram, depois o
// caixa (se livre) chama. Mostre cada chamada e o resumo.
//
//   Saída esperada:
//   min 0: atende Ana (esperou 0)
//   min 5: Beto tinha desistido
//   min 5: atende Caio (esperou 3)
//   min 9: Duda tinha desistido
//   min 9: atende Edu (esperou 1)
//   min 12: Fabi tinha desistido
//   Atendidos: 3, desistências: 3
//   Espera média dos atendidos: 1.33 min
//
// Dicas:
// 1. Guarde livre_em: o minuto em que o caixa termina o atendimento atual.
//    O caixa está livre quando livre_em <= minuto.
// 2. Espera = minuto da chamada - chegada. Desistiu se espera > tolerância.
// 3. Pare quando todos tiverem chegado e a fila estiver vazia. Lembre de
//    liberar cada nó que sai da fila.
// 4. Resposta esperada: a saída acima ((0 + 3 + 1) / 3 = 1.33).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[12];
    int chegada, atendimento, tolerancia;
} Cliente;

int main(void) {

    return 0;
}
