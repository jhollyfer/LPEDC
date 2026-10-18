// 0067 · Ponteiro para struct
// Exercício E399 · ★★☆
//
// Crie o tipo Conta (titular e saldo) e três funções:
//
//   - Conta *conta_criar(const char *titular, double saldo): aloca com malloc,
//     preenche e devolve (NULL se faltar memória);
//   - bool transferir(Conta *de, Conta *para, double valor): só transfere se
//     houver saldo, e devolve se deu certo;
//   - void conta_destruir(Conta *c): libera.
//
// Crie Ana com R$ 500.00 e Beto com R$ 120.00. Transfira R$ 200.00 de Ana
// para Beto e depois R$ 400.00 de Beto para Ana.
//
//   Saída esperada:
//   Ana -> Beto, R$ 200.00: ok
//   Beto -> Ana, R$ 400.00: saldo insuficiente
//   Ana: R$ 300.00 | Beto: R$ 320.00
//
// Dicas:
// 1. Conta *c = malloc(sizeof *c); if (c == NULL) return NULL;
// 2. O titular é vetor: strcpy(c->titular, titular). Garanta que o nome cabe
//    (ou use strncpy e ponha o '\0' no fim).
// 3. Todo conta_criar precisa de um conta_destruir. Rode com o rodar: o
//    AddressSanitizer acusa se você esquecer algum.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
