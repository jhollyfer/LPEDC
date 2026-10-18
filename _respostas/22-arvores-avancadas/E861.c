// 0144 · Árvores gerais
// Exercício E861 · ★★☆

#include <stdio.h>
#include <string.h>
#include "arvgen.h"

// devolve a profundidade do item (e deixa a trilha em trilha[0..nivel]) ou -1
int acha(const NoG *r, const char *nome, const NoG *trilha[], int nivel) {
    trilha[nivel] = r;
    if (strcmp(r->nome, nome) == 0) {
        return nivel;
    }
    for (const NoG *p = r->filho; p != NULL; p = p->irmao) {
        int prof = acha(p, nome, trilha, nivel + 1);
        if (prof >= 0) {
            return prof;
        }
    }
    return -1;
}

void caminho(const NoG *r, const char *nome) {
    const NoG *trilha[32];
    int prof = acha(r, nome, trilha, 0);
    printf("%s: ", nome);
    if (prof < 0) {
        printf("não encontrado\n");
        return;
    }
    for (int i = 0; i <= prof; i++) {
        printf("%s%s", i > 0 ? " > " : "", trilha[i]->nome);
    }
    printf(" (profundidade %d)\n", prof);
}

int main(void) {
    NoG *reforma = ag_cria("reforma", 0);
    NoG *cozinha = ag_adiciona(reforma, "cozinha", 0);
    ag_adiciona(cozinha, "piso", 1800);
    ag_adiciona(cozinha, "pia", 650);
    NoG *banheiro = ag_adiciona(reforma, "banheiro", 0);
    ag_adiciona(banheiro, "box", 900);
    NoG *loucas = ag_adiciona(banheiro, "loucas", 0);
    ag_adiciona(loucas, "vaso", 420);
    ag_adiciona(loucas, "cuba", 280);
    ag_adiciona(reforma, "pintura", 1200);

    caminho(reforma, "vaso");
    caminho(reforma, "pia");
    caminho(reforma, "reforma");
    caminho(reforma, "janela");

    ag_libera(reforma);
    return 0;
}
