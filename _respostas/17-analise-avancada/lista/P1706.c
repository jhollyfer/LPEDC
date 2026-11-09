// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1706 · ★☆☆ · O desfazer do editor: pilha com multipop

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char item[MAX];
    int topo; // quantos itens há
} Pilha;

void empilha(Pilha *p, char c) { p->item[p->topo++] = c; }

int multipop(Pilha *p, int k) {
    int saiu = 0;
    while (k > 0 && p->topo > 0) {
        p->topo--;
        k--;
        saiu++;
    }
    return saiu;
}

int main(void) {
    Pilha p = {.topo = 0};
    const char *sessao[] = {"manaux", "-1", "s! ok", "-12", "oi", "-1"}; // "-k" = desfazer k
    int pushes = 0, pops = 0, maior = 0;

    for (int i = 0; i < 6; i++) {
        int custo;
        char rotulo[32];
        if (sessao[i][0] == '-') {
            custo = multipop(&p, atoi(sessao[i] + 1));
            pops += custo;
            snprintf(rotulo, sizeof rotulo, "desfaz %s", sessao[i] + 1);
        } else {
            custo = 0;
            for (const char *c = sessao[i]; *c; c++, custo++) empilha(&p, *c);
            pushes += custo;
            snprintf(rotulo, sizeof rotulo, "digita \"%s\"", sessao[i]);
        }
        printf("%-15s custo %2d | texto: \"%.*s\"\n", rotulo, custo, p.topo, p.item);
        if (custo > maior) maior = custo;
    }
    printf("Empilhadas %d, tiradas %d, total %d (limite 2 x %d = %d)\n",
           pushes, pops, pushes + pops, pushes, 2 * pushes);
    printf("Operação mais cara: %d\n", maior);
    return 0;
}
