// Lista · Módulo 15 · Tabelas hash
// Exercício P1509 · ★☆☆ · A busca que desistia cedo
//
// Resposta: na sondagem linear, a busca só pode concluir "não está" quando
// encontra uma posição VAZIA. Uma posição ocupada por OUTRA chave é só uma
// colisão: é preciso continuar para a próxima. O else que devolvia -1 ao ver
// uma chave diferente fazia o 25 e o 36 (que colidiram com o 14) sumirem.

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
