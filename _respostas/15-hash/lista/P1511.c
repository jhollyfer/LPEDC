// Lista · Módulo 15 · Tabelas hash
// Exercício P1511 · ★★☆ · A lápide que segura a busca

#include <stdio.h>

#define M 7
#define VAZIO -1
#define LAPIDE -2

void mostra(const char *rotulo, const int t[]) {
    printf("%s", rotulo); // o rótulo já vem com os espaços
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

int busca(const int t[], int k) {
    for (int i = 0; i < M; i++) {
        int pos = (k % M + i) % M;
        if (t[pos] == VAZIO) {
            return -1;     // só o vazio encerra a busca
        }
        if (t[pos] == k) {
            return pos;    // a lápide não é igual a nada: a busca passa reto
        }
    }
    return -1;
}

// a inserção pode reaproveitar a primeira lápide do caminho
void insere(int t[], int k) {
    for (int i = 0; i < M; i++) {
        int pos = (k % M + i) % M;
        if (t[pos] == VAZIO || t[pos] == LAPIDE) {
            t[pos] = k;
            return;
        }
    }
}

void remove_chave(int t[], int k, int marca) {
    int pos = busca(t, k);
    if (pos >= 0) {
        t[pos] = marca;
    }
}

int main(void) {
    int com[M], sem[M];
    for (int i = 0; i < M; i++) {
        com[i] = sem[i] = VAZIO;
    }
    int chaves[] = {10, 17, 24, 5, 12};
    for (int i = 0; i < 5; i++) {
        insere(com, chaves[i]);
        insere(sem, chaves[i]);
    }
    mostra("início:    ", com);

    remove_chave(sem, 17, VAZIO);
    remove_chave(com, 17, LAPIDE);
    mostra("sem lápide:", sem);
    mostra("com lápide:", com);
    printf("busca 24 sem lápide: %d\n", busca(sem, 24));
    printf("busca 24 com lápide: %d\n", busca(com, 24));

    insere(com, 31);
    mostra("entra o 31:", com);
    return 0;
}
