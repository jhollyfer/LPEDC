// arvore.h · interface do TAD árvore binária (cada nó guarda um char)
#ifndef ARVORE_H
#define ARVORE_H

// a struct fica à mostra no .h porque os exercícios andam pelos nós
typedef struct No {
    char info;
    struct No *esq; // subárvore da esquerda
    struct No *dir; // subárvore da direita
} No;

// cria um nó com as duas subárvores já prontas (podem ser NULL)
No *arv_cria(char info, No *esq, No *dir);

void arv_pre_ordem(const No *r); // raiz, esquerda, direita
void arv_em_ordem(const No *r);  // esquerda, raiz, direita
void arv_pos_ordem(const No *r); // esquerda, direita, raiz
void arv_por_nivel(const No *r); // nível por nível, da esquerda para a direita

int arv_conta(const No *r);  // quantos nós
int arv_altura(const No *r); // vazia: -1; só a raiz: 0

// libera tudo e devolve NULL: use r = arv_libera(r);
No *arv_libera(No *r);

#endif
