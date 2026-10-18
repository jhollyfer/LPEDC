// 0082 · Pilha
// Exercício E487 · ★☆☆

#include <stdbool.h>
#include <stdio.h>
// Na pasta do assunto basta #include "pilha.h" (o rodar compila o pilha.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0082-pilha/pilha.c"

int main(void) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return 1;
    }
    int x;

    pilha_empilha(p, 4);
    pilha_empilha(p, 7);
    pilha_desempilha(p, &x);
    printf("%d\n", x);

    pilha_empilha(p, 2);
    pilha_empilha(p, 9);
    pilha_topo(p, &x);
    printf("%d\n", x);

    pilha_desempilha(p, &x);
    pilha_desempilha(p, &x);
    printf("%d %d\n", x, pilha_tamanho(p));

    while (pilha_desempilha(p, &x)) {
        printf("%d ", x);
    }
    printf("\nvazia? %d\n", pilha_vazia(p));

    bool ok = pilha_desempilha(p, &x); // vazia: devolve false e não mexe em x
    printf("mais um desempilha: devolveu %d, x = %d\n", ok, x);

    pilha_libera(p);
    return 0;
}
