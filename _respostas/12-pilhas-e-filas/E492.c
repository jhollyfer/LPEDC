// 0082 · Pilha
// Exercício E492 · ★★★

#include <stdbool.h>
#include <stdio.h>

#define LUGARES 6

typedef struct {
    int itens[LUGARES];
    int n_limpos;   // próxima vaga da esquerda; limpos em itens[0..n_limpos-1]
    int topo_sujos; // último sujo; sujos em itens[topo_sujos..LUGARES-1]
} Bancada;

bool empilha_limpo(Bancada *b, int prato) {
    if (b->n_limpos == b->topo_sujos) {
        return false; // as duas pilhas se encontraram
    }
    b->itens[b->n_limpos] = prato;
    b->n_limpos++;
    return true;
}

bool empilha_sujo(Bancada *b, int prato) {
    if (b->n_limpos == b->topo_sujos) {
        return false;
    }
    b->topo_sujos--;
    b->itens[b->topo_sujos] = prato;
    return true;
}

bool desempilha_limpo(Bancada *b, int *prato) {
    if (b->n_limpos == 0) {
        return false;
    }
    b->n_limpos--;
    *prato = b->itens[b->n_limpos];
    return true;
}

bool desempilha_sujo(Bancada *b, int *prato) {
    if (b->topo_sujos == LUGARES) {
        return false;
    }
    *prato = b->itens[b->topo_sujos];
    b->topo_sujos++;
    return true;
}

int main(void) {
    Bancada b = {.n_limpos = 0, .topo_sujos = LUGARES};
    int x;

    for (int i = 1; i <= 3; i++) {
        empilha_limpo(&b, i);
        empilha_sujo(&b, i * 10);
    }
    printf("Limpo 4: %s\n", empilha_limpo(&b, 4) ? "ok" : "bancada cheia");
    if (desempilha_sujo(&b, &x)) {
        printf("Saiu o sujo %d\n", x);
    }
    printf("Limpo 4: %s\n", empilha_limpo(&b, 4) ? "ok" : "bancada cheia");

    printf("Limpos:");
    while (desempilha_limpo(&b, &x)) {
        printf(" %d", x);
    }
    printf("\nSujos:");
    while (desempilha_sujo(&b, &x)) {
        printf(" %d", x);
    }
    printf("\n");
    return 0;
}
