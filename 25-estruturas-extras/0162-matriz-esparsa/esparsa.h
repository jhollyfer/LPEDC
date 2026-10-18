// esparsa.h · interface do TAD matriz esparsa (uma lista por linha)
#ifndef ESPARSA_H
#define ESPARSA_H

// a struct fica à mostra no .h porque os exercícios andam pelas listas
typedef struct Celula {
    int col;             // coluna da célula
    int valor;           // nunca é 0: zero não se guarda
    struct Celula *prox; // próxima célula da mesma linha (coluna maior)
} Celula;

typedef struct {
    int linhas;
    int colunas;
    int nao_zeros;  // quantas células existem
    Celula **linha; // vetor de ponteiros: linha[i] é a lista da linha i
} Esparsa;

// cria a matriz linhas x colunas com tudo zero (nenhuma célula)
Esparsa *esp_cria(int linhas, int colunas);

// m[i][j] = valor; valor 0 apaga a célula, se ela existir
void esp_define(Esparsa *m, int i, int j, int valor);

// devolve m[i][j]; célula que não existe vale 0
int esp_valor(const Esparsa *m, int i, int j);

void esp_mostra(const Esparsa *m); // imprime a matriz cheia, com os zeros
void esp_libera(Esparsa *m);

#endif
