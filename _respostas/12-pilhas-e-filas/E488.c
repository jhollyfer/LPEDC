// 0082 · Pilha
// Exercício E488 · ★☆☆

#include <stdio.h>
#include <string.h>
// Na pasta do assunto basta #include "pilha.h" (o rodar compila o pilha.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0082-pilha/pilha.c"

int main(void) {
    char palavra[32];
    printf("Digite uma palavra: ");
    if (fgets(palavra, sizeof palavra, stdin) == NULL) {
        return 1;
    }
    palavra[strcspn(palavra, "\n")] = '\0';

    Pilha *p = pilha_cria();
    if (p == NULL) {
        return 1;
    }
    for (size_t i = 0; palavra[i] != '\0'; i++) {
        pilha_empilha(p, palavra[i]);
    }

    printf("Ao contrário: ");
    int c;
    while (pilha_desempilha(p, &c)) {
        printf("%c", c);
    }
    printf("\n");

    pilha_libera(p);
    return 0;
}
