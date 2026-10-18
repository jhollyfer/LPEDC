// 0062 · Ponteiro para struct
// Exercício E371 · ★★★
//
// Leia produtos (nome sem espaço e preço) até a entrada acabar, guardando
// num vetor de structs no heap que começa com capacidade 2 e dobra com
// realloc quando enche. Mostre cada vez que a capacidade crescer e, no fim, a
// lista e o total.
//
// Para testar:
//
//   printf 'Arroz 27.90\nFeijao 8.49\nCafe 18.90\nOleo 7.99\nAcucar 4.59\n' | ~/LPEDC/rodar 08-structs/0062-ponteiro-para-struct/E371.c
//
//   Saída esperada:
//   capacidade: 2 -> 4
//   capacidade: 4 -> 8
//   5 produtos:
//     Arroz      R$ 27.90
//     Feijao     R$ 8.49
//     Cafe       R$ 18.90
//     Oleo       R$ 7.99
//     Acucar     R$ 4.59
//   Total: R$ 67.87
//
// Dicas:
// 1. Guarde três coisas: Produto *v, int n (quantos tem) e int cap.
// 2. Leia com while (scanf("%19s %lf", nome, &preco) == 2). Leia numa
//    variável Produto temporária e só depois copie para v[n].
// 3. Cresça com um ponteiro temporário: Produto *novo = realloc(v, ...); se
//    der NULL, o v antigo continua valendo e precisa de free.
// 4. Resposta esperada: a saída acima, e um free(v) no fim.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
