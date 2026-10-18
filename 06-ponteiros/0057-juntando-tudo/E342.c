// 0057 · Juntando tudo: o ranking da feira
// Exercício E342 · ★★★
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
// Dicas:
// 1. Ande pelo vetor com const unsigned char *: o i-ésimo está em
//    base + i * tam. Guarde o endereço do maior até agora.
// 2. Para as frutas, cada elemento é um const char *: o resultado de
//    maximo é, na verdade, um const char ** (converta para usar).
// 3. Para o índice: (const int *)m - pontos.
// 4. Resposta esperada: as quatro linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
