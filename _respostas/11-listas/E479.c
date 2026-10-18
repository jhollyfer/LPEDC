// 0080 · Vetor dinâmico
// Exercício E479 · ★★★
//
// Os três problemas: (1) realloc recebia v->cap (bytes) em vez de
// v->cap * sizeof(int); (2) "primeiro" guardava o endereço de um item, que
// fica solto quando o realloc muda o vetor de lugar: guarde o índice;
// (3) "v->itens = realloc(v->itens, ...)" perde o bloco antigo se o realloc
// falhar: use uma variável temporária.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *itens;
    int tam;
    int cap;
} Vetor;

static bool vetor_insere(Vetor *v, int valor) {
    if (v->tam == v->cap) {
        int nova_cap = v->cap * 2;
        int *novo = realloc(v->itens, nova_cap * sizeof(int));
        if (novo == NULL) return false; // v->itens continua valendo
        v->itens = novo;
        v->cap = nova_cap;
    }
    v->itens[v->tam] = valor;
    v->tam++;
    return true;
}

int main(void) {
    Vetor v = {malloc(2 * sizeof(int)), 0, 2};
    if (v.itens == NULL) return 1;

    vetor_insere(&v, 40);
    int primeiro = 0; // a posição continua valendo; o endereço, não
    for (int vel = 50; vel <= 90; vel += 10) {
        vetor_insere(&v, vel);
    }

    printf("primeiro: %d\n", v.itens[primeiro]);
    for (int i = 0; i < v.tam; i++) {
        printf("%d ", v.itens[i]);
    }
    printf("\n");

    free(v.itens);
    return 0;
}
