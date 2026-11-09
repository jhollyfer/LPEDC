// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2416 · ★★☆ · O maior palíndromo escondido

#include <stdio.h>
#include <string.h>

// expande ao redor do centro (e, d) enquanto as pontas forem iguais
int expande(const char *s, int n, int e, int d) {
    while (e >= 0 && d < n && s[e] == s[d]) {
        e--;
        d++;
    }
    return d - e - 1; // tamanho do palíndromo achado
}

void maior(const char *s) {
    int n = (int)strlen(s), ini = 0, tam = n > 0 ? 1 : 0;
    for (int c = 0; c < n; c++) {
        int impar = expande(s, n, c, c);     // centro numa letra
        int par = expande(s, n, c, c + 1);   // centro entre duas letras
        if (impar > tam) {
            tam = impar;
            ini = c - impar / 2;
        }
        if (par > tam) {
            tam = par;
            ini = c - par / 2 + 1;
        }
    }
    printf("%-16s \"%.*s\" (posição %d, %d letra(s))\n", s, tam, s + ini, ini, tam);
}

int main(void) {
    const char *palavras[] = {"bananas", "paralelepipedo", "arrozzorra", "abcd", "osso", "sopapos"};
    for (int k = 0; k < 6; k++) maior(palavras[k]);
    return 0;
}
