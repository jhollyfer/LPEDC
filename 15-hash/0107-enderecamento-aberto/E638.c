// 0107 · Endereçamento aberto
// Exercício E638 · ★☆☆
//
// O programa abaixo insere 16, 8, 3, 24 e 11 numa tabela de 8 posições com
// sondagem linear e mostra a vaga e as sondagens de cada inserção. Estenda o
// programa: depois das inserções, busque as chaves 24 e 19 com a mesma
// sondagem (começa em k % 8, anda uma casa por vez, para ao achar a chave
// ou uma vaga livre) e mostre o resultado de cada busca.
//
//   Saída esperada (as 5 primeiras linhas já saem hoje):
//   16: vaga 0 (1)
//   8: vaga 1 (2)
//   3: vaga 3 (1)
//   24: vaga 2 (3)
//   11: vaga 4 (2)
//   busca 24: vaga 2 (3 sondagens)
//   busca 19: não está (3 sondagens)
//
// Dicas:
// 1. A busca é o mesmo while da inserção, com uma condição a mais: pare
//    quando tab[i] == 0 (livre) ou tab[i] == chave.
// 2. Conte as sondagens do mesmo jeito: s começa em 1 e soma a cada passo.
// 3. Resposta esperada: a saída acima. O 19 tem hash 3: olha a 3 (o 3), a
//    4 (o 11) e para na 5, livre.
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdio.h>

#define M 8

int main(void) {
    int tab[M] = {0}; // 0 = livre (nenhuma chave é 0)
    int chaves[] = {16, 8, 3, 24, 11};
    for (int k = 0; k < 5; k++) {
        int i = chaves[k] % M;
        int s = 1;
        while (tab[i] != 0) {
            i = (i + 1) % M;
            s++;
        }
        tab[i] = chaves[k];
        printf("%d: vaga %d (%d)\n", chaves[k], i, s);
    }

    // busque 24 e 19 aqui

    return 0;
}
