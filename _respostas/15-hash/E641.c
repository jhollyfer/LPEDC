// 0107 · Endereçamento aberto
// Exercício E641 · ★★★
//
// Resposta: a) no "tab[i] != 0" (e no "tab[i] = chave") quando i chega a 7,
// ao inserir o 20; b) 20 % 7 = 6, a vaga 6 já tem o 13, e "i = i + 1" leva
// i para 7, uma posição depois do fim do vetor. A sondagem precisa dar a
// volta: "i = (i + 1) % M". Consertado, o 20 vai para a vaga 0.

#include <stdio.h>

#define M 7

void insere(int tab[], int chave) {
    int i = chave % M;
    while (tab[i] != 0) {
        i = (i + 1) % M; // depois da última vaga, volta para a 0
    }
    tab[i] = chave;
}

int main(void) {
    int tab[M] = {0}; // 0 = livre
    int chaves[] = {9, 13, 20, 4};
    for (int k = 0; k < 4; k++) {
        insere(tab, chaves[k]);
    }
    for (int i = 0; i < M; i++) {
        printf("[%d] %d\n", i, tab[i]);
    }
    return 0;
}
