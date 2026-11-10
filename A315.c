// A315 · Todas as bordas de uma palavra

#include <stdio.h>
#include <string.h>

#define MAX 32

void calcula_pi(const char *p, int m, int pi[]) {
    int k = 0;
    pi[0] = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) {
            k = pi[k - 1];
        }
        if (p[j] == p[k]) {
            k++;
        }
        pi[j] = k;
    }
}

// a maior borda de p tem pi[m-1] letras; a borda da borda tem pi[b-1], e assim
// por diante: seguir a corrente de pi dá TODAS as bordas, da maior à menor
void mostra_bordas(const char *p) {
    int m = (int) strlen(p);
    int pi[MAX];
    calcula_pi(p, m, pi);

    printf("%-9s pi =", p);
    for (int j = 0; j < m; j++) {
        printf(" %d", pi[j]);
    }
    printf("   bordas:");
    int b = pi[m - 1];
    if (b == 0) {
        printf(" nenhuma");
    }
    while (b > 0) {
        printf(" \"%.*s\"", b, p);   // as b primeiras letras
        b = pi[b - 1];
    }
    printf("\n");
}

int main(void) {
    mostra_bordas("arara");
    mostra_bordas("ananas");
    mostra_bordas("aaaa");
    mostra_bordas("cacaraca");
    mostra_bordas("brasil");
    return 0;
}
// Saída:
// arara     pi = 0 0 1 2 3   bordas: "ara" "a"
// ananas    pi = 0 0 1 2 3 0   bordas: nenhuma
// aaaa      pi = 0 1 2 3   bordas: "aaa" "aa" "a"
// cacaraca  pi = 0 0 1 2 0 0 1 2   bordas: "ca"
// brasil    pi = 0 0 0 0 0 0   bordas: nenhuma
