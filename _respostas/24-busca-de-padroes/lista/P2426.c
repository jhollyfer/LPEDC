// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2426 · ★★★ · A cifra de César do bilhete

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

int kmp_tem(const char *t, const char *p) {
    int n = (int)strlen(t), m = (int)strlen(p), pi[64], k = 0;
    calcula_pi(p, m, pi);
    for (int i = 0; i < n; i++) {
        while (k > 0 && t[i] != p[k]) k = pi[k - 1];
        if (t[i] == p[k]) k++;
        if (k == m) return 1;
    }
    return 0;
}

// desloca cada letra minúscula s casas para trás; o resto fica igual
void decifra(const char *c, int s, char saida[]) {
    int i = 0;
    for (; c[i]; i++) saida[i] = c[i] >= 'a' && c[i] <= 'z' ? (char)('a' + (c[i] - 'a' - s + 26) % 26) : c[i];
    saida[i] = '\0';
}

int main(void) {
    const char *bilhete = "alrfp z ati op ntynz cpltd lep dpiel, glwpf";
    const char *sabida = "pix";
    char tentativa[128];
    int candidatos = 0;
    for (int s = 0; s < 26; s++) {
        decifra(bilhete, s, tentativa);
        if (kmp_tem(tentativa, sabida)) {
            candidatos++;
            printf("deslocamento %2d: %s\n", s, tentativa);
        }
    }
    printf("Deslocamentos com \"%s\": %d de 26\n", sabida, candidatos);
    return 0;
}
