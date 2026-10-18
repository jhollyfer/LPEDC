// 0161 · Juntando tudo
// Exercício E964 · ★★☆

#include <stdio.h>
#include <string.h>
#include "padroes.h"

#define MAXPOS 16

// mostra a linha com cada ocorrência entre colchetes
void destaca(const char *linha, const char *padrao) {
    int n = (int) strlen(linha);
    int m = (int) strlen(padrao);
    int pos[MAXPOS];
    long comp = 0;
    int k = pb_horspool(linha, n, padrao, m, pos, MAXPOS, &comp);
    if (k == 0) {
        return;                          // como o grep: linha sem padrão não sai
    }
    if (k > MAXPOS) {
        k = MAXPOS;
    }
    int prox = 0;                        // próxima ocorrência a abrir
    int fecha = -1;                      // onde fechar o colchete aberto
    for (int i = 0; i <= n; i++) {
        if (i == fecha) {
            putchar(']');
            fecha = -1;
        }
        if (i == n) {
            break;
        }
        if (prox < k && pos[prox] == i && fecha < 0) {
            putchar('[');
            fecha = i + m;
            prox++;
        }
        putchar(linha[i]);
    }
    printf("   (%d)\n", k);
}

int main(void) {
    const char *previsao[] = {
        "segunda: sol, sem chuva",
        "terça: chuva forte à tarde; depois da chuva, frio",
        "quarta: nublado",
        "quinta: chuvarada de manhã",
    };
    for (int l = 0; l < 4; l++) {
        destaca(previsao[l], "chuva");
    }
    return 0;
}
