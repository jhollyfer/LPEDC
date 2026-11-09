// Lista · Módulo 13 · Busca e ordenação
// Exercício P1312 · ★★☆ · Encaixando consultas na agenda

#include <stdio.h>

// primeira posição com v[i] >= x (vai de 0 a n)
int ponto_insercao(const int v[], int n, int x) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        if (v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio - 1; // v[meio] >= x: a resposta é meio ou está antes
        }
    }
    return ini; // ao sair, ini é o primeiro com v[ini] >= x
}

// insere x mantendo a ordem; devolve a posição
int insere(int v[], int *n, int x) {
    int pos = ponto_insercao(v, *n, x);
    for (int i = *n; i > pos; i--) {
        v[i] = v[i - 1];
    }
    v[pos] = x;
    (*n)++;
    return pos;
}

int main(void) {
    int agenda[10] = {480, 540, 600, 660, 780, 840};
    int n = 6;
    int novas[] = {615, 450, 900, 600};

    for (int k = 0; k < 4; k++) {
        int pos = insere(agenda, &n, novas[k]);
        printf("%d entrou na posição %d:", novas[k], pos);
        for (int i = 0; i < n; i++) {
            printf(" %d", agenda[i]);
        }
        printf("\n");
    }
    return 0;
}
