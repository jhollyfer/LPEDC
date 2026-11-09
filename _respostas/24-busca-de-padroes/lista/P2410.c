// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2410 · ★☆☆ · O letreiro que gira

#include <stdio.h>
#include <string.h>

void inverte(char *s, int i, int j) {
    while (i < j) {
        char t = s[i];
        s[i++] = s[j];
        s[j--] = t;
    }
}

// gira k casas para a esquerda com três inversões, sem vetor extra
void gira(char *s, int k) {
    int n = (int)strlen(s);
    k %= n;
    if (k == 0) return;
    inverte(s, 0, k - 1);
    inverte(s, k, n - 1);
    inverte(s, 0, n - 1);
}

int main(void) {
    char letreiro[] = "030 CENTRO ";
    printf("[%s]\n", letreiro);
    for (int passo = 1; passo <= 4; passo++) {
        gira(letreiro, 3);
        printf("[%s]\n", letreiro);
    }
    char outro[] = "ABCDE";
    gira(outro, 12);
    printf("ABCDE girado 12: %s\n", outro);
    return 0;
}
