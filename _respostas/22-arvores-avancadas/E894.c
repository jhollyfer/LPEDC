// 0149 · Juntando tudo
// Exercício E894 · ★★★

#include <stdio.h>
#include <string.h>
#include "corretor.h"

#define LIMITE 2

// Desce na trie carregando a última linha da tabela de Levenshtein entre a
// palavra procurada e o prefixo do caminho. ant[j] = distância entre o
// prefixo do pai e as j primeiras letras da palavra.
void procura(const NoC *n, char letra, const char *alvo, int m, const int ant[],
             char buf[], int nivel, int *achadas) {
    int lin[COR_MAX + 1];
    lin[0] = ant[0] + 1; // apagar todas as letras do prefixo
    int menor = lin[0];
    for (int j = 1; j <= m; j++) {
        int troca = ant[j - 1] + (alvo[j - 1] == letra ? 0 : 1);
        int apaga = ant[j] + 1;
        int poe = lin[j - 1] + 1;
        int d = troca < apaga ? troca : apaga;
        lin[j] = d < poe ? d : poe;
        if (lin[j] < menor) {
            menor = lin[j];
        }
    }
    buf[nivel] = letra;
    if (n->fim && lin[m] <= LIMITE) {
        buf[nivel + 1] = '\0';
        printf(" %s(%d)", buf, lin[m]);
        (*achadas)++;
    }
    if (menor > LIMITE || nivel + 2 >= COR_MAX) {
        return; // poda: nada embaixo daqui chega a LIMITE
    }
    for (int i = 0; i < COR_LETRAS; i++) {
        if (n->filho[i] != NULL) {
            procura(n->filho[i], (char)('a' + i), alvo, m, lin, buf, nivel + 1, achadas);
        }
    }
}

void parecidas(const NoC *d, const char *alvo) {
    int m = (int)strlen(alvo);
    int lin[COR_MAX + 1];
    for (int j = 0; j <= m; j++) {
        lin[j] = j; // prefixo vazio: j inserções
    }
    char buf[COR_MAX];
    int achadas = 0;
    printf("%s:", alvo);
    for (int i = 0; i < COR_LETRAS; i++) {
        if (d->filho[i] != NULL) {
            procura(d->filho[i], (char)('a' + i), alvo, m, lin, buf, 0, &achadas);
        }
    }
    printf(achadas == 0 ? " nenhuma\n" : "\n");
}

int main(void) {
    NoC *dic = cor_cria();
    cor_carrega_basico(dic);
    const char *testes[] = {"carrro", "jnaela", "bolsa", "mercadorias"};
    for (int i = 0; i < 4; i++) {
        parecidas(dic, testes[i]);
    }
    cor_libera(dic);
    return 0;
}
