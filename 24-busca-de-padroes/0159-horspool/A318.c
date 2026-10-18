// A318 · Acentos são bytes: por que unsigned char

#include <stdio.h>
#include <string.h>

#define ALFABETO 256

int main(void) {
    const char *texto = "informação e ação";
    const char *padrao = "ação";
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);

    // em UTF-8, 'ç' e 'ã' ocupam 2 bytes cada: "ação" tem 4 letras e 6 bytes
    printf("strlen(\"ação\") = %d bytes:", m);
    for (int j = 0; j < m; j++) {
        printf(" %d", padrao[j]);                  // char com sinal: negativo
    }
    printf("\ncomo unsigned char:      ");
    for (int j = 0; j < m; j++) {
        printf(" %d", (unsigned char) padrao[j]);  // de 0 a 255: índice válido
    }
    printf("\n");

    int salto[ALFABETO];
    for (int c = 0; c < ALFABETO; c++) {
        salto[c] = m;
    }
    for (int j = 0; j < m - 1; j++) {
        salto[(unsigned char) padrao[j]] = m - 1 - j;
    }
    printf("saltos: 'a'=%d 0xC3=%d 0xA7=%d 0xA3=%d outras=%d\n",
           salto['a'], salto[0xC3], salto[0xA7], salto[0xA3], salto['z']);

    int i = 0;
    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0 && texto[i + j] == padrao[j]) {
            j--;
        }
        if (j < 0) {
            printf("achou no byte %d\n", i);
        }
        i += salto[(unsigned char) texto[i + m - 1]];
    }
    return 0;
}
// Saída:
// strlen("ação") = 6 bytes: 97 -61 -89 -61 -93 111
// como unsigned char:       97 195 167 195 163 111
// saltos: 'a'=5 0xC3=2 0xA7=3 0xA3=1 outras=6
// achou no byte 6
// achou no byte 15
