// 0149 · Juntando tudo
// Exercício E889 · ★☆☆

#include <stdio.h>
#include "corretor.h"

int main(void) {
    NoC *dic = cor_cria();
    cor_carrega_basico(dic);
    const char *texto = "a escola da cidade tem muitos alunos e um onibus amarelo na porta";
    char palavra[COR_MAX];
    int total = 0, fora = 0;
    printf("desconhecidas:");
    while (cor_proxima(&texto, palavra)) {
        total++;
        if (!cor_contem(dic, palavra)) {
            printf(" %s", palavra);
            fora++;
        }
    }
    printf("\n%d de %d palavras fora do dicionário\n", fora, total);
    cor_libera(dic);
    return 0;
}
