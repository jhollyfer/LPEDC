// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0520 · ★★☆ · O meu atoi

#include <stdio.h>
#include <ctype.h>

int texto_para_int(const char s[]) {
    int i = 0;
    int sinal = 1;
    if (s[i] == '-' || s[i] == '+') {
        if (s[i] == '-') {
            sinal = -1;
        }
        i++;
    }
    int valor = 0;
    while (isdigit((unsigned char) s[i])) {
        valor = valor * 10 + (s[i] - '0'); // empurra uma casa e soma o dígito
        i++;
    }
    return sinal * valor;
}

int main(void) {
    char lanc[5][8] = {"1200", "-350", "+80", "-1045", "75"};
    int saldo = 0;

    for (int i = 0; i < 5; i++) {
        int v = texto_para_int(lanc[i]);
        printf("\"%s\" -> %d\n", lanc[i], v);
        saldo += v;
    }
    printf("Saldo: %d\n", saldo);
    return 0;
}
