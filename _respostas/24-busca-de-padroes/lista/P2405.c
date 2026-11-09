// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2405 · ★☆☆ · Quanto o Horspool pula

#include <stdio.h>
#include <string.h>

void monta_saltos(const char *p, int m, int salto[256]) {
    for (int c = 0; c < 256; c++) salto[c] = m;
    for (int j = 0; j < m - 1; j++) salto[(unsigned char)p[j]] = m - 1 - j;
}

// conta as ocorrências e os alinhamentos testados
int horspool(const char *t, const char *p, int *alinhamentos) {
    int n = (int)strlen(t), m = (int)strlen(p), salto[256], achou = 0;
    monta_saltos(p, m, salto);
    *alinhamentos = 0;
    int i = 0;
    while (i <= n - m) {
        (*alinhamentos)++;
        int j = m - 1;
        while (j >= 0 && t[i + j] == p[j]) j--;
        if (j < 0) achou++;
        i += salto[(unsigned char)t[i + m - 1]];
    }
    return achou;
}

int main(void) {
    const char *cardapio = "tapioca de queijo coalho, tacaca quente, pato no tucupi e tapioca de coco";
    const char *pratos[] = {"pa", "pato", "tapioca de coco"};
    printf("texto com %d letras\n", (int)strlen(cardapio));
    for (int k = 0; k < 3; k++) {
        int al;
        int achou = horspool(cardapio, pratos[k], &al);
        printf("%-16s m = %2d: %d ocorrência(s), %2d alinhamentos\n", pratos[k], (int)strlen(pratos[k]), achou, al);
    }
    return 0;
}
