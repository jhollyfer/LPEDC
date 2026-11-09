// Lista · Módulo 08 · Tipos compostos
// Exercício P0815 · ★★☆ · O estoque por categoria
//
// Uma loja de material de construção tem produtos de quatro categorias:
//
//   typedef enum { HIDRAULICA, ELETRICA, PINTURA, FERRAGEM,
//                  N_CATEGORIAS } Categoria;
//
// O último nome do enum (N_CATEGORIAS) vale 4 e serve de tamanho para vetores
// indexados pela categoria. Com os produtos abaixo (nome, categoria,
// quantidade, preço), calcule, num vetor de N_CATEGORIAS posições, quantos
// itens e quanto dinheiro há em estoque em cada categoria, e mostre a
// categoria com mais dinheiro parado:
//
//   Tubo PVC 25mm      HIDRAULICA  40  12.90
//   Fio 2,5mm (rolo)   ELETRICA    15  189.00
//   Tinta 18L          PINTURA      8  329.90
//   Registro 3/4       HIDRAULICA  22  45.50
//   Disjuntor 20A      ELETRICA    30  28.00
//   Parafuso (cento)   FERRAGEM    60  9.80
//   Rolo de lã         PINTURA     25  24.90
//
//   Saída esperada:
//    62 itens  R$  1517.00  Hidráulica
//    45 itens  R$  3675.00  Elétrica
//    33 itens  R$  3261.70  Pintura
//    60 itens  R$   588.00  Ferragem
//   Mais dinheiro parado: Elétrica
//
// Dicas:
// 1. typedef struct { char nome[20]; Categoria cat; int qtd; double preco; }
//    Produto;
// 2. int itens[N_CATEGORIAS] = {0}; double valor[N_CATEGORIAS] = {0}; e,
//    para cada produto, itens[p.cat] += p.qtd.
// 3. Os nomes vêm de um vetor de strings na mesma ordem do enum:
//    const char *nome_cat[N_CATEGORIAS] = {"Hidráulica", ...};
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef enum { HIDRAULICA, ELETRICA, PINTURA, FERRAGEM, N_CATEGORIAS } Categoria;

int main(void) {

    return 0;
}
