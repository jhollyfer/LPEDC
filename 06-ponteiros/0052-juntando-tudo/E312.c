// 0052 · Juntando tudo: o ranking da feira
// Exercício E312 · ★★★
//
// Escreva um "máximo" genérico, que serve para vetores de qualquer tipo:
//
//   void *maximo(void *v, size_t n, size_t tam,
//                int (*cmp)(const void *, const void *))
//
// que devolve o ENDEREÇO do maior elemento (o primeiro, em caso de empate)
// segundo a comparação cmp, ou NULL se n for 0. Teste com
//
//   int pontos[5] = {12, 47, 33, 47, 5};
//   const char *frutas[4] = {"uva", "maca", "laranja", "abacate"};
//
// usando três comparações: inteiros, ordem alfabética (strcmp) e tamanho
// do nome. Mostre o valor e o índice (subtraindo ponteiros). Depois, use o
// endereço devolvido para zerar o maior inteiro dentro do vetor.
//
//   Saída esperada:
//   maior pontuação: 47 (índice 1)
//   última no alfabeto: uva (índice 0)
//   nome mais comprido: laranja (índice 2)
//   depois de zerar: 12 0 33 47 5
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
