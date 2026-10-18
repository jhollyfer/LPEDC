// 0164 · Listas autoajustáveis
// Exercício E983 · ★★★

#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 3

typedef struct NoFoto {
    int foto;
    struct NoFoto *prox;
} NoFoto;

// mover para a frente: devolve 1 se achou (e levou para o início)
int acha(NoFoto **inicio, int foto) {
    NoFoto *ant = NULL;
    NoFoto *p = *inicio;
    while (p != NULL && p->foto != foto) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) {
        return 0;
    }
    if (ant != NULL) {
        ant->prox = p->prox;
        p->prox = *inicio;
        *inicio = p;
    }
    return 1;
}

int main(void) {
    NoFoto *cache = NULL;
    int tamanho = 0, acertos = 0, faltas = 0, foto;

    while (scanf("%d", &foto) == 1) {
        int acertou = acha(&cache, foto);
        if (acertou) {
            acertos++;
        } else {
            faltas++;
            NoFoto *novo = malloc(sizeof(NoFoto));
            if (novo == NULL) {
                exit(1);
            }
            novo->foto = foto;
            novo->prox = cache;
            cache = novo;
            tamanho++;
            if (tamanho > CAPACIDADE) { // sai a usada há mais tempo: a do fim
                NoFoto *p = cache;
                while (p->prox->prox != NULL) {
                    p = p->prox;
                }
                free(p->prox);
                p->prox = NULL;
                tamanho--;
            }
        }
        printf("foto %d: %-6s ->", foto, acertou ? "acerto" : "falta");
        for (NoFoto *p = cache; p != NULL; p = p->prox) {
            printf(" %d", p->foto);
        }
        printf("\n");
    }
    printf("Acertos: %d, faltas: %d\n", acertos, faltas);

    while (cache != NULL) {
        NoFoto *prox = cache->prox;
        free(cache);
        cache = prox;
    }
    return 0;
}
