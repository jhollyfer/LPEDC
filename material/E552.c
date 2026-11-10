// 0092 · Selection sort
// Exercício E552 · ★★★
//
// Os produtos de uma loja têm uma descrição de 200 bytes, então cada struct
// é pesada de mover:
//
//   typedef struct { int codigo; double preco; char descricao[200]; } Produto;
//
//   {11, 249.90, "Fone sem fio"}, {12, 89.90, "Mouse"},
//   {13, 1299.00, "Monitor 24"}, {14, 159.90, "Teclado"},
//   {15, 49.90, "Mousepad"}
//
// Mostre os produtos do mais barato ao mais caro SEM mexer no vetor loja.
// Truque: crie int ordem[5] = {0, 1, 2, 3, 4} e ordene ESSE vetor com
// selection sort, comparando loja[ordem[j]].preco. É a ORDENAÇÃO INDIRETA.
// (O 216 é o tamanho do Produto numa máquina de 64 bits comum.)
//
//   Saída esperada:
//   Do mais barato ao mais caro:
//   15 Mousepad      R$   49.90
//   12 Mouse         R$   89.90
//   14 Teclado       R$  159.90
//   11 Fone sem fio  R$  249.90
//   13 Monitor 24    R$ 1299.00
//   loja[0] continua sendo: Fone sem fio
//   3 trocas de 4 bytes, em vez de 216 bytes
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
