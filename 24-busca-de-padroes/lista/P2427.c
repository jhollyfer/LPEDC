// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2427 · ★★★ · Os prefixos que são refrão
//
// Um prefixo de tamanho i é um REFRÃO quando é um pedaço repetido um
// número inteiro de vezes, duas ou mais ("tumtum" = "tum" × 2). Com a
// tabela π, o período do prefixo de tamanho i é i - pi[i - 1]; ele é
// refrão quando o período é menor que i e divide i. Escreva refraos(s),
// que mostra todos os prefixos refrão de s, em O(m), com o tamanho, o
// pedaço e quantas vezes ele se repete.
//
//   Saída esperada:
//   tumtumtumpatumtumtumpa
//      6 letras = "tum" x 2
//      9 letras = "tum" x 3
//     22 letras = "tumtumtumpa" x 2
//   aabaabaabaab
//      2 letras = "a" x 2
//      6 letras = "aab" x 2
//      9 letras = "aab" x 3
//     12 letras = "aab" x 4
//
// Dicas:
// 1. Calcule pi uma vez só e percorra i de 2 até m.
// 2. Mostre com printf("  %2d letras = \"%.*s\" x %d\n", i, periodo, s,
//    i / periodo).
// 3. Resposta esperada: a batucada inteira (22 letras) é "tumtumtumpa" × 2;
//    aabaabaabaab tem 4 prefixos refrão.
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
    printf("%s\n", "tumtumtumpatumtumtumpa");
    printf("%s\n", "aabaabaabaab");
    return 0;
}
