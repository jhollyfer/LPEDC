// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2203 · ★☆☆ · Vermelho com filho vermelho
//
// Na rubro-negra do Cormen (a clássica, não a esquerdista), cada NÓ é
// vermelho ou preto, e uma das regras é: um nó vermelho não tem filho
// vermelho. O programa abaixo monta à mão duas árvores (V é vermelho, P é
// preto) e chama sem_vv(r), que devia devolver 1 se a regra vale em toda a
// árvore e 0 se algum vermelho tem filho vermelho (mostrando qual). Complete
// sem_vv. As árvores estão escritas como raiz(esquerda, direita), com - no
// lugar de um filho vazio:
//
//   Árvore 1: 20P(10V(5P, 15P), 30V(25P, -))
//   Árvore 2: 20P(10P, 30V(25V, 40P))
//
//   Saída esperada:
//   Árvore 1:
//     regra vale
//   Árvore 2:
//     30 vermelho tem filho vermelho
//     regra quebrada
//
// Dicas:
// 1. Árvore vazia: 1. Se r é vermelho e algum filho existe e é vermelho,
//    mostre e devolva 0.
// 2. Senão, a resposta é sem_vv(esq) && sem_vv(dir).
// 3. Resposta esperada: a árvore 1 vale; na 2, o 30 vermelho tem o filho
//    25 vermelho.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    bool vermelho;
    struct No *esq, *dir;
} No;

No *no(int chave, char cor, No *esq, No *dir) {
    No *n = malloc(sizeof *n);
    if (n == NULL) {
        exit(1);
    }
    *n = (No){chave, cor == 'V', esq, dir};
    return n;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int sem_vv(const No *r) {
    (void)r;
    // COMPLETE AQUI
    return 1;
}

int main(void) {
    No *a1 = no(20, 'P', no(10, 'V', no(5, 'P', NULL, NULL), no(15, 'P', NULL, NULL)),
                no(30, 'V', no(25, 'P', NULL, NULL), NULL));
    No *a2 = no(20, 'P', no(10, 'P', NULL, NULL),
                no(30, 'V', no(25, 'V', NULL, NULL), no(40, 'P', NULL, NULL)));
    printf("Árvore 1:\n");
    printf("  %s\n", sem_vv(a1) ? "regra vale" : "regra quebrada");
    printf("Árvore 2:\n");
    printf("  %s\n", sem_vv(a2) ? "regra vale" : "regra quebrada");
    libera(a1);
    libera(a2);
    return 0;
}
