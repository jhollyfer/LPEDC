// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2411 · ★★☆ · A tabela π atrasada
//
// Ache o bug. O KMP abaixo conta o refrão "tumtum" na batucada e "abab"
// numa sequência, mas perde as ocorrências que se sobrepõem. A tabela π
// sai errada; o resto do KMP está certo:
//
//   Saída que aparece:
//   pi de tumtum: 0 0 0 0 1 2
//     achou em 0
//     achou em 11
//   total: 2
//   pi de abab: 0 0 0 1
//     achou em 0
//     achou em 4
//   total: 2
//
// O erro está na ordem de duas linhas da calcula_pi. Conserte.
//
//   Saída esperada:
//   pi de tumtum: 0 0 0 1 2 3
//     achou em 0
//     achou em 3
//     achou em 11
//   total: 3
//   pi de abab: 0 0 1 2
//     achou em 0
//     achou em 2
//     achou em 4
//   total: 3
//
// Dicas:
// 1. Calcule à mão o pi de "abab": pi[2] tem que ser 1 ("a") e pi[3], 2
//    ("ab"). Cada valor errado é exatamente 1 a menos que o certo.
// 2. pi[j] é a borda de p[0..j], que inclui a letra j. A borda só fica
//    certa DEPOIS de testar se p[j] estende a borda anterior.
// 3. Resposta esperada: grave pi[j] = k depois do if que faz k++; saem 3
//    ocorrências em cada busca.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

void calcula_pi(const char *p, int m, int pi[]) {
    pi[0] = 0;
    int k = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) k = pi[k - 1];
        pi[j] = k;
        if (p[j] == p[k]) k++;
    }
}

int kmp(const char *t, const char *p) {
    int n = (int)strlen(t), m = (int)strlen(p), pi[64], k = 0, achou = 0;
    calcula_pi(p, m, pi);
    printf("pi de %s:", p);
    for (int j = 0; j < m; j++) printf(" %d", pi[j]);
    printf("\n");
    for (int i = 0; i < n; i++) {
        while (k > 0 && t[i] != p[k]) k = pi[k - 1];
        if (t[i] == p[k]) k++;
        if (k == m) {
            printf("  achou em %d\n", i - m + 1);
            achou++;
            k = pi[k - 1];
        }
    }
    return achou;
}

int main(void) {
    printf("total: %d\n", kmp("tumtumtumtatumtum", "tumtum"));
    printf("total: %d\n", kmp("abababab", "abab"));
    return 0;
}
