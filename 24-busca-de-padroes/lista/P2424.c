// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2424 · ★★★ · O SOS que some
//
// Ache o bug. O rádio do barco procura "sos" no sinal recebido. O KMP
// abaixo compila e roda, mas perde pedidos de socorro que se encostam:
//
//   Saída que aparece:
//   sososos: 0 4 (2)
//   xsosxsososx: 1 5 (2)
//   ososo: 1 (1)
//   aaaaa: 0 2 (2)
//
// Em "sososos", o "sos" da posição 2 usa o último s do primeiro. O erro
// está numa linha só. Conserte.
//
//   Saída esperada:
//   sososos: 0 2 4 (3)
//   xsosxsososx: 1 5 7 (3)
//   ososo: 1 (1)
//   aaaaa: 0 1 2 3 (4)
//
// Dicas:
// 1. O que o programa faz com k logo depois de achar uma ocorrência? O que
//    ele "esquece" do que já leu?
// 2. Depois de casar o padrão inteiro, o fim dele pode ser o começo da
//    próxima ocorrência: quanto? Exatamente a borda pi[m - 1].
// 3. Resposta esperada: troque k = 0 por k = pi[k - 1]; sososos tem 3
//    ocorrências e aaaaa, 4.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

void calcula_pi(const char *p, int m, int pi[]) {
    pi[0] = 0;
    int k = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) k = pi[k - 1];
        if (p[j] == p[k]) k++;
        pi[j] = k;
    }
}

int kmp(const char *t, const char *p) {
    int n = (int)strlen(t), m = (int)strlen(p), pi[64], k = 0, achou = 0;
    calcula_pi(p, m, pi);
    for (int i = 0; i < n; i++) {
        while (k > 0 && t[i] != p[k]) k = pi[k - 1];
        if (t[i] == p[k]) k++;
        if (k == m) {
            printf(" %d", i - m + 1);
            achou++;
            k = 0;
        }
    }
    return achou;
}

int main(void) {
    const char *sinais[] = {"sososos", "xsosxsososx", "ososo"};
    for (int s = 0; s < 3; s++) {
        printf("%s:", sinais[s]);
        int n = kmp(sinais[s], "sos");
        printf(" (%d)\n", n);
    }
    printf("aaaaa:");
    printf(" (%d)\n", kmp("aaaaa", "aa"));
    return 0;
}
