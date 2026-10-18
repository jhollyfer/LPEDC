// 0083 · Pilha encadeada
// Exercício E497 · ★★★

#include <stdio.h>
// Na pasta do assunto basta #include "pilha.h" (o rodar compila o pilha.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0083-pilha-encadeada/pilha.c"

void ordena(Pilha *p) {
    Pilha *aux = pilha_cria(); // sempre ordenada, com o maior no topo
    if (aux == NULL) {
        return;
    }
    int x;
    while (pilha_desempilha(p, &x)) {
        int topo;
        // abre espaço: o que for maior que x volta para a original
        while (pilha_topo(aux, &topo) && topo > x) {
            pilha_desempilha(aux, &topo);
            pilha_empilha(p, topo);
        }
        pilha_empilha(aux, x);
    }
    while (pilha_desempilha(aux, &x)) { // o maior vai para o fundo
        pilha_empilha(p, x);
    }
    pilha_libera(aux);
}

int main(void) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return 1;
    }
    int pedidos[] = {5, 3, 8, 1, 4};
    for (int i = 0; i < 5; i++) {
        pilha_empilha(p, pedidos[i]);
    }

    ordena(p);

    int x;
    while (pilha_desempilha(p, &x)) {
        printf("%d ", x);
    }
    printf("\n");
    pilha_libera(p);
    return 0;
}
