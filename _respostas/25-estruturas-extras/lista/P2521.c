// Lista · Módulo 25 · Estruturas especiais
// Exercício P2521 · ★★★ · O cache de CEPs em O(1)

#include <stdio.h>
#include <stdlib.h>

#define CAP 3
#define BALDES 13

typedef struct No {
    int cep;
    struct No *ant, *prox; // a lista dupla: da frente (recente) para o fim (antigo)
    struct No *irmao;      // o próximo no mesmo balde do hash
} No;

No *frente = NULL, *fundo = NULL;
No *balde[BALDES];
int tamanho = 0;

No *acha(int cep) {
    for (No *x = balde[cep % BALDES]; x != NULL; x = x->irmao)
        if (x->cep == cep) return x;
    return NULL;
}

void desliga(No *x) { // tira x da lista dupla em O(1)
    if (x->ant) x->ant->prox = x->prox;
    else frente = x->prox;
    if (x->prox) x->prox->ant = x->ant;
    else fundo = x->ant;
}

void na_frente(No *x) {
    x->ant = NULL;
    x->prox = frente;
    if (frente) frente->ant = x;
    frente = x;
    if (fundo == NULL) fundo = x;
}

void tira_do_balde(No *x) {
    No **p = &balde[x->cep % BALDES];
    while (*p != x) p = &(*p)->irmao;
    *p = x->irmao;
}

// devolve 1 se foi acerto
int consulta(int cep) {
    No *x = acha(cep);
    if (x != NULL) {
        desliga(x);
        na_frente(x);
        return 1;
    }
    if (tamanho == CAP) { // sai o usado há mais tempo: o do fundo
        No *velho = fundo;
        desliga(velho);
        tira_do_balde(velho);
        free(velho);
        tamanho--;
    }
    x = malloc(sizeof(No));
    if (x == NULL) exit(1);
    x->cep = cep;
    x->irmao = balde[cep % BALDES];
    balde[cep % BALDES] = x;
    na_frente(x);
    tamanho++;
    return 0;
}

// a versão simples, O(CAP) por consulta, para conferir
int simples(int v[], int *n, int cep) {
    int i = 0;
    while (i < *n && v[i] != cep) i++;
    int acerto = i < *n;
    if (!acerto) {
        if (*n == CAP) i = CAP - 1;
        else i = (*n)++;
    }
    for (; i > 0; i--) v[i] = v[i - 1];
    v[0] = cep;
    return acerto;
}

int main(void) {
    int pedidos[] = {69050, 69060, 69050, 69077, 69083, 69060, 69050, 69083, 69091, 69077};
    int acertos = 0;
    for (int k = 0; k < 10; k++) {
        int a = consulta(pedidos[k]);
        acertos += a;
        printf("%d %-6s cache:", pedidos[k], a ? "acerto" : "falta");
        for (No *x = frente; x != NULL; x = x->prox) printf(" %d", x->cep);
        printf("\n");
    }
    printf("Acertos: %d de 10\n", acertos);

    // conferência com 5000 consultas sorteadas entre 8 CEPs
    int v[CAP], n = 0, iguais = 1, a1 = 0;
    unsigned s = 99;
    for (int k = 0; k < 5000; k++) {
        s = s * 1103515245u + 12345u;
        int cep = 69000 + (int)((s >> 16) % 8) * 13; // múltiplos de 13: todos no mesmo balde
        int x = consulta(cep), y = simples(v, &n, cep);
        if (x != y) iguais = 0;
        a1 += x;
    }
    printf("5000 consultas: %d acertos, %s a versão simples\n", a1, iguais ? "igual" : "DIFERENTE de");

    while (frente != NULL) {
        No *x = frente;
        frente = x->prox;
        free(x);
    }
    return 0;
}
