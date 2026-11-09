// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2419 · ★★☆ · Anagramas escondidos

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    const char *texto = "a roma de amor e o ramo de mora";
    const char *p = "amor";
    int n = (int)strlen(texto), m = (int)strlen(p);
    int quer[256] = {0}, janela[256] = {0};
    for (int k = 0; k < m; k++) {
        quer[(unsigned char)p[k]]++;
        janela[(unsigned char)texto[k]]++;
    }
    int achou = 0;
    for (int i = 0; i + m <= n; i++) {
        bool igual = true;
        for (int c = 0; c < 256 && igual; c++) igual = quer[c] == janela[c];
        if (igual) {
            printf("%2d: %.*s\n", i, m, texto + i);
            achou++;
        }
        if (i + m < n) { // a janela rola: sai uma letra, entra outra
            janela[(unsigned char)texto[i]]--;
            janela[(unsigned char)texto[i + m]]++;
        }
    }
    printf("Anagramas de \"%s\": %d\n", p, achou);
    return 0;
}
