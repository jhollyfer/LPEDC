// 0158 · KMP
// Exercício E946 · ★★☆
//
// O programa abaixo conta as comparações de letra da força bruta num texto
// de 29 'a' seguidos de um 'b'. Estenda: escreva
// long kmp(const char *t, const char *p, int *achados), que conta cada
// comparação t[i] com p[k] (as do recuo também) e as ocorrências, e mostre os
// dois lado a lado no main:
//
//   Saída esperada:
//   aaaab: força bruta 130, KMP 55 (achou 1 e 1)
//   baaaa: força bruta  26, KMP 30 (achou 0 e 0)
//   aaaaa: força bruta 130, KMP 34 (achou 25 e 25)
//
// Dicas:
// 1. Um jeito limpo de contar: para cada i, um laço while (1) que compara
//    (comp++) t[i] com p[k]; se bateu, k++ e sai; se k == 0, sai; senão,
//    k = pi[k - 1] e compara de novo.
// 2. Repare que o KMP nunca passa de 2n = 60 comparações: cada recuo gasta
//    um k que algum avanço criou antes.
// 3. Em "baaaa" o KMP faz MAIS comparações que a força bruta: em texto sem
//    repetição, a força bruta já falha na primeira letra. O ganho do KMP é
//    a garantia no pior caso.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (acrescente a kmp e mude o main):

#include <stdio.h>
#include <string.h>

#define MAX 32

long forca_bruta(const char *t, const char *p, int *achados) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    long comp = 0;
    *achados = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) {
            comp++;
            if (t[i + j] != p[j]) {
                break;
            }
            j++;
        }
        if (j == m) {
            (*achados)++;
        }
    }
    return comp;
}

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
    const char *texto = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaab"; // 29 'a' e um 'b'
    const char *padroes[] = {"aaaab", "baaaa", "aaaaa"};
    int a1;

    for (int k = 0; k < 3; k++) {
        long fb = forca_bruta(texto, padroes[k], &a1);
        printf("%s: força bruta %3ld (achou %d)\n", padroes[k], fb, a1);
    }
    return 0;
}
