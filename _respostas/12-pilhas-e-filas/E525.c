// 0088 · Pilha encadeada
// Exercício E525 · ★★☆

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pagina {
    char url[40];
    struct pagina *ant; // a página de onde você veio
} Pagina;

typedef struct {
    Pagina *topo; // a página aberta agora
} Historico;

bool visita(Historico *h, const char *url) {
    Pagina *nova = malloc(sizeof *nova);
    if (nova == NULL) {
        return false;
    }
    strcpy(nova->url, url); // as urls do exemplo cabem em 40 bytes
    nova->ant = h->topo;
    h->topo = nova;
    return true;
}

bool voltar(Historico *h) {
    if (h->topo == NULL || h->topo->ant == NULL) {
        return false; // vazio ou só uma página: não tem para onde voltar
    }
    Pagina *velha = h->topo;
    h->topo = velha->ant;
    free(velha);
    return true;
}

void historico_libera(Historico *h) {
    while (h->topo != NULL) {
        Pagina *ant = h->topo->ant;
        free(h->topo);
        h->topo = ant;
    }
}

void tenta_voltar(Historico *h) {
    if (voltar(h)) {
        printf("Voltar -> %s\n", h->topo->url);
    } else if (h->topo != NULL) {
        printf("Não dá para voltar de %s\n", h->topo->url);
    }
}

int main(void) {
    Historico h = {NULL};

    visita(&h, "g1.globo.com");
    visita(&h, "ge.globo.com");
    visita(&h, "receitas.com");
    if (h.topo != NULL) {
        printf("Agora em: %s\n", h.topo->url);
    }
    tenta_voltar(&h);
    visita(&h, "cifraclub.com.br");
    if (h.topo != NULL) {
        printf("Agora em: %s\n", h.topo->url);
    }
    tenta_voltar(&h);
    tenta_voltar(&h);
    tenta_voltar(&h);

    historico_libera(&h);
    return 0;
}
