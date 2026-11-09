// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1830 · ★★★ · O log do servidor: IPs ordenados por radix base 256

#include <stdio.h>
#include <string.h>

#define N 16

unsigned ip_de(const char *s) {
    unsigned a, b, c, d;
    if (sscanf(s, "%u.%u.%u.%u", &a, &b, &c, &d) != 4 || a > 255 || b > 255 || c > 255 || d > 255) {
        printf("IP inválido: %s\n", s);
        return 0;
    }
    return (a << 24) | (b << 16) | (c << 8) | d;
}

void ip_para(unsigned ip, char s[16]) {
    snprintf(s, 16, "%u.%u.%u.%u", ip >> 24, (ip >> 16) & 255, (ip >> 8) & 255, ip & 255);
}

void radix256(unsigned v[], int n) {
    unsigned saida[N];
    for (int p = 0; p < 4; p++) { // do byte menos significativo para o mais
        int c[256] = {0}, s = 8 * p;
        for (int i = 0; i < n; i++) c[(v[i] >> s) & 255]++;
        for (int x = 1; x < 256; x++) c[x] += c[x - 1];
        for (int i = n - 1; i >= 0; i--) saida[--c[(v[i] >> s) & 255]] = v[i];
        memcpy(v, saida, n * sizeof *v);
    }
}

int main(void) {
    const char *registro[N] = {"192.168.1.20", "10.0.0.10", "200.17.5.3", "10.0.0.9",
                               "192.168.1.20", "172.16.0.1", "10.0.0.10", "192.168.1.3",
                               "200.17.5.3", "192.168.1.20", "8.8.8.8", "10.0.0.9",
                               "192.168.1.20", "172.16.0.1", "10.0.0.10", "200.17.5.30"};
    unsigned v[N];
    for (int i = 0; i < N; i++) v[i] = ip_de(registro[i]);

    radix256(v, N);
    char s[16], top[16] = "";
    int distintos = 0, mais = 0;
    for (int i = 0; i < N;) {
        int j = i;
        while (j < N && v[j] == v[i]) j++; // as repetições ficam juntas
        ip_para(v[i], s);
        printf("%-15s %d acesso%s\n", s, j - i, j - i > 1 ? "s" : "");
        if (j - i > mais) {
            mais = j - i;
            strcpy(top, s);
        }
        distintos++;
        i = j;
    }
    printf("Distintos: %d | quem mais acessou: %s (%d)\n", distintos, top, mais);
    printf("strcmp(\"10.0.0.9\", \"10.0.0.10\") > 0: %s\n", strcmp("10.0.0.9", "10.0.0.10") > 0 ? "sim" : "não");
    return 0;
}
