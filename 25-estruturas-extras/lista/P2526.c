// Lista · Módulo 25 · Estruturas especiais
// Exercício P2526 · ★★★ · A skip list que não sabe se desmontar
//
// Ache o bug. Nesta skip list, cada nó tem um vetor prox alocado à parte,
// com o tamanho exato dos andares dele (economiza memória). Ela monta e
// mostra os andares certinho, mas na hora de desmontar o AddressSanitizer
// para o programa com heap-use-after-free dentro de destroi (é de
// propósito). E, mesmo que não parasse, a memória dos vetores prox
// vazaria. Conserte destroi (faltam duas linhas e uma precisa mudar).
//
//   Saída esperada:
//   andar 5: 640
//   andar 4: 310 640
//   andar 3: 310 640
//   andar 2: 125 310 640 870
//   andar 1: 7 125 310 640 870
//   andar 0: 7 42 125 310 555 640 870 999
//   memória devolvida
//
// Dicas:
// 1. Depois de free(x), ler x->prox[0] é ler memória devolvida. Guarde o
//    próximo ANTES de liberar.
// 2. Cada nó fez dois malloc (o nó e o vetor prox): precisa de dois free,
//    e o do vetor vem antes do do nó.
// 3. Resposta esperada: No *seguinte = x->prox[0]; free(x->prox);
//    free(x); x = seguinte; e o programa termina com "memória devolvida".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

#define MAX 8

typedef struct No {
    int chave;
    int andares;
    struct No **prox; // vetor com exatamente "andares" ponteiros
} No;

typedef struct {
    No *cabeca;
    unsigned semente;
} Skip;

int moeda(Skip *s) {
    s->semente = s->semente * 1103515245u + 12345u;
    return (s->semente >> 16) & 1;
}

No *novo_no(int chave, int andares) {
    No *x = malloc(sizeof(No));
    if (x == NULL) exit(1);
    x->prox = malloc(andares * sizeof(No *));
    if (x->prox == NULL) exit(1);
    x->chave = chave;
    x->andares = andares;
    for (int k = 0; k < andares; k++) x->prox[k] = NULL;
    return x;
}

void insere(Skip *s, int chave) {
    int andares = 1;
    while (andares < MAX && moeda(s) == 1) andares++;
    No *antes[MAX], *x = s->cabeca;
    for (int k = MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL && x->prox[k]->chave < chave) x = x->prox[k];
        antes[k] = x;
    }
    No *novo = novo_no(chave, andares);
    for (int k = 0; k < andares; k++) {
        novo->prox[k] = antes[k]->prox[k];
        antes[k]->prox[k] = novo;
    }
}

void destroi(Skip *s) {
    No *x = s->cabeca;
    while (x != NULL) {
        free(x);
        x = x->prox[0];
    }
}

int main(void) {
    Skip s = {novo_no(0, MAX), 42};
    int pacotes[] = {310, 125, 870, 42, 555, 999, 7, 640};
    for (int k = 0; k < 8; k++) insere(&s, pacotes[k]);
    for (int k = MAX - 1; k >= 0; k--) {
        if (s.cabeca->prox[k] == NULL) continue;
        printf("andar %d:", k);
        for (No *x = s.cabeca->prox[k]; x != NULL; x = x->prox[k]) printf(" %d", x->chave);
        printf("\n");
    }
    destroi(&s);
    printf("memória devolvida\n");
    return 0;
}
