// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2403 · ★☆☆ · A borda de cada prefixo
//
// A tabela π é difícil de ler só com números. O programa abaixo já
// calcula pi[] de uma palavra. Estenda a função mostra: para cada j,
// mostre o índice (%2d), o prefixo p[0..j] alinhado à esquerda numa
// coluna da largura da palavra, o valor de pi[j] e, quando ele não é zero,
// a borda: o prefixo de tamanho pi[j], que também é o fim de p[0..j].
// Teste com "tatuta" e "aabaaab".
//
//   Saída esperada:
//   tatuta
//      0 t      pi = 0
//      1 ta     pi = 0
//      2 tat    pi = 1  borda "t"
//      3 tatu   pi = 0
//      4 tatut  pi = 1  borda "t"
//      5 tatuta pi = 2  borda "ta"
//   aabaaab
//      0 a       pi = 0
//      1 aa      pi = 1  borda "a"
//      2 aab     pi = 0
//      3 aaba    pi = 1  borda "a"
//      4 aabaa   pi = 2  borda "aa"
//      5 aabaaa  pi = 2  borda "aa"
//      6 aabaaab pi = 3  borda "aab"
//
// Dicas:
// 1. "%.*s" mostra só as primeiras letras: printf("%.*s", j + 1, p). Com
//    "%-*.*s" você ainda escolhe a largura: printf("%-*.*s", m, j + 1, p).
// 2. Em "aabaaa" a borda é "aa", e não "aaa": a borda é um prefixo
//    PRÓPRIO que termina no fim, e "aaa" não é prefixo de "aabaaa".
// 3. Resposta esperada: a última linha de "aabaaab" tem pi = 3 e borda
//    "aab".
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

void mostra(const char *p) {
    int m = (int)strlen(p), pi[64];
    calcula_pi(p, m, pi);
    printf("%s\n", p);
}

int main(void) {
    mostra("tatuta");
    mostra("aabaaab");
    return 0;
}
