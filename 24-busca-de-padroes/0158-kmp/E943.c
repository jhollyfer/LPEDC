// 0158 · KMP
// Exercício E943 · ★☆☆
//
// Complete calcula_pi(p, m, pi): pi[j] é o tamanho da maior borda de
// p[0..j], isto é, do maior prefixo próprio de p[0..j] que também é sufixo
// dele. O main já mostra a tabela de cinco palavras:
//
//   Saída esperada:
//   papapa: 0 0 1 2 3 4
//   cacau: 0 0 1 2 0
//   ovo: 0 0 1
//   pix: 0 0 0
//   tatuta: 0 0 1 0 1 2
//
// Dicas:
// 1. pi[0] é sempre 0: um prefixo PRÓPRIO de uma letra só é vazio.
// 2. Guarde em k o tamanho da borda de p[0..j-1]. Se p[j] == p[k], a borda
//    cresce: k++. Se não, tente a borda menor, k = pi[k - 1], enquanto k > 0.
// 3. Confira "tatuta" no papel: em j = 3 ('u') o k cai de 1 para 0; em
//    j = 4 ('t') volta a 1.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete calcula_pi):

#include <stdio.h>
#include <string.h>

#define MAX 32

void calcula_pi(const char *p, int m, int pi[]) {
    for (int j = 0; j < m; j++) {
        pi[j] = 0; // troque este laço pelo cálculo de verdade
    }
    (void)p;
}

int main(void) {
    const char *palavras[] = {"papapa", "cacau", "ovo", "pix", "tatuta"};
    int pi[MAX];

    for (int w = 0; w < 5; w++) {
        int m = (int) strlen(palavras[w]);
        calcula_pi(palavras[w], m, pi);
        printf("%s:", palavras[w]);
        for (int j = 0; j < m; j++) {
            printf(" %d", pi[j]);
        }
        printf("\n");
    }
    return 0;
}
