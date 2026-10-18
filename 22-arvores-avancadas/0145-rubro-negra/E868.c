// 0145 · Rubro-negra esquerdista (LLRB)
// Exercício E868 · ★★☆
//
// Estenda o programa. A eleição do síndico usa uma rubro-negra para guardar
// os números votados, mas a inserção abaixo IGNORA número repetido, e a
// apuração precisa contar. Faça três mudanças:
// 1. em insere, quando o número já existir, some 1 em qtd;
// 2. escreva apura(r): mostra cada número votado, em ordem crescente, com a
//  quantidade de votos ("voto" no singular quando for 1);
// 3. escreva vencedor(r): devolve o nó com mais votos.
//
//   Saída esperada:
//   12: 3 votos
//   13: 2 votos
//   30: 2 votos
//   45: 4 votos
//   99: 1 voto
//   Vencedor: 45 com 4 de 12 votos
//
// Dicas:
// 1. A contagem cabe no else que hoje não faz nada (chave igual). Repare
//    que novo() já começa qtd em 1.
// 2. apura é um percurso em ordem. vencedor compara o nó com o melhor de
//    cada lado (cuidado com os NULL).
// 3. Resposta esperada: a saída acima. A árvore guarda 5 nós, não 12: o
//    tamanho dela depende dos números diferentes, não do total de votos.
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Voto {
    int numero;
    int qtd;
    bool vermelho;
    struct Voto *esq, *dir;
} Voto;

bool vermelho(const Voto *v) {
    return v != NULL && v->vermelho;
}

Voto *novo(int numero) {
    Voto *v = malloc(sizeof(Voto));
    if (v == NULL) {
        exit(1);
    }
    v->numero = numero;
    v->qtd = 1;
    v->vermelho = true;
    v->esq = v->dir = NULL;
    return v;
}

Voto *vira_esq(Voto *h) {
    Voto *x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->vermelho = h->vermelho;
    h->vermelho = true;
    return x;
}

Voto *vira_dir(Voto *h) {
    Voto *x = h->esq;
    h->esq = x->dir;
    x->dir = h;
    x->vermelho = h->vermelho;
    h->vermelho = true;
    return x;
}

Voto *insere(Voto *h, int numero) {
    if (h == NULL) {
        return novo(numero);
    }
    if (numero < h->numero) {
        h->esq = insere(h->esq, numero);
    } else if (numero > h->numero) {
        h->dir = insere(h->dir, numero);
    } else {
        // número repetido: hoje não faz nada
    }
    if (vermelho(h->dir) && !vermelho(h->esq)) {
        h = vira_esq(h);
    }
    if (vermelho(h->esq) && vermelho(h->esq->esq)) {
        h = vira_dir(h);
    }
    if (vermelho(h->esq) && vermelho(h->dir)) {
        h->vermelho = true;
        h->esq->vermelho = h->dir->vermelho = false;
    }
    return h;
}

void libera(Voto *v) {
    if (v != NULL) {
        libera(v->esq);
        libera(v->dir);
        free(v);
    }
}

int main(void) {
    int urna[] = {45, 12, 45, 13, 30, 12, 45, 13, 45, 30, 12, 99};
    int n = 12;
    Voto *raiz = NULL;
    for (int i = 0; i < n; i++) {
        raiz = insere(raiz, urna[i]);
        raiz->vermelho = false;
    }

    // chame apura e vencedor aqui

    libera(raiz);
    return 0;
}
