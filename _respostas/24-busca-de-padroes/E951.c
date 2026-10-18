// 0159 · Horspool
// Exercício E951 · ★★☆

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALFABETO 256

// minúscula de um char, sem cair no índice negativo
int baixa(char c) {
    return tolower((unsigned char) c);
}

// Horspool que ignora maiúsculas/minúsculas e acha todas as ocorrências
int horspool_todas(const char *texto, const char *padrao) {
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);
    int salto[ALFABETO];
    int total = 0;
    for (int c = 0; c < ALFABETO; c++) {
        salto[c] = m;
    }
    for (int j = 0; j < m - 1; j++) {
        salto[baixa(padrao[j])] = m - 1 - j;   // a tabela só usa minúsculas
    }
    int i = 0;
    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0 && baixa(texto[i + j]) == baixa(padrao[j])) {
            j--;
        }
        if (j < 0) {
            printf("posição %2d: %.*s\n", i, m, texto + i);
            total++;
        }
        i += salto[baixa(texto[i + m - 1])];   // achando ou não, salta
    }
    return total;
}

int main(void) {
    const char *frase = "Banana na BANANEIRA, banana no prato, BANANA no bolo";
    int t = horspool_todas(frase, "banana");
    printf("%d ocorrências\n", t);
    return 0;
}
