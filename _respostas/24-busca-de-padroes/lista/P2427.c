// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2427 · ★★★ · Os prefixos que são refrão

#include <stdio.h>
#include <string.h>

void calcula_pi(const char *p, int m, int pi[]) {
    pi[0] = 0;
    int k = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) k = pi[k - 1];
        if (p[j] == p[k]) k++;
        pi[j] = k;
    }
}

void refraos(const char *s) {
    int m = (int)strlen(s), pi[128];
    calcula_pi(s, m, pi);
    printf("%s\n", s);
    for (int i = 2; i <= m; i++) { // prefixo de tamanho i
        int periodo = i - pi[i - 1];
        if (periodo < i && i % periodo == 0)
            printf("  %2d letras = \"%.*s\" x %d\n", i, periodo, s, i / periodo);
    }
}

int main(void) {
    refraos("tumtumtumpatumtumtumpa");
    refraos("aabaabaabaab");
    return 0;
}
