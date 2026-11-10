// Lista · Módulo 14 · Árvores
// Exercício P1421 · ★★★ · Remoção na AVL
//
// O assunto 0101 fez a inserção na AVL. A remoção é a da BST (com o sucessor
// no caso de dois filhos) mais um detalhe: na VOLTA da recursão, cada nó do
// caminho atualiza a altura e gira se ficou desbalanceado. Diferente da
// inserção, uma remoção pode exigir rotação em mais de um nível.
//
// O esqueleto traz o nó, alt, atualiza, fator e as duas rotações. Escreva:
//
//   No *rebalanceia(No *r)   atualiza, olha o fator, gira e guarda o nome da
//                            rotação ("LL", "LR", "RR" ou "RL") na global
//                            rotacao; usada pela inserção E pela remoção
//   No *insere(No *r, int chave)
//   No *remove_chave(No *r, int chave)
//
// Insira 40, 20, 60, 10, 30, 50, 70, 5, 25, 35, 45 e remova 70, 45, 60 e 5,
// mostrando a pré-ordem, a rotação (se houve) e a altura depois de cada
// remoção.
//
//   Saída esperada:
//   início: 40 20 10 5 30 25 35 60 50 45 70
//   sem o 70: 40 20 10 5 30 25 35 50 45 60   (rotação LL)  altura 3
//   sem o 45: 40 20 10 5 30 25 35 50 60  altura 3
//   sem o 60: 20 10 5 40 30 25 35 50   (rotação LL)  altura 3
//   sem o 5: 30 20 10 25 40 35 50   (rotação RL)  altura 2
//
// Dicas:
// 1. Os casos de fator são os mesmos da inserção: > 1 com fator(esq) < 0 é
//    LR; senão LL. < -1 com fator(dir) > 0 é RL; senão RR.
// 2. Na remoção, o fator do filho pode ser 0 (na inserção nunca é). Com 0,
//    use a rotação simples: por isso o teste é fator(esq) < 0, e não <= 0.
// 3. No "sem o 60", a raiz 40 fica com fator +2 e quem sobe é o 20.
// 4. Zere rotacao = "" antes de cada remoção. Mostre com
//    printf("   (rotação %s)", rotacao) e printf("  altura %d\n", raiz->alt).
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave, alt;
    struct No *esq, *dir;
} No;

int alt(const No *p) {
    return p == NULL ? -1 : p->alt;
}

void atualiza(No *p) {
    int he = alt(p->esq), hd = alt(p->dir);
    p->alt = 1 + (he > hd ? he : hd);
}

int fator(const No *p) {
    return alt(p->esq) - alt(p->dir);
}

No *gira_dir(No *r) {
    No *e = r->esq;
    r->esq = e->dir;
    e->dir = r;
    atualiza(r);
    atualiza(e);
    return e;
}

No *gira_esq(No *r) {
    No *d = r->dir;
    r->dir = d->esq;
    d->esq = r;
    atualiza(r);
    atualiza(d);
    return d;
}

const char *rotacao = "";

int main(void) {

    return 0;
}
