// 0149 · Juntando tudo
// Exercício E893 · ★★★
//
// Ache o bug. Esta versão enxuta do sugeridor testa só duas edições: tirar
// uma letra e pôr uma letra. Ela acerta "pasou" e "baratoo", mas não sugere
// nada para "barat" e "cas", que estão a uma letra de distância de palavras do
// dicionário:
//
//   Saída que aparece:
//   pasou: passou
//   baratoo: barato
//   barat: nenhuma
//   cas: nenhuma
//
//   Saída esperada:
//   pasou: passou
//   baratoo: barato
//   barat: barato
//   cas: casa caso
//
// Ache a linha errada, conserte e rode de novo.
//
// Dicas:
// 1. "barat" vira "barato" pondo uma letra em qual posição? Quais posições o
//    laço da inserção experimenta numa palavra de 5 letras?
// 2. Numa palavra de n letras existem n + 1 lugares para pôr uma letra nova:
//    antes da primeira, entre cada par e DEPOIS da última.
// 3. Resposta esperada: no laço "pôr uma letra", a condição é i <= n, e não
//    i < n. Com i < n, a posição depois da última letra nunca é testada.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>
#include "corretor.h"

// mostra c se estiver no dicionário e ainda não tiver sido mostrada
void mostra(const NoC *d, const char *c, char vistas[][COR_MAX], int *qtd) {
    if (!cor_contem(d, c)) {
        return;
    }
    for (int i = 0; i < *qtd; i++) {
        if (strcmp(vistas[i], c) == 0) {
            return;
        }
    }
    if (*qtd < 10) {
        strcpy(vistas[(*qtd)++], c);
        printf(" %s", c);
    }
}

void sugere(const NoC *d, const char *palavra) {
    char c[COR_MAX + 1], vistas[10][COR_MAX];
    int n = (int)strlen(palavra), qtd = 0;
    printf("%s:", palavra);
    for (int i = 0; i < n; i++) { // tirar a letra i
        memcpy(c, palavra, i);
        strcpy(c + i, palavra + i + 1);
        mostra(d, c, vistas, &qtd);
    }
    for (int i = 0; i < n; i++) { // pôr uma letra na posição i
        for (char l = 'a'; l <= 'z'; l++) {
            memcpy(c, palavra, i);
            c[i] = l;
            strcpy(c + i + 1, palavra + i);
            mostra(d, c, vistas, &qtd);
        }
    }
    printf(qtd == 0 ? " nenhuma\n" : "\n");
}

int main(void) {
    NoC *dic = cor_cria();
    cor_carrega_basico(dic);
    const char *testes[] = {"pasou", "baratoo", "barat", "cas"};
    for (int i = 0; i < 4; i++) {
        sugere(dic, testes[i]);
    }
    cor_libera(dic);
    return 0;
}
