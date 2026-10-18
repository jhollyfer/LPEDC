// 0161 · Juntando tudo
// Exercício E961 · ★☆☆

#include <stdio.h>
#include <string.h>
#include "padroes.h"

int main(void) {
    const char *extrato = "pix recebido; pix enviado; boleto pago; pix agendado; tarifa pix";
    const char *padrao = "pix";
    int n = (int) strlen(extrato);
    int m = (int) strlen(padrao);
    const char *nomes[] = {"força bruta", "KMP", "Horspool", "Rabin-Karp"};
    Busca buscas[] = {pb_forca_bruta, pb_kmp, pb_horspool, pb_rabin_karp};
    int primeiro = -1, concordam = 1;

    for (int a = 0; a < 4; a++) {
        long comp = 0;
        int k = buscas[a](extrato, n, padrao, m, NULL, 0, &comp);
        printf("%d ocorrências, %3ld comparações: %s\n", k, comp, nomes[a]);
        if (primeiro < 0) {
            primeiro = k;
        } else if (k != primeiro) {
            concordam = 0;
        }
    }
    printf("%s\n", concordam ? "os quatro concordam" : "DISCORDAM!");
    return 0;
}
