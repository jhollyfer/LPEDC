// arvgen.h · interface do TAD árvore geral (primeiro filho / próximo irmão)
#ifndef ARVGEN_H
#define ARVGEN_H

typedef struct NoG {
    char nome[20];
    int valor;          // o valor do próprio nó (um grupo pode ter 0)
    struct NoG *filho;  // o primeiro filho
    struct NoG *irmao;  // o próximo irmão (mesmo pai)
} NoG;

NoG *ag_cria(const char *nome, int valor);

// pendura um filho novo no FIM da fila de irmãos e devolve o filho
NoG *ag_adiciona(NoG *pai, const char *nome, int valor);

// procura o nome em r e nos descendentes de r; NULL se não achar
NoG *ag_busca(NoG *r, const char *nome);

int ag_grau(const NoG *n);    // quantos filhos n tem
int ag_total(const NoG *r);   // soma dos valores de r e de todos os descendentes
int ag_conta(const NoG *r);   // quantos nós tem a subárvore de r
int ag_altura(const NoG *r);  // em arestas: folha tem altura 0

// mostra a subárvore de r, recuada por nível, com o total de cada nó
void ag_mostra(const NoG *r);

// libera r e todos os descendentes (os irmãos de r ficam)
void ag_libera(NoG *r);

#endif
