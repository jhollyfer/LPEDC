// Lista · Módulo 25 · Estruturas especiais
// Exercício P2522 · ★★★ · A skip list perfeita

#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define N 15

typedef struct No {
    int chave;
    int andares;
    struct No *prox[MAX];
} No;

No cabeca;
No *nos[N];

int main(void) {
    int chaves[N];
    for (int i = 0; i < N; i++) chaves[i] = 10 * (i + 1); // 10, 20, ..., 150

    // o nó da posição i (contando de 1) ganha 1 + (quantos zeros no fim de i em binário) andares
    No *ultimo[MAX];
    for (int k = 0; k < MAX; k++) {
        ultimo[k] = &cabeca;
        cabeca.prox[k] = NULL;
    }
    for (int i = 1; i <= N; i++) {
        No *x = malloc(sizeof(No));
        if (x == NULL) exit(1);
        x->chave = chaves[i - 1];
        x->andares = 1;
        for (int t = i; t % 2 == 0 && x->andares < MAX; t /= 2) x->andares++;
        for (int k = 0; k < MAX; k++) {
            x->prox[k] = NULL;
            if (k < x->andares) { // liga no fim de cada andar dele
                ultimo[k]->prox[k] = x;
                ultimo[k] = x;
            }
        }
        nos[i - 1] = x;
    }
    for (int k = MAX - 1; k >= 0; k--) {
        printf("andar %d:", k);
        for (No *x = cabeca.prox[k]; x != NULL; x = x->prox[k]) printf(" %d", x->chave);
        printf("\n");
    }

    int pior = 0, soma = 0;
    printf("comparações:");
    for (int i = 0; i < N; i++) {
        int alvo = chaves[i], c = 0;
        No *x = &cabeca;
        for (int k = MAX - 1; k >= 0; k--)
            while (x->prox[k] != NULL) {
                c++;
                if (x->prox[k]->chave >= alvo) break;
                x = x->prox[k];
            }
        printf(" %d", c);
        soma += c;
        if (c > pior) pior = c;
    }
    printf("\nmédia %.2f, pior %d\n", soma / (double)N, pior);
    for (int i = 0; i < N; i++) free(nos[i]);
    return 0;
}
