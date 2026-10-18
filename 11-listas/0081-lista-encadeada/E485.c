// 0081 · Lista encadeada
// Exercício E485 · ★★★
//
// A cartela de fidelidade da padaria guarda os pontos de cada compra numa
// lista. O programa tem DOIS erros de propósito. Rode, leia o aviso do gcc,
// o que sai e o relatório do AddressSanitizer, ache os dois e conserte.
//
//   Saída esperada depois do conserto:
//   10 -> 5 -> 8 -> 3 -> NULL
//   total de pontos: 26
//
// Dicas:
// 1. A execução mostra só "NULL" e total 0, e o ASan reclama de "memory
//    leaks": os nós foram criados, mas ninguém guardou o endereço deles.
// 2. O gcc já avisa o outro: "pointer 'p' used after 'free'" em libera_tudo.
//    Olhe o "p = p->prox" do for: ele roda DEPOIS do free(p). Consertado o
//    primeiro erro, o ASan confirma com "heap-use-after-free".
// 3. Resposta esperada: "cartela = lista_insere_inicio(cartela, ...)" (a
//    função devolve o novo início, e o valor devolvido era jogado fora); e
//    em libera_tudo, guardar p->prox numa variável antes do free.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

static void libera_tudo(No *inicio) {
    for (No *p = inicio; p != NULL; p = p->prox) {
        free(p);
    }
}

int main(void) {
    int pontos[] = {3, 8, 5, 10};
    No *cartela = NULL;
    for (int i = 0; i < 4; i++) {
        lista_insere_inicio(cartela, pontos[i]);
    }
    lista_imprime(cartela);

    int soma = 0;
    for (No *p = cartela; p != NULL; p = p->prox) {
        soma += p->valor;
    }
    printf("total de pontos: %d\n", soma);

    libera_tudo(cartela);
    return 0;
}
