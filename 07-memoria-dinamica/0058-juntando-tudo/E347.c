// 0058 · Juntando tudo
// Exercício E347 · ★★★
//
// Uma versão apressada do caderninho de fiado. Ela tem TRÊS problemas de
// memória, de propósito. O AddressSanitizer acha dois (um durante a
// execução, outro no fim); o terceiro só aparece quando falta memória, e
// você tem que achar lendo. Conserte os três.
//
//   Saída esperada depois do conserto:
//   Cida: R$ 12
//   Jorge: R$ 8
//   Bia: R$ 20
//
// Dicas:
// 1. Comece pelo heap-buffer-overflow: quantos bytes copiar precisa?
// 2. Depois o vazamento: quantos malloc existem? Quantos free?
// 3. O terceiro está na linha do realloc.
// 4. Resposta esperada: (a) copiar faz malloc(strlen(s)) sem o + 1 do
//    '\0'; (b) o fim libera só nomes, e cada nomes[i] vaza: faça um free
//    por nome antes; (c) nomes = realloc(nomes, ...) perde o bloco se
//    falhar: use um ponteiro temporário.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copiar(const char *s) {
    char *c = malloc(strlen(s));
    if (c != NULL) {
        strcpy(c, s);
    }
    return c;
}

int main(void) {
    const char *quem[] = {"Cida", "Jorge", "Bia"};
    int deve[] = {12, 8, 20};
    int cap = 1;
    int qtd = 0;
    char **nomes = malloc(cap * sizeof *nomes);
    if (nomes == NULL) {
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        if (qtd == cap) {
            cap *= 2;
            nomes = realloc(nomes, cap * sizeof *nomes);
            if (nomes == NULL) {
                return 1;
            }
        }
        nomes[qtd] = copiar(quem[i]);
        if (nomes[qtd] == NULL) {
            return 1;
        }
        qtd++;
    }
    for (int i = 0; i < qtd; i++) {
        printf("%s: R$ %d\n", nomes[i], deve[i]);
    }
    free(nomes);
    return 0;
}
