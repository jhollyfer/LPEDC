// 0060 · calloc e realloc
// Exercício E360 · ★★★
//
// A fila do banco guarda as senhas num vetor que cresce. O programa guarda o
// endereço da primeira senha para mostrar no painel depois. Ele está ERRADO
// de propósito: rode com o rodar, leia o relatório do AddressSanitizer e
// responda: qual é o erro, em que linha, e por que o realloc é o culpado?
// Depois conserte.
//
//   Saída esperada depois do conserto:
//   Painel: senha 101
//   Senhas na fila: 4
//
// Dicas:
// 1. Procure "heap-use-after-free" e as três pilhas do relatório: onde leu,
//    onde o bloco foi liberado e onde foi alocado.
// 2. O realloc pode mudar o bloco de lugar. O que acontece com um ponteiro
//    que apontava para dentro do bloco antigo?
// 3. Resposta esperada: o printf do painel lê *primeira, que aponta para o
//    bloco antigo, liberado dentro do realloc. Conserto: guarde o ÍNDICE (0)
//    em vez do endereço e leia senhas[0] depois, ou pegue o endereço só
//    depois do último realloc.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int capacidade = 2;
    int quantidade = 0;
    int *senhas = malloc(capacidade * sizeof *senhas);
    if (senhas == NULL) {
        return 1;
    }
    senhas[quantidade++] = 101;
    int *primeira = &senhas[0]; // endereço guardado para o painel

    for (int nova = 102; nova <= 104; nova++) {
        if (quantidade == capacidade) {
            int *maior = realloc(senhas, 2 * capacidade * sizeof *senhas);
            if (maior == NULL) {
                free(senhas);
                return 1;
            }
            senhas = maior;
            capacidade *= 2;
        }
        senhas[quantidade++] = nova;
    }

    printf("Painel: senha %d\n", *primeira);
    printf("Senhas na fila: %d\n", quantidade);
    free(senhas);
    return 0;
}
