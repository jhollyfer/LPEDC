// Lista · Módulo 08 · Tipos compostos
// Exercício P0811 · ★★☆ · O cardápio em duas ordens
//
// A lanchonete guarda o cardápio num vetor de structs:
//
//   typedef struct { char nome[24]; double preco; int calorias; } Item;
//
//   X-Caboquinho      22.90  780 kcal     Tapioca           12.00  420 kcal
//   Pastel de carne    9.50  510 kcal     Açaí 500 ml       18.00  640 kcal
//   Suco de cupuaçu    8.00  190 kcal     Misto quente       9.50  380 kcal
//
// (o vetor já está pronto no esqueleto). Ordene com qsort duas vezes: primeiro
// em ordem alfabética do nome; depois
// pelo preço (do mais barato ao mais caro; no empate, o de menos calorias
// primeiro). Mostre as duas listas:
//
//   Saída esperada:
//   Por nome:
//     R$ 18.00  640 kcal  Açaí 500 ml
//     R$  9.50  380 kcal  Misto quente
//     R$  9.50  510 kcal  Pastel de carne
//     R$  8.00  190 kcal  Suco de cupuaçu
//     R$ 12.00  420 kcal  Tapioca
//     R$ 22.90  780 kcal  X-Caboquinho
//   Por preço:
//     R$  8.00  190 kcal  Suco de cupuaçu
//     R$  9.50  380 kcal  Misto quente
//     R$  9.50  510 kcal  Pastel de carne
//     R$ 12.00  420 kcal  Tapioca
//     R$ 18.00  640 kcal  Açaí 500 ml
//     R$ 22.90  780 kcal  X-Caboquinho
//
// Dicas:
// 1. A comparação recebe o endereço de cada Item: const Item *a = pa;
//    e compara a->nome, a->preco...
// 2. Para double, não devolva a->preco - b->preco: a conversão para int
//    corta a diferença (0.50 vira 0). Use (a->preco > b->preco) -
//    (a->preco < b->preco).
// 3. qsort(cardapio, 6, sizeof cardapio[0], por_nome); — o qsort move a
//    struct inteira (36 ou 40 bytes) a cada troca.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[24];
    double preco;
    int calorias;
} Item;

int main(void) {
    Item cardapio[6] = {{"X-Caboquinho", 22.90, 780}, {"Tapioca", 12.00, 420},
                        {"Pastel de carne", 9.50, 510}, {"Açaí 500 ml", 18.00, 640},
                        {"Suco de cupuaçu", 8.00, 190}, {"Misto quente", 9.50, 380}};
    (void) cardapio; // apague esta linha quando escrever

    return 0;
}
