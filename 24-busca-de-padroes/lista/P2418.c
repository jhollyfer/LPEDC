// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2418 · ★★☆ · O KMP passo a passo
//
// O programa abaixo procura "abab" em "abaababcabab" com o KMP, mas não
// mostra nada. Instrumente-o: para cada i, mostre t[i], o k antes de ler a
// letra, o k depois e, quando houver recuo pela tabela, os valores que k
// assumiu em cada recuo. Marque as ocorrências. É o teste de mesa que a
// prova pede.
//
//   Saída esperada:
//    i t[i] k antes k depois
//    0   a       0        1
//    1   b       1        2
//    2   a       2        3
//    3   a       3        1  recuou para 1 0
//    4   b       1        2
//    5   a       2        3
//    6   b       3        4  <- achou em 3
//    7   c       2        0  recuou para 0
//    8   a       0        1
//    9   b       1        2
//   10   a       2        3
//   11   b       3        4  <- achou em 8
//
// Dicas:
// 1. Guarde os recuos num vetor durante o while e mostre depois do printf
//    principal, com printf("%2d   %c %7d %8d", i, t[i], antes, k).
// 2. Na letra 3 ('a'), k estava em 3 (lido "aba") e esperava 'b': recua
//    para pi[2] = 1, ainda não bate, recua para 0, e aí 'a' bate: k = 1.
// 3. Resposta esperada: ocorrências em 3 e 8; a única outra linha com
//    recuo é a do 'c', de 2 para 0.
//
// Escreva sua resposta abaixo:

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

int main(void) {
    const char *t = "abaababcabab", *p = "abab";
    int n = (int)strlen(t), m = (int)strlen(p), pi[16], k = 0;
    calcula_pi(p, m, pi);
    for (int i = 0; i < n; i++) {
        while (k > 0 && t[i] != p[k]) k = pi[k - 1];
        if (t[i] == p[k]) k++;
        if (k == m) k = pi[k - 1];
    }
    return 0;
}
