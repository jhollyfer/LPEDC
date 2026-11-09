// Lista · Módulo 15 · Tabelas hash
// Exercício P1521 · ★★★ · O contador da feira que cresce sozinho

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char palavra[16];
    int vezes;
    struct No *prox;
} No;

typedef struct {
    No **baldes;
    int m, n;
} Tabela;

unsigned long long djb2(const char *s) {
    unsigned long long h = 5381;
    for (; *s != '\0'; s++) {
        h = h * 33 + (unsigned char)*s;
    }
    return h;
}

No **cria_baldes(int m) {
    No **b = calloc(m, sizeof(No *));
    if (b == NULL) {
        exit(1);
    }
    return b;
}

// muda o número de baldes e move os nós (sem copiar palavra nenhuma)
void rehash(Tabela *t, int novo_m) {
    No **novos = cria_baldes(novo_m);
    for (int b = 0; b < t->m; b++) {
        No *p = t->baldes[b];
        while (p != NULL) {
            No *prox = p->prox;
            int nb = (int)(djb2(p->palavra) % novo_m);
            p->prox = novos[nb];
            novos[nb] = p;
            p = prox;
        }
    }
    free(t->baldes);
    t->baldes = novos;
    t->m = novo_m;
}

void conta(Tabela *t, const char *palavra) {
    int b = (int)(djb2(palavra) % t->m);
    for (No *p = t->baldes[b]; p != NULL; p = p->prox) {
        if (strcmp(p->palavra, palavra) == 0) {
            p->vezes++;
            return;
        }
    }
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    snprintf(novo->palavra, sizeof novo->palavra, "%s", palavra);
    novo->vezes = 1;
    novo->prox = t->baldes[b];
    t->baldes[b] = novo;
    t->n++;
    if (t->n > t->m) { // alfa passou de 1
        int velho = t->m;
        rehash(t, 2 * t->m + 1);
        printf("rehash depois de \"%s\": %d -> %d baldes\n", palavra, velho, t->m);
    }
}

void libera(Tabela *t) {
    for (int b = 0; b < t->m; b++) {
        while (t->baldes[b] != NULL) {
            No *prox = t->baldes[b]->prox;
            free(t->baldes[b]);
            t->baldes[b] = prox;
        }
    }
    free(t->baldes);
}

int main(void) {
    const char *feira[] = {"banana", "maca", "uva", "banana", "pera", "maca", "banana", "limao",
                           "uva", "kiwi", "manga", "pera", "banana", "caju", "coco", "figo"};
    int total = 16;
    Tabela t = {cria_baldes(3), 3, 0};

    for (int i = 0; i < total; i++) {
        conta(&t, feira[i]);
    }

    int maior = 0;
    for (int b = 0; b < t.m; b++) {
        int tam = 0;
        printf("%d:", b);
        for (No *p = t.baldes[b]; p != NULL; p = p->prox) {
            printf(" %s=%d", p->palavra, p->vezes);
            tam++;
        }
        printf("\n");
        if (tam > maior) {
            maior = tam;
        }
    }
    printf("%d palavras, %d distintas, m = %d, alfa = %.2f, maior corrente = %d\n", total, t.n, t.m, (double)t.n / t.m, maior);
    libera(&t);
    return 0;
}
