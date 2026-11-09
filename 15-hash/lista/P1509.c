// Lista · Módulo 15 · Tabelas hash
// Exercício P1509 · ★☆☆ · A busca que desistia cedo
//
// A tabela abaixo (m = 11, sondagem linear) insere 14, 25, 7, 36, 19. A
// inserção está certa, mas a busca tem um erro de propósito: ela diz que o
// 25 e o 36 não estão lá. Rode, entenda e conserte a busca.
//
//   Saída esperada (depois do conserto):
//   14: posição 3
//   25: posição 4
//   36: posição 5
//   19: posição 8
//   47: posição -1
//
// Dicas:
// 1. O 25 e o 36 têm h = 3, a mesma casa do 14, e foram empurrados para 4 e 5.
// 2. Quando a busca vê uma chave DIFERENTE na posição, isso prova que o k não
//    está ali, mas não que ele não está na tabela.
// 3. Resposta esperada: a busca só pode devolver -1 ao achar uma posição
//    VAZIA (ou depois de olhar as M posições). Tire o else que devolve -1 e
//    deixe a sondagem continuar; a saída fica igual à de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define M 11
#define VAZIO -1

void insere(int tab[], int k) {
    int pos = k % M;
    while (tab[pos] != VAZIO) {
        pos = (pos + 1) % M;
    }
    tab[pos] = k;
}

int busca(const int tab[], int k) {
    int pos = k % M;
    for (int i = 0; i < M; i++) {
        if (tab[pos] == VAZIO) {
            return -1;
        }
        if (tab[pos] == k) {
            return pos;
        } else {
            return -1;
        }
        pos = (pos + 1) % M;
    }
    return -1;
}

int main(void) {
    int tab[M];
    for (int i = 0; i < M; i++) {
        tab[i] = VAZIO;
    }
    int chaves[] = {14, 25, 7, 36, 19};
    for (int i = 0; i < 5; i++) {
        insere(tab, chaves[i]);
    }

    int procura[] = {14, 25, 36, 19, 47};
    for (int i = 0; i < 5; i++) {
        printf("%d: posição %d\n", procura[i], busca(tab, procura[i]));
    }
    return 0;
}
