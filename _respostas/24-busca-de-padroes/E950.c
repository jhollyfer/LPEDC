// 0159 · Horspool
// Exercício E950 · ★☆☆

#include <stdio.h>
#include <string.h>

#define ALFABETO 256

int horspool(const char *texto, const char *padrao) {
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);
    int salto[ALFABETO];
    for (int c = 0; c < ALFABETO; c++) {
        salto[c] = m;
    }
    for (int j = 0; j < m - 1; j++) {
        salto[(unsigned char) padrao[j]] = m - 1 - j;
    }
    int i = 0, alinhamentos = 0;
    while (i <= n - m) {
        alinhamentos++;
        int j = m - 1;
        while (j >= 0 && texto[i + j] == padrao[j]) {
            j--;
        }
        unsigned char ultima = (unsigned char) texto[i + m - 1];
        if (j < 0) {
            printf("i = %2d: achou\n", i);
            return alinhamentos;
        }
        printf("i = %2d: '%c' sob a última casa, salta %d\n", i, ultima, salto[ultima]);
        i += salto[ultima];
    }
    printf("não achou\n");
    return alinhamentos;
}

int main(void) {
    int a = horspool("COMPRE PIPOCA DOCE", "PIPOCA");
    printf("%d alinhamentos\n", a);
    return 0;
}
