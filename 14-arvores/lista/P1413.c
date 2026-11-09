// Lista · Módulo 14 · Árvores
// Exercício P1413 · ★★☆ · O k-ésimo menor tempo da maratona
//
// Os tempos (em minutos) de 11 corredores foram inseridos numa BST: 212, 185,
// 240, 170, 199, 228, 265, 192, 205, 251, 178. Escreva
// const No *k_esimo(const No *r, int *k), que faz a em ordem e para no
// k-ésimo nó visitado (o k é gasto: cada nó visitado faz (*k)--, e quem
// zera o k é a resposta). Devolve NULL se a árvore tiver menos de k nós.
// Mostre o 1º, o 3º, o 8º, o 11º e o 12º menores e a mediana, o
// ((n + 1) / 2)-ésimo.
//
//   Saída esperada:
//   1º menor: 170 min
//   3º menor: 185 min
//   8º menor: 228 min
//   11º menor: 265 min
//   12º menor: não existe
//   mediana (6º de 11): 205 min
//
// Dicas:
// 1. Procure à esquerda; se achou lá, devolva sem olhar mais nada.
// 2. Senão, (*k)--; se *k chegou a 0, o nó atual é a resposta; senão,
//    procure à direita.
// 3. Passe uma CÓPIA de k (int k = pedido; k_esimo(raiz, &k)), porque ela é
//    modificada.
// 4. Custa O(h + k): não precisa percorrer a árvore toda.
// 5. Resposta esperada: a saída acima.
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
    int tempos[] = {212, 185, 240, 170, 199, 228, 265, 192, 205, 251, 178};
    No *raiz = NULL;
    for (int i = 0; i < 11; i++) {
        raiz = insere(raiz, tempos[i]);
    }

    libera(raiz);
    return 0;
}
