// Lista · Módulo 12 · Pilhas e filas
// Exercício P1201 · ★☆☆ · O painel de LEDs em binário
//
// O painel da estação mostra números em binário. Para converter, divida por
// 2 até chegar a zero: os restos saem do bit menos significativo para o
// mais significativo, ou seja, AO CONTRÁRIO da ordem de leitura. Uma pilha
// desinverte. Escreva uma pilha de int sobre vetor (32 posições) com
// empilha, desempilha e vazia, e a função
//
//   void binario(int n)   // mostra n em binário, usando a pilha
//
// Mostre 13, 156, 1024 e 0.
//
//   Saída esperada:
//   13 = 1101
//   156 = 10011100
//   1024 = 10000000000
//   0 = 0
//
// Dicas:
// 1. typedef struct { int v[32]; int n; } Pilha; com n = quantos itens. O
//    topo é v[n - 1].
// 2. Use do { empilha(&p, n % 2); n /= 2; } while (n > 0); para o 0 também
//    gerar um dígito. Depois desempilhe e mostre até a pilha ficar vazia.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
