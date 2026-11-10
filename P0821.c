// Lista · Módulo 08 · Tipos compostos
// Exercício P0821 · ★★★ · O catálogo ordenado por três chaves
//
// O catálogo de uma loja de eletrônicos é um vetor de structs:
//
//   typedef enum { CELULAR, NOTEBOOK, FONE } Categoria;
//   typedef struct {
//       char nome[24]; Categoria cat; double preco; int estoque;
//   } Produto;
//
// Ordene com qsort por uma chave COMPOSTA: primeiro a categoria (na ordem do
// enum), depois o preço (do mais barato ao mais caro) e, no empate, o nome
// (ordem alfabética). Depois mostre o catálogo agrupado, com um cabeçalho por
// categoria e, no fim de cada grupo, o valor do estoque (preço x estoque) da
// categoria:
//
//   Saída esperada:
//   == Celulares ==
//     Celular Lite       R$   999.00  x18
//     Celular Alfa       R$  1899.00  x 4
//     Celular Mega 5G    R$  1899.00  x10
//     Estoque: R$ 44568.00
//   == Notebooks ==
//     Notebook Basic     R$  2499.00  x 7
//     Notebook Ultra 14  R$  4299.00  x 3
//     Notebook Pro 16    R$  8999.00  x 1
//     Estoque: R$ 39389.00
//   == Fones ==
//     Fone com fio       R$    39.90  x60
//     Fone Bluetooth X   R$   199.90  x25
//     Fone Gamer         R$   199.90  x12
//     Estoque: R$ 9790.30
//
// Dicas:
// 1. Uma comparação com três critérios: if (a->cat != b->cat) return
//    (int) a->cat - (int) b->cat; depois o preço com (x > y) - (x < y);
//    por fim, strcmp dos nomes.
// 2. Para agrupar depois de ordenar, basta perceber quando a categoria muda
//    de um produto para o próximo: aí fecha o grupo anterior e abre outro.
// 3. Os nomes das categorias: const char *nome_cat[] = {"Celulares",
//    "Notebooks", "Fones"};
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { CELULAR, NOTEBOOK, FONE } Categoria;

typedef struct {
    char nome[24];
    Categoria cat;
    double preco;
    int estoque;
} Produto;

int main(void) {
    Produto v[9] = {
        {"Notebook Ultra 14", NOTEBOOK, 4299.00, 3},
        {"Fone Bluetooth X", FONE, 199.90, 25},
        {"Celular Mega 5G", CELULAR, 1899.00, 10},
        {"Fone com fio", FONE, 39.90, 60},
        {"Celular Lite", CELULAR, 999.00, 18},
        {"Notebook Basic", NOTEBOOK, 2499.00, 7},
        {"Celular Alfa", CELULAR, 1899.00, 4},
        {"Fone Gamer", FONE, 199.90, 12},
        {"Notebook Pro 16", NOTEBOOK, 8999.00, 1},
    };
    (void) v; // apague esta linha quando escrever

    return 0;
}
