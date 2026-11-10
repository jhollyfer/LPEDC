// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2220 · ★★☆ · O tamanho de sapato mais próximo
//
// A sapataria guarda os números que tem em estoque numa rubro-negra
// esquerdista: 34, 35, 37, 38, 40, 41, 43 e 45. Quando o cliente pede um
// número que acabou, o vendedor oferece o PISO (o maior em estoque <= ao
// pedido) e o TETO (o menor em estoque >= ao pedido). Complete piso(r, x) e
// teto(r, x), que devolvem -1 quando não existe, usando a ordem da árvore
// de busca: no piso, se x < chave, a resposta está à esquerda; se não, a
// chave é candidata e talvez haja algo melhor à direita.
//
//   Saída esperada:
//   Pedido 36: piso 35, teto 37
//   Pedido 33: piso nenhum, teto 34
//   Pedido 46: piso 45, teto nenhum
//   Pedido 40: piso 40, teto 40
//   Pedido 42: piso 41, teto 43
//
// Dicas:
// 1. piso iterativo: melhor = -1; enquanto r != NULL: se r->chave == x,
//    devolva x; se r->chave < x, melhor = r->chave e vá para a direita;
//    senão, para a esquerda.
// 2. teto é o espelho.
// 3. Resposta esperada: para 36, piso 35 e teto 37; para 33 não há piso;
//    para 46 não há teto; 40 está em estoque.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    bool vermelho; // cor do link que vem do pai
    struct No *esq, *dir;
} No;

bool verm(const No *h) {
    return h != NULL && h->vermelho;
}

No *rot_esq(No *h) {
    No *x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->vermelho = h->vermelho;
    h->vermelho = true;
    return x;
}

No *rot_dir(No *h) {
    No *x = h->esq;
    h->esq = x->dir;
    x->dir = h;
    x->vermelho = h->vermelho;
    h->vermelho = true;
    return x;
}

void inverte(No *h) {
    h->vermelho = !h->vermelho;
    h->esq->vermelho = !h->esq->vermelho;
    h->dir->vermelho = !h->dir->vermelho;
}

No *ins(No *h, int k) {
    if (h == NULL) {
        No *n = malloc(sizeof *n);
        if (n == NULL) {
            exit(1);
        }
        *n = (No){k, true, NULL, NULL};
        return n;
    }
    if (k < h->chave) {
        h->esq = ins(h->esq, k);
    } else if (k > h->chave) {
        h->dir = ins(h->dir, k);
    }
    if (verm(h->dir) && !verm(h->esq)) {
        h = rot_esq(h);
    }
    if (verm(h->esq) && verm(h->esq->esq)) {
        h = rot_dir(h);
    }
    if (verm(h->esq) && verm(h->dir)) {
        inverte(h);
    }
    return h;
}

No *insere(No *r, int k) {
    r = ins(r, k);
    r->vermelho = false;
    return r;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int piso(const No *r, int x) {
    (void)r;
    (void)x;
    // COMPLETE AQUI
    return -1;
}

int teto(const No *r, int x) {
    (void)r;
    (void)x;
    // COMPLETE AQUI
    return -1;
}

int main(void) {
    const int estoque[8] = {34, 35, 37, 38, 40, 41, 43, 45};
    No *r = NULL;
    for (int i = 0; i < 8; i++) {
        r = insere(r, estoque[i]);
    }
    const int pedido[5] = {36, 33, 46, 40, 42};
    for (int i = 0; i < 5; i++) {
        int p = piso(r, pedido[i]), t = teto(r, pedido[i]);
        printf("Pedido %d: ", pedido[i]);
        if (p < 0) {
            printf("piso nenhum, ");
        } else {
            printf("piso %d, ", p);
        }
        if (t < 0) {
            printf("teto nenhum\n");
        } else {
            printf("teto %d\n", t);
        }
    }
    libera(r);
    return 0;
}
