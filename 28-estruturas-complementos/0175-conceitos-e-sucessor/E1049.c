// 0175 · Conceitos e sucessor
// Exercício E1049 · ★★★
//
// Ache o bug. O app da rodoviária guarda os horários de saída numa BST com
// ponteiro para o pai e responde "qual é o próximo ônibus depois deste?".
// O sucessor foi escrito à mão e erra justamente quando o horário não tem
// subárvore direita. Rode, compare com a saída esperada e conserte UMA
// condição.
//
//   Saída esperada:
//   depois de 6h15: 6h50
//   depois de 6h50: 7h00
//   depois de 7h00: 7h30
//   depois de 7h30: 8h00
//   depois de 8h00: 9h20
//   depois de 9h20: 10h30
//   depois de 10h30: 12h00
//   depois de 12h00: nenhum
//
// Dicas:
// 1. Desenhe a árvore e siga o 7h30: ele não tem filho direito, então o
//    sucessor é um ancestral. Qual?
// 2. Você sobe enquanto está vindo de um filho DIREITO (o pai é menor que
//    você). O primeiro ancestral alcançado por um filho esquerdo é a
//    resposta.
// 3. Resposta esperada: o while tem que ser "y != NULL && x == y->dir".
//    Com a correção, a saída é a de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

typedef struct Saida {
    int hora;
    struct Saida *esq, *dir, *pai;
} Saida;

Saida *insere(Saida *raiz, int hora) {
    Saida *pai = NULL;
    Saida *x = raiz;
    while (x != NULL) {
        pai = x;
        x = hora < x->hora ? x->esq : x->dir;
    }
    Saida *z = malloc(sizeof(Saida));
    if (z == NULL) {
        exit(1);
    }
    z->hora = hora;
    z->esq = z->dir = NULL;
    z->pai = pai;
    if (pai == NULL) {
        return z;
    }
    if (hora < pai->hora) {
        pai->esq = z;
    } else {
        pai->dir = z;
    }
    return raiz;
}

Saida *minimo(Saida *x) {
    while (x->esq != NULL) {
        x = x->esq;
    }
    return x;
}

Saida *sucessor(Saida *x) {
    if (x->dir != NULL) {
        return minimo(x->dir);
    }
    Saida *y = x->pai;
    while (y != NULL && x == y->esq) {
        x = y;
        y = y->pai;
    }
    return y;
}

void libera(Saida *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    int horas[] = {800, 615, 1030, 700, 650, 920, 1200, 730};
    Saida *raiz = NULL;
    for (int i = 0; i < 8; i++) {
        raiz = insere(raiz, horas[i]);
    }
    // percorre em ordem com uma lista fixa de horários, para não depender
    // do próprio sucessor para andar
    int ordem[] = {615, 650, 700, 730, 800, 920, 1030, 1200};
    for (int i = 0; i < 8; i++) {
        Saida *x = raiz;
        while (x->hora != ordem[i]) {
            x = ordem[i] < x->hora ? x->esq : x->dir;
        }
        Saida *s = sucessor(x);
        printf("depois de %dh%02d: ", x->hora / 100, x->hora % 100);
        if (s == NULL) {
            printf("nenhum\n");
        } else {
            printf("%dh%02d\n", s->hora / 100, s->hora % 100);
        }
    }
    libera(raiz);
    return 0;
}
