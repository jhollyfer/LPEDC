// Lista · Módulo 15 · Tabelas hash
// Exercício P1523 · ★★★ · O cadastro que duplicava pacientes
//
// O posto de saúde guarda as fichas numa tabela aberta (m = 11, sondagem
// linear, VAZIO = -1, LAPIDE = -2). Ela insere 10, 21, 32, 43, 5 (os quatro
// primeiros com h = 10), remove o 21, procura o 32 e o 43 e tenta inserir o
// 32 DE NOVO (insere devolve -1 se a ficha já existe) e o 54. O código tem
// DOIS erros de propósito: um na busca e um na inserção. Ache, conserte e
// rode até sair:
//
//   Saída esperada:
//   tabela: 21 32 43 _ _ 5 _ _ _ _ 10
//   busca 32: 1
//   busca 43: 2
//   insere 32 de novo: -1
//   insere 54: 0
//   tabela: 54 32 43 _ _ 5 _ _ _ _ 10
//
// Dicas:
// 1. Antes do conserto, a busca não acha o 32 nem o 43, e o 32 aparece duas
//    vezes na tabela final.
// 2. Na busca, o que pode encerrar a procura: o VAZIO, a LAPIDE ou os dois?
// 3. Na inserção, ocupar a primeira lápide é certo, mas só depois de ter
//    certeza de que a chave não está mais adiante no caminho.
// 4. Resposta esperada: a busca para só no VAZIO (a lápide é pulada), e a
//    inserção chama busca(t, k) primeiro e devolve -1 se achar. Com os dois
//    consertos, a saída fica igual à de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define M 11
#define VAZIO -1
#define LAPIDE -2

int busca(const int t[], int k) {
    for (int i = 0; i < M; i++) {
        int pos = (k % M + i) % M;
        if (t[pos] == VAZIO || t[pos] == LAPIDE) {
            return -1;
        }
        if (t[pos] == k) {
            return pos;
        }
    }
    return -1;
}

// devolve a posição onde k ficou, ou -1 se k já existia
int insere(int t[], int k) {
    for (int i = 0; i < M; i++) {
        int pos = (k % M + i) % M;
        if (t[pos] == k) {
            return -1;
        }
        if (t[pos] == VAZIO || t[pos] == LAPIDE) {
            t[pos] = k;
            return pos;
        }
    }
    return -1;
}

void remove_chave(int t[], int k) {
    int pos = busca(t, k);
    if (pos >= 0) {
        t[pos] = LAPIDE;
    }
}

void mostra(const int t[]) {
    printf("tabela:");
    for (int i = 0; i < M; i++) {
        if (t[i] == VAZIO) {
            printf(" _");
        } else if (t[i] == LAPIDE) {
            printf(" X");
        } else {
            printf(" %d", t[i]);
        }
    }
    printf("\n");
}

int main(void) {
    int t[M];
    for (int i = 0; i < M; i++) {
        t[i] = VAZIO;
    }
    int fichas[] = {10, 21, 32, 43, 5};
    for (int i = 0; i < 5; i++) {
        insere(t, fichas[i]);
    }
    mostra(t);

    remove_chave(t, 21);
    printf("busca 32: %d\n", busca(t, 32));
    printf("busca 43: %d\n", busca(t, 43));
    printf("insere 32 de novo: %d\n", insere(t, 32));
    printf("insere 54: %d\n", insere(t, 54));
    mostra(t);
    return 0;
}
