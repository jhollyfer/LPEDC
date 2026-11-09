// Lista · Módulo 15 · Tabelas hash
// Exercício P1522 · ★★★ · Quando as lápides tomam conta

#include <stdio.h>

#define M 11
#define VAZIO -1
#define LAPIDE -2

int t[M];

int busca(int k, int *sondagens) {
    *sondagens = 0;
    for (int i = 0; i < M; i++) {
        int pos = (k % M + i) % M;
        (*sondagens)++;
        if (t[pos] == VAZIO) {
            return -1;
        }
        if (t[pos] == k) {
            return pos;
        }
    }
    return -1;
}

void insere(int k) {
    int s;
    if (busca(k, &s) >= 0) {
        return;
    }
    for (int i = 0; i < M; i++) {
        int pos = (k % M + i) % M;
        if (t[pos] == VAZIO || t[pos] == LAPIDE) {
            t[pos] = k;
            return;
        }
    }
}

void remove_chave(int k) {
    int s, pos = busca(k, &s);
    if (pos >= 0) {
        t[pos] = LAPIDE;
    }
}

// reinsere só as chaves vivas numa tabela limpa (mesmo m)
void reconstroi(void) {
    int vivas[M], n = 0;
    for (int i = 0; i < M; i++) {
        if (t[i] >= 0) {
            vivas[n++] = t[i];
        }
        t[i] = VAZIO;
    }
    for (int i = 0; i < n; i++) {
        insere(vivas[i]);
    }
}

void relatorio(const char *quando) {
    int ocupadas = 0, lapides = 0, total = 0;
    for (int i = 0; i < M; i++) {
        ocupadas += t[i] >= 0;
        lapides += t[i] == LAPIDE;
    }
    // média das buscas SEM sucesso, uma começando em cada posição
    for (int h = 0; h < M; h++) {
        int s;
        busca(1100 + h, &s); // 1100 % 11 = 0: a chave 1100 + h começa em h
        total += s;
    }
    printf("%-11s", quando);
    for (int i = 0; i < M; i++) {
        if (t[i] == VAZIO) {
            printf(" _");
        } else if (t[i] == LAPIDE) {
            printf(" X");
        } else {
            printf(" %d", t[i]);
        }
    }
    printf("\n  vivas %d, lápides %d, busca sem sucesso: %.2f sondagens\n", ocupadas, lapides, (double)total / M);
}

int main(void) {
    for (int i = 0; i < M; i++) {
        t[i] = VAZIO;
    }
    int entram[] = {22, 34, 46, 58, 13, 70, 81, 92};
    for (int i = 0; i < 8; i++) {
        insere(entram[i]);
    }
    relatorio("cheia:");

    int saem[] = {22, 46, 13, 81, 92};
    for (int i = 0; i < 5; i++) {
        remove_chave(saem[i]);
    }
    relatorio("removidas:");

    reconstroi();
    relatorio("refeita:");
    return 0;
}
