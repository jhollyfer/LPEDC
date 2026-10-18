// 0066 · Vetor de structs
// Exercício E394 · ★★☆
//
// Uma loja tem estes celulares em estoque:
//
//   Moto G     R$ 1299.00
//   Galaxy A   R$ 1899.00
//   iPhone     R$ 5499.00
//   Redmi      R$ 999.00
//
// Use qsort (assunto 0055) duas vezes: primeiro em ordem alfabética do nome,
// depois do mais caro para o mais barato. Mostre a lista após cada ordenação.
//
//   Saída esperada:
//   Por nome:
//     Galaxy A   R$ 1899.00
//     Moto G     R$ 1299.00
//     Redmi      R$ 999.00
//     iPhone     R$ 5499.00
//   Por preço:
//     iPhone     R$ 5499.00
//     Galaxy A   R$ 1899.00
//     Moto G     R$ 1299.00
//     Redmi      R$ 999.00
//
// Dicas:
// 1. A comparadora recebe const void *: copie o elemento com
//    Celular x = *(const Celular *)a; e compare os campos.
// 2. Por nome: return strcmp(x.nome, y.nome);
// 3. Por preço decrescente: cuidado, preço é double. Não devolva y.preco -
//    x.preco (0.5 viraria 0 no int); use if/else e devolva -1, 0 ou 1.
// 4. Resposta esperada: a saída acima. O iPhone vai para o fim na ordem
//    alfabética porque strcmp compara códigos ASCII: 'i' minúsculo (105) vem
//    depois de todas as maiúsculas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
