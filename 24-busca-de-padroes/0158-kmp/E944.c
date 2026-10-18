// 0158 · KMP
// Exercício E944 · ★☆☆
//
// A lista de compras virou "ananas, banana e mais banana". Escreva
// int kmp(const char *texto, const char *padrao), que mostra as posições de
// todas as ocorrências (inclusive as sobrepostas) e devolve o total. Use a
// calcula_pi pronta e procure "ana":
//
//   Saída esperada:
//   posições: 0 2 9 11 23 25
//   total: 6
//
// Dicas:
// 1. k guarda quantas letras do padrão já casaram. Para cada texto[i]:
//    enquanto k > 0 e texto[i] != padrao[k], faça k = pi[k - 1]; depois, se
//    texto[i] == padrao[k], k++.
// 2. Quando k chega a m, a ocorrência começou em i - m + 1.
// 3. Depois de achar, NÃO zere o k: faça k = pi[m - 1]. É isso que encontra
//    o "ana" da posição 2, que divide o 'a' com o da posição 0.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define MAX 32

void calcula_pi(const char *p, int m, int pi[]) {
    int k = 0;
    pi[0] = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) {
            k = pi[k - 1];
        }
        if (p[j] == p[k]) {
            k++;
        }
        pi[j] = k;
    }
}

int main(void) {

    return 0;
}
