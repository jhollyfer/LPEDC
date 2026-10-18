// 0083 · Pilha encadeada
// Exercício E495 · ★★☆
//
// O botão Voltar do navegador é uma pilha de páginas. Este programa monta a
// própria pilha encadeada, com um texto em cada nó (por isso não usa o
// pilha.h, que guarda int). Complete as funções:
//
// - visita: cria um nó com a url e põe no topo (devolve false se faltar
// memória);
// - voltar: tira a página do topo, mas só se ela não for a única (da
// primeira página não se volta). Devolve false se não deu para voltar.
//
//   Saída esperada:
//   Agora em: receitas.com
//   Voltar -> ge.globo.com
//   Agora em: cifraclub.com.br
//   Voltar -> ge.globo.com
//   Voltar -> g1.globo.com
//   Não dá para voltar de g1.globo.com
//
// Dicas:
// 1. Em visita, faça como no pilha_empilha: malloc, copie a url com strcpy,
//    ligue novo->ant ao topo antigo e só então troque o topo.
// 2. A página é a única quando h->topo->ant == NULL.
// 3. Em voltar, guarde o nó velho, avance o topo e só depois dê free.
// 4. Resposta esperada: as seis linhas acima, sem vazamento no sanitizer.
//
// Escreva sua resposta abaixo (complete visita e voltar):

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
    (void)h; // apague estas linhas quando usar h e url
    (void)url;
    return false;
}

bool voltar(Historico *h) {
    (void)h;
    return false;
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
