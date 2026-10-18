// A279 · O pen drive com uma linha só de tabela

#include <stdio.h>

#define N 4
#define CAP 16 // GB livres no pen drive

int tamanho[N] = {5, 4, 7, 3};     // GB de cada videoaula
int nota[N] = {30, 24, 40, 20};    // o quanto cada uma interessa
const char *nome[N] = {"A", "B", "C", "D"};

// mochila 0/1 com UM vetor: melhor[c] faz o papel da linha "de cima".
// O laço de c DESCE: assim melhor[c - tamanho] ainda é o valor da linha
// anterior, sem o item i.
int mochila_descendo(void) {
    int melhor[CAP + 1] = {0};
    for (int i = 0; i < N; i++) {
        for (int c = CAP; c >= tamanho[i]; c--) {
            int com_i = nota[i] + melhor[c - tamanho[i]];
            if (com_i > melhor[c]) {
                melhor[c] = com_i;
            }
        }
    }
    return melhor[CAP];
}

// O MESMO código com o laço subindo: melhor[c - tamanho] já pode ter usado
// o item i nesta mesma volta. O item vira infinito (mochila "ilimitada").
int mochila_subindo(int copias[]) {
    int melhor[CAP + 1] = {0};
    int ultimo[CAP + 1];
    for (int c = 0; c <= CAP; c++) {
        ultimo[c] = -1;
    }
    for (int i = 0; i < N; i++) {
        for (int c = tamanho[i]; c <= CAP; c++) {
            int com_i = nota[i] + melhor[c - tamanho[i]];
            if (com_i > melhor[c]) {
                melhor[c] = com_i;
                ultimo[c] = i;
            }
        }
    }
    // conta quantas vezes cada item entrou (anda pelo último item escolhido)
    for (int c = CAP; c > 0 && ultimo[c] != -1; c -= tamanho[ultimo[c]]) {
        copias[ultimo[c]]++;
    }
    return melhor[CAP];
}

int main(void) {
    // o certo: A + B + C = 16 GB, nota 94; cada aula entra uma vez só
    printf("laço descendo (0/1): nota %d\n", mochila_descendo());

    int copias[N] = {0};
    printf("laço subindo:        nota %d, com", mochila_subindo(copias));
    for (int i = 0; i < N; i++) {
        if (copias[i] > 0) {
            printf(" %s x%d", nome[i], copias[i]);
        }
    }
    printf("\n");
    return 0;
}
// Saída:
// laço descendo (0/1): nota 94
// laço subindo:        nota 104, com B x1 D x4
