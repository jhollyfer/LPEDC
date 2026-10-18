// 0051 · void * e cast
// Exercício E303 · ★★☆
//
// Escreva sua versão do memset para zerar qualquer coisa:
//
//   void zera(void *p, size_t tam)
//
// que coloca 0 em cada um dos tam bytes a partir de p. Teste zerando o
// vetor de placar int gols[5] = {2, 1, 3, 0, 4} e a variável double saldo
// = 99.90. Mostre antes e depois.
//
//   Saída esperada:
//   antes: 2 1 3 0 4 | 99.90
//   depois: 0 0 0 0 0 | 0.00
//
// Dicas:
// 1. Dentro, unsigned char *b = p; e um for de 0 a tam.
// 2. Para o vetor inteiro, o tamanho é sizeof gols (20 bytes); para o
//    double, sizeof saldo.
// 3. Resposta esperada: tudo vira 0 (todos os bytes 0 dão 0 tanto no int
//    quanto no double).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
