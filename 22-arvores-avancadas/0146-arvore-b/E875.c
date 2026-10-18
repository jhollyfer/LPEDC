// 0146 · Árvore B
// Exercício E875 · ★★★
//
// Ache o bug. Esta árvore B escrita à mão (páginas de até 3 chaves, como no
// TAD) recebe os protocolos de 10 a 120, de 10 em 10. Ela tem UM erro na
// descida da inserção. Rode: o percurso em ordem sai fora de ordem e a busca
// por chaves que foram inseridas falha. Conserte e rode de novo.
//
//   Saída esperada:
//   em ordem: 10 20 30 40 50 60 70 80 90 100 110 120
//   em ordem? sim
//   achou 10, 60 e 120? sim sim sim
//
// Dicas:
// 1. Desenhe a árvore com 10, 20 e 30 e insira o 40: a raiz cheia se divide
//    e o 20 sobe. Por qual filho do 20 o 40 deveria descer?
// 2. Depois de dividir o filho i, a chave que subiu fica em p->chave[i], e
//    o filho i + 1 é a metade nova, com as chaves maiores que ela.
// 3. Resposta esperada: em poe_em_nao_cheia, logo depois de
//    "parte(p, i);" falta "if (chave > p->chave[i]) { i++; }". Sem ele, a
//    chave sempre desce pela metade da esquerda, mesmo sendo maior que a que
//    subiu. Com a linha, a saída é a de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define T 2
#define MAX (2 * T - 1)

typedef struct Pagina {
    int n;
    int chave[MAX];
    struct Pagina *filho[MAX + 1];
    bool folha;
} Pagina;

Pagina *nova(bool folha) {
    Pagina *p = malloc(sizeof(Pagina));
    if (p == NULL) {
        exit(1);
    }
    p->n = 0;
    p->folha = folha;
    return p;
}

void parte(Pagina *pai, int i) {
    Pagina *y = pai->filho[i];
    Pagina *z = nova(y->folha);
    z->n = T - 1;
    for (int j = 0; j < T - 1; j++) {
        z->chave[j] = y->chave[j + T];
    }
    if (!y->folha) {
        for (int j = 0; j < T; j++) {
            z->filho[j] = y->filho[j + T];
        }
    }
    y->n = T - 1;
    for (int j = pai->n; j > i; j--) {
        pai->filho[j + 1] = pai->filho[j];
    }
    pai->filho[i + 1] = z;
    for (int j = pai->n - 1; j >= i; j--) {
        pai->chave[j + 1] = pai->chave[j];
    }
    pai->chave[i] = y->chave[T - 1];
    pai->n++;
}

void poe_em_nao_cheia(Pagina *p, int chave) {
    int i = p->n - 1;
    if (p->folha) {
        while (i >= 0 && chave < p->chave[i]) {
            p->chave[i + 1] = p->chave[i];
            i--;
        }
        p->chave[i + 1] = chave;
        p->n++;
        return;
    }
    while (i >= 0 && chave < p->chave[i]) {
        i--;
    }
    i++;
    if (p->filho[i]->n == MAX) {
        parte(p, i);
    }
    poe_em_nao_cheia(p->filho[i], chave);
}

Pagina *poe(Pagina *raiz, int chave) {
    if (raiz == NULL) {
        raiz = nova(true);
    }
    if (raiz->n == MAX) {
        Pagina *s = nova(false);
        s->filho[0] = raiz;
        parte(s, 0);
        raiz = s;
    }
    poe_em_nao_cheia(raiz, chave);
    return raiz;
}

bool acha(const Pagina *p, int chave) {
    while (p != NULL) {
        int i = 0;
        while (i < p->n && chave > p->chave[i]) {
            i++;
        }
        if (i < p->n && chave == p->chave[i]) {
            return true;
        }
        p = p->folha ? NULL : p->filho[i];
    }
    return false;
}

// percorre em ordem guardando as chaves em v; devolve quantas guardou
int em_ordem(const Pagina *p, int v[], int k) {
    for (int i = 0; i < p->n; i++) {
        if (!p->folha) {
            k = em_ordem(p->filho[i], v, k);
        }
        v[k++] = p->chave[i];
    }
    if (!p->folha) {
        k = em_ordem(p->filho[p->n], v, k);
    }
    return k;
}

void libera(Pagina *p) {
    if (!p->folha) {
        for (int i = 0; i <= p->n; i++) {
            libera(p->filho[i]);
        }
    }
    free(p);
}

int main(void) {
    Pagina *raiz = NULL;
    for (int c = 10; c <= 120; c += 10) {
        raiz = poe(raiz, c);
    }
    int v[12];
    int k = em_ordem(raiz, v, 0);
    bool ordenado = true;
    printf("em ordem:");
    for (int i = 0; i < k; i++) {
        printf(" %d", v[i]);
        if (i > 0 && v[i - 1] > v[i]) {
            ordenado = false;
        }
    }
    printf("\nem ordem? %s\n", ordenado ? "sim" : "não");
    printf("achou 10, 60 e 120? %s %s %s\n", acha(raiz, 10) ? "sim" : "não",
           acha(raiz, 60) ? "sim" : "não", acha(raiz, 120) ? "sim" : "não");
    libera(raiz);
    return 0;
}
