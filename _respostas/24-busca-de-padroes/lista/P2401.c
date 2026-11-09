// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2401 · ★☆☆ · O último Pix do extrato

#include <stdio.h>
#include <string.h>

// força bruta de trás para a frente: o primeiro achado é o último do texto
int ultima(const char *texto, const char *padrao, int *alinhamentos) {
    int n = (int)strlen(texto), m = (int)strlen(padrao);
    *alinhamentos = 0;
    for (int i = n - m; i >= 0; i--) {
        (*alinhamentos)++;
        int j = 0;
        while (j < m && texto[i + j] == padrao[j]) j++;
        if (j == m) return i;
    }
    return -1;
}

int main(void) {
    const char *extrato = "pix 50; boleto 120; pix 35; ted 900; pix 18; tarifa 12";
    const char *busca[] = {"pix", "ted", "doc"};
    for (int k = 0; k < 3; k++) {
        int al;
        int pos = ultima(extrato, busca[k], &al);
        if (pos < 0) printf("%s: não aparece (%d alinhamentos)\n", busca[k], al);
        else printf("%s: última em %d -> \"%.10s\" (%d alinhamentos)\n", busca[k], pos, extrato + pos, al);
    }
    return 0;
}
