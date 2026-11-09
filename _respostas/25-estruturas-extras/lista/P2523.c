// Lista · Módulo 25 · Estruturas especiais
// Exercício P2523 · ★★★ · O jogo da vida esparso

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 64

typedef struct {
    int lin, col;
} Celula;

int compara(const void *a, const void *b) {
    const Celula *x = a, *y = b;
    if (x->lin != y->lin) return x->lin - y->lin;
    return x->col - y->col;
}

int viva(const Celula v[], int n, Celula c) { // busca binária
    return bsearch(&c, v, n, sizeof(Celula), compara) != NULL;
}

// próxima geração olhando só as vivas e os vizinhos delas
int proxima(const Celula v[], int n, Celula nova[]) {
    Celula cand[8 * MAXV];
    int nc = 0;
    for (int i = 0; i < n; i++)
        for (int dl = -1; dl <= 1; dl++)
            for (int dc = -1; dc <= 1; dc++)
                if (dl != 0 || dc != 0) cand[nc++] = (Celula){v[i].lin + dl, v[i].col + dc};
    qsort(cand, nc, sizeof(Celula), compara);
    int m = 0;
    for (int i = 0; i < nc;) {
        int j = i;
        while (j < nc && compara(&cand[j], &cand[i]) == 0) j++;
        int vizinhos = j - i; // a célula apareceu uma vez por vizinha viva
        if (vizinhos == 3 || (vizinhos == 2 && viva(v, n, cand[i]))) nova[m++] = cand[i];
        i = j;
    }
    return m; // já sai em ordem, porque cand estava ordenado
}

void mostra(int g, const Celula v[], int n) {
    printf("geração %d (%d vivas):", g, n);
    for (int i = 0; i < n; i++) printf(" (%d,%d)", v[i].lin, v[i].col);
    printf("\n");
}

int main(void) {
    // um planador: anda uma casa na diagonal a cada 4 gerações
    Celula v[MAXV] = {{0, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
    int n = 5;
    mostra(0, v, n);
    for (int g = 1; g <= 4; g++) {
        Celula nova[MAXV];
        n = proxima(v, n, nova);
        memcpy(v, nova, n * sizeof(Celula));
        mostra(g, v, n);
    }
    // depois de 400 gerações ele está 100 casas longe: a matriz cheia teria
    // que ser enorme, a esparsa continua com 5 células
    for (int g = 5; g <= 400; g++) {
        Celula nova[MAXV];
        n = proxima(v, n, nova);
        memcpy(v, nova, n * sizeof(Celula));
    }
    mostra(400, v, n);
    return 0;
}
