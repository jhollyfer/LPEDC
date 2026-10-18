// 0107 · Endereçamento aberto
// Exercício E641 · ★★★
//
// No clube, os armários usam sondagem linear com 7 posições. O programa
// abaixo guarda 9, 13, 20 e 4, mas o AddressSanitizer acusa
// "stack-buffer-overflow" ao guardar o 20. O erro está aí de propósito.
// Rode, leia o relatório e conserte a função insere. Depois faça insere
// devolver quantas sondagens usou ("int insere(...)") e mostre esse número
// para cada chave, antes da tabela.
//
//   Saída esperada depois do conserto:
//   9: 1 sondagem(ns)
//   13: 1 sondagem(ns)
//   20: 2 sondagem(ns)
//   4: 1 sondagem(ns)
//   [0] 20
//   [1] 0
//   [2] 9
//   [3] 0
//   [4] 4
//   [5] 0
//   [6] 13
//
// Dicas:
// 1. 20 % 7 = 6. Quem está na vaga 6? Qual é a "próxima" depois da 6?
// 2. Num vetor de 7 posições, o maior índice é 6: "i = i + 1" chega a 7.
// 3. Resposta esperada: a saída acima. O conserto é "i = (i + 1) % M", que
//    volta para a vaga 0; conte as sondagens com uma variável que começa
//    em 1 e soma a cada passo do while.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define M 7

void insere(int tab[], int chave) {
    int i = chave % M;
    while (tab[i] != 0) {
        i = i + 1;
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
