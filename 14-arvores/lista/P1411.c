// Lista · Módulo 14 · Árvores
// Exercício P1411 · ★★☆ · Sucessor e antecessor sem ponteiro para o pai
//
// A agenda de um consultório guarda os horários (em minutos) numa BST cujos
// nós NÃO têm ponteiro para o pai. O main insere 50, 30, 70, 20, 40, 60, 80,
// 35, 45, 65. Escreva, sem recursão, descendo a partir da raiz:
//
//   int sucessor(const No *r, int x)     menor chave MAIOR que x, ou -1
//   int antecessor(const No *r, int x)   maior chave MENOR que x, ou -1
//
// Mostre os dois para 40, 45, 65, 20 e 80.
//
//   Saída esperada:
//   40: antecessor 35, sucessor 45
//   45: antecessor 40, sucessor 50
//   65: antecessor 60, sucessor 70
//   20: antecessor -1, sucessor 30
//   80: antecessor 70, sucessor -1
//
// Dicas:
// 1. Para o sucessor: se x < r->chave, r é um candidato (guarde) e talvez
//    exista um menor que ainda sirva, à esquerda; senão, vá para a direita.
// 2. O antecessor é o espelho: guarde quando x > r->chave e vá para a direita.
// 3. O 45 é folha, então o sucessor dele é um ANCESTRAL (o 50, o primeiro de
//    quem o 45 está à esquerda). É o caso que a prova adora.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *esq, *dir;
} No;

No *insere(No *r, int chave) {
    if (r == NULL) {
        No *p = malloc(sizeof(No));
        if (p == NULL) {
            exit(1);
        }
        p->chave = chave;
        p->esq = p->dir = NULL;
        return p;
    }
    if (chave < r->chave) {
        r->esq = insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = insere(r->dir, chave);
    }
    return r;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    int horarios[] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65};
    No *raiz = NULL;
    for (int i = 0; i < 10; i++) {
        raiz = insere(raiz, horarios[i]);
    }

    libera(raiz);
    return 0;
}
