// 0162 · Matriz esparsa
// Exercício E970 · ★★☆
//
// Escreva do zero uma matriz esparsa de vendas, sem usar o esparsa.h: uma
// lista encadeada por linha, células ordenadas por coluna, com os campos
// col, valor e prox, e a struct Esparsa (linhas, colunas, nao_zeros e o
// vetor de listas). Faça cria, define (insere no lugar certo ou troca o
// valor), mostra_linha (cada valor com %3d, zeros inclusos) e libera.
// Grave, nesta ordem, as vendas (vendedor, dia, valor) de 2 vendedores em 7
// dias: (0,5,30) (1,4,40) (0,2,20) (1,1,12) (0,0,15). Compile com
// -fsanitize=address: não pode haver vazamento nem acesso inválido.
//
//   Saída esperada:
//   Vendedor 0: 15  0 20  0  0 30  0
//   Vendedor 1:  0 12  0  0 40  0  0
//   Células: 5
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int col, valor;
    struct Celula *prox;
} Celula;

typedef struct {
    int linhas, colunas, nao_zeros;
    Celula **linha;
} Esparsa;

int main(void) {

    return 0;
}
