// 0161 · Juntando tudo
// Exercício E962 · ★☆☆

#include <stdio.h>
#include <string.h>
#include "padroes.h"

int main(void) {
    const char *receitas[] = {
        "bolo de cenoura: 3 ovos, 2 xícaras de farinha",
        "pão de queijo: polvilho, queijo, ovo e leite",
        "brigadeiro: leite condensado e chocolate",
        "omelete: 2 ovos e queijo",
        "pudim: leite, ovos e açúcar; ovo extra se quiser",
        "farofa: farinha, manteiga e ovo cozido",
    };
    int linhas = sizeof receitas / sizeof receitas[0];
    const char *padrao = "ovo";
    int m = (int) strlen(padrao);
    int com = 0, ocorrencias = 0;
    long comp = 0;

    for (int l = 0; l < linhas; l++) {
        int k = pb_horspool(receitas[l], (int) strlen(receitas[l]), padrao, m,
                            NULL, 0, &comp);
        if (k > 0) {
            printf("%d: %s\n", l + 1, receitas[l]);
            com++;
            ocorrencias += k;
        }
    }
    printf("%d linhas, %d ocorrências\n", com, ocorrencias);
    return 0;
}
