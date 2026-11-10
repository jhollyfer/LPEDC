// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2421 · ★★★ · A senha do cofre
//
// No jogo de enigmas, a senha do cofre está escondida na dica: é o MAIOR
// trecho que, ao mesmo tempo, começa a dica, termina a dica e aparece no
// meio dela (uma ocorrência que não é nem a do começo nem a do fim). Se
// não houver, não há senha. Escreva int senha(const char *s), em O(m),
// com a tabela π:
// - os candidatos são as bordas do texto inteiro: pi[m-1], depois
// pi[pi[m-1] - 1], e assim por diante;
// - um candidato de tamanho L aparece no meio se algum pi[j], com
// 1 <= j <= m - 2, é pelo menos L.
//
//   Saída esperada:
//   fixprefixsuffix  senha "fix"
//   abcdabc          sem senha
//   aaaa             senha "aa"
//   papapapa         senha "papa"
//   araraquara       senha "ara"
//
// Dicas:
// 1. Guarde meio = o maior pi[j] para j de 1 a m - 2. Desça pela cadeia de
//    bordas enquanto L > meio.
// 2. Se pi[j] >= L, o prefixo de tamanho L termina em j (é borda de uma
//    borda): logo ele aparece terminando antes do fim.
// 3. Resposta esperada: fixprefixsuffix dá "fix"; abcdabc não tem senha
//    ("abc" é prefixo e sufixo, mas não aparece no meio); papapapa dá
//    "papa".
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
    const char *dicas[] = {"fixprefixsuffix", "abcdabc", "aaaa", "papapapa", "araraquara"};
    printf("%s\n", dicas[0]);
    return 0;
}
