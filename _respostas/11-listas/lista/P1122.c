// Lista · Módulo 11 · Listas
// Exercício P1122 · ★★★ · O malloc de brinquedo (first-fit)

#include <stdio.h>
#include <stdlib.h>

typedef struct bloco {
    int inicio;
    int tamanho;
    struct bloco *prox;
} Bloco;

Bloco *novo_bloco(int inicio, int tamanho, Bloco *prox) {
    Bloco *b = malloc(sizeof *b);
    if (b == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    b->inicio = inicio;
    b->tamanho = tamanho;
    b->prox = prox;
    return b;
}

int aloca(Bloco **livres, int tam) {
    Bloco *ant = NULL, *p = *livres;
    while (p != NULL && p->tamanho < tam) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) {
        return -1;
    }
    int endereco = p->inicio;
    p->inicio += tam;
    p->tamanho -= tam;
    if (p->tamanho == 0) { // o bloco acabou: sai da lista
        if (ant == NULL) {
            *livres = p->prox;
        } else {
            ant->prox = p->prox;
        }
        free(p);
    }
    return endereco;
}

void desaloca(Bloco **livres, int ini, int tam) {
    Bloco *ant = NULL, *p = *livres;
    while (p != NULL && p->inicio < ini) {
        ant = p;
        p = p->prox;
    }
    Bloco *meio;
    if (ant != NULL && ant->inicio + ant->tamanho == ini) {
        ant->tamanho += tam; // encosta à esquerda: cresce o anterior
        meio = ant;
    } else {
        meio = novo_bloco(ini, tam, p);
        if (ant == NULL) {
            *livres = meio;
        } else {
            ant->prox = meio;
        }
    }
    if (p != NULL && meio->inicio + meio->tamanho == p->inicio) {
        meio->tamanho += p->tamanho; // encosta à direita: engole o seguinte
        meio->prox = p->prox;
        free(p);
    }
}

void mostra(const Bloco *livres) {
    printf("| livres:");
    for (const Bloco *b = livres; b != NULL; b = b->prox) {
        printf(" [%d,%d)", b->inicio, b->inicio + b->tamanho);
    }
    printf("\n");
}

void faz_aloca(Bloco **livres, int tam) {
    int e = aloca(livres, tam);
    if (e >= 0) {
        printf("aloca %d -> %d ", tam, e);
    } else {
        printf("aloca %d -> falhou ", tam);
    }
    mostra(*livres);
}

void faz_desaloca(Bloco **livres, int ini, int tam) {
    desaloca(livres, ini, tam);
    printf("desaloca %d+%d ", ini, tam);
    mostra(*livres);
}

int main(void) {
    Bloco *livres = novo_bloco(0, 100, NULL);
    faz_aloca(&livres, 30);
    faz_aloca(&livres, 20);
    faz_aloca(&livres, 25);
    faz_desaloca(&livres, 30, 20);
    faz_aloca(&livres, 10);
    faz_desaloca(&livres, 0, 30);
    faz_desaloca(&livres, 50, 25);
    faz_aloca(&livres, 50);
    faz_aloca(&livres, 40);

    int total = 0, maior = 0;
    for (const Bloco *b = livres; b != NULL; b = b->prox) {
        total += b->tamanho;
        if (b->tamanho > maior) {
            maior = b->tamanho;
        }
    }
    printf("Livre: %d posições, maior bloco: %d\n", total, maior);
    while (livres != NULL) {
        Bloco *seguinte = livres->prox;
        free(livres);
        livres = seguinte;
    }
    return 0;
}
