// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2423 · ★★★ · A mensagem em pedaços

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

// maior sufixo de a que também é prefixo de b: a borda de b + '#' + a
int sobreposicao(const char *a, const char *b) {
    char junto[256];
    snprintf(junto, sizeof junto, "%s#%s", b, a);
    int m = (int)strlen(junto), pi[256];
    calcula_pi(junto, m, pi);
    return pi[m - 1];
}

int main(void) {
    const char *pedacos[] = {"o rato roe", "roeu a rou", "a roupa do rei", "rei de roma", "roma inteira"};
    char msg[256];
    strcpy(msg, pedacos[0]);
    for (int k = 1; k < 5; k++) {
        int s = sobreposicao(msg, pedacos[k]);
        printf("\"%s\" sobrepõe %d: \"%.*s\"\n", pedacos[k], s, s, pedacos[k]);
        strcat(msg, pedacos[k] + s);
    }
    printf("Mensagem: %s\n", msg);
    return 0;
}
