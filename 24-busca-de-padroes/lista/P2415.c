// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2415 · ★★☆ · O Horspool que confunde bolo com rolo
//
// Ache o bug. A padaria procura "bolo" e "de" no quadro de avisos, mas o
// Horspool abaixo acha coisas demais:
//
//   Saída que aparece:
//     bolo em 0
//     bolo em 8
//     bolo em 14
//     bolo em 33
//     bolo em 46
//   bolo: 5
//     de em 5
//     de em 19
//     de em 27
//   de: 3
//
// Na posição 8 está "rolo" e na 33, "tolo". O erro está na comparação de
// cada alinhamento (duas linhas). Conserte.
//
//   Saída esperada:
//     bolo em 0
//     bolo em 14
//     bolo em 46
//   bolo: 3
//     de em 5
//     de em 19
//   de: 2
//
// Dicas:
// 1. Para qual j o laço de comparação para? A letra p[0] chega a ser
//    comparada alguma vez?
// 2. O Horspool compara da direita para a esquerda até j passar do começo:
//    j >= 0. Achou quando todas bateram, ou seja, j < 0.
// 3. Resposta esperada: bolo 3, de 2.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

int horspool(const char *t, const char *p) {
    int n = (int)strlen(t), m = (int)strlen(p), salto[256], achou = 0;
    for (int c = 0; c < 256; c++) salto[c] = m;
    for (int j = 0; j < m - 1; j++) salto[(unsigned char)p[j]] = m - 1 - j;
    int i = 0;
    while (i <= n - m) {
        int j = m - 1;
        while (j > 0 && t[i + j] == p[j]) j--;
        if (j == 0) {
            printf("  %s em %d\n", p, i);
            achou++;
        }
        i += salto[(unsigned char)t[i + m - 1]];
    }
    return achou;
}

int main(void) {
    const char *padaria = "bolo de rolo, bolo de milho e um tolo pedindo bolo";
    printf("bolo: %d\n", horspool(padaria, "bolo"));
    printf("de: %d\n", horspool(padaria, "de"));
    return 0;
}
