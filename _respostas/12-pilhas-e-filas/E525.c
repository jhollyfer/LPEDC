// 0088 · Juntando tudo: a calculadora de expressões
// Exercício E525 · ★★☆

#include <stdbool.h>
#include <stdio.h>
// Inclui a implementação do TAD para compilar sozinho (no enunciado: #include do .h).
#include "../../material/0088-fila.c"
#include "../../material/0088-pilha.c"

typedef struct {
    Pilha *entrada;
    Pilha *saida;
} FilaDuasPilhas;

bool fdp_insere(FilaDuasPilhas *f, int valor) {
    return pilha_empilha(f->entrada, valor);
}

bool fdp_retira(FilaDuasPilhas *f, int *valor) {
    if (pilha_vazia(f->saida)) { // só despeja quando a saída esvaziou
        int x;
        while (pilha_desempilha(f->entrada, &x)) {
            pilha_empilha(f->saida, x);
        }
    }
    return pilha_desempilha(f->saida, valor);
}

int main(void) {
    FilaDuasPilhas f = {pilha_cria(), pilha_cria()};
    if (f.entrada == NULL || f.saida == NULL) {
        if (f.entrada != NULL) {
            pilha_libera(f.entrada);
        }
        if (f.saida != NULL) {
            pilha_libera(f.saida);
        }
        return 1;
    }
    int x;
    fdp_insere(&f, 1);
    fdp_insere(&f, 2);
    fdp_insere(&f, 3);
    if (fdp_retira(&f, &x)) {
        printf("Saiu: %d\n", x);
    }
    fdp_insere(&f, 4);
    printf("Depois:");
    while (fdp_retira(&f, &x)) {
        printf(" %d", x);
    }
    printf("\n");
    pilha_libera(f.entrada);
    pilha_libera(f.saida);
    return 0;
}
