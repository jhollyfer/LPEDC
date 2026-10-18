// 0159 · Horspool
// Exercício E953 · ★★★

#include <stdio.h>
#include <string.h>

int horspool(const char *texto, const char *padrao) {
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);
    int salto[256];
    int total = 0;
    for (int c = 0; c < 256; c++) {
        salto[c] = m;
    }
    for (int j = 0; j < m - 1; j++) {
        int c = (unsigned char) padrao[j];      // de 0 a 255, nunca negativo
        salto[c] = m - 1 - j;
    }
    int i = 0;
    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0 && texto[i + j] == padrao[j]) {
            j--;
        }
        if (j < 0) {
            total++;
        }
        int ultima = (unsigned char) texto[i + m - 1];
        i += salto[ultima];
    }
    return total;
}

int main(void) {
    printf("pao: %d\n", horspool("o pao de queijo e o pao doce", "pao"));
    printf("feijão: %d\n", horspool("feijão, arroz e mais feijão", "feijão"));
    printf("açaí: %d\n", horspool("açaí com granola ou açaí puro?", "açaí"));
    return 0;
}
