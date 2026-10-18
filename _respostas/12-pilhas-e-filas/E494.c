// 0083 · Pilha encadeada
// Exercício E494 · ★☆☆

#include <stdio.h>
// Na pasta do assunto basta #include "pilha.h" (o rodar compila o pilha.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0083-pilha-encadeada/pilha.c"

int main(void) {
    Pilha *notas = pilha_cria();
    if (notas == NULL) {
        return 1;
    }
    printf("Digite os valores (0 para terminar): ");
    int valor;
    while (scanf("%d", &valor) == 1 && valor != 0) {
        pilha_empilha(notas, valor);
    }

    printf("Lidas %d notas. Da última para a primeira:", pilha_tamanho(notas));
    while (pilha_desempilha(notas, &valor)) {
        printf(" %d", valor);
    }
    printf("\n");
    pilha_libera(notas);
    return 0;
}
