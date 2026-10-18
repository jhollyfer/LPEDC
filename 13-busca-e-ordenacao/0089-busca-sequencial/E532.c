// 0089 · Busca sequencial
// Exercício E532 · ★★☆
//
// O estoque do mercadinho é um vetor de structs:
//
//   typedef struct { int codigo; char nome[20]; double preco; } Produto;
//
//   {1010, "Arroz 5kg", 27.50}, {2050, "Café 500g", 18.90},
//   {3300, "Feijão 1kg", 8.40}, {4120, "Leite 1L", 5.20}
//
// Escreva Produto *busca_produto(Produto v[], int n, int codigo), que devolve
// o ENDEREÇO do produto dentro do vetor (ou NULL). No main, busque 2050,
// mostre o produto e dê um reajuste de 10% pelo ponteiro devolvido. Depois
// mostre estoque[1] direto do vetor e busque 9999.
//
//   Saída esperada:
//   2050 Café 500g R$ 18.90
//   No vetor: Café 500g R$ 20.79
//   9999: não cadastrado
//
// Dicas:
// 1. return &v[i]; devolve o endereço da gaveta i, não uma cópia.
// 2. Com o ponteiro, p->preco = p->preco * 1.10 muda o próprio vetor.
// 3. Sempre teste p != NULL antes de usar p->.
// 4. Resposta esperada: a saída acima (18,90 * 1,10 = 20,79).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
