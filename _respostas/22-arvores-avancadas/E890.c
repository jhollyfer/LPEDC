// 0149 · Juntando tudo
// Exercício E890 · ★☆☆

#include <ctype.h>
#include <stdio.h>
#include "corretor.h"

// passa as maiúsculas para minúsculas, no próprio vetor
void normaliza(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = (char)tolower((unsigned char)s[i]);
    }
}

void confere(const NoC *dic, const char *texto) {
    char palavra[COR_MAX];
    int total = 0, fora = 0;
    printf("palavras:");
    while (cor_proxima(&texto, palavra)) {
        printf(" %s", palavra);
        total++;
        fora += !cor_contem(dic, palavra);
    }
    printf("\n  %d palavras, %d fora do dicionário\n", total, fora);
}

int main(void) {
    NoC *dic = cor_cria();
    cor_carrega_basico(dic);
    char recado[] = "Hoje, a FEIRA da Rua tem Pao e Cafe!";
    confere(dic, recado);
    normaliza(recado);
    confere(dic, recado);
    cor_libera(dic);
    return 0;
}
