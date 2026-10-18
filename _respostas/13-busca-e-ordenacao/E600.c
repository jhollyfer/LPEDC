// 0100 · Quick sort
// Exercício E600 · ★★★

#include <stdio.h>

static int comparacoes;

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    for (int k = p; k < r; k++) {
        comparacoes++;
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

void quick_lomuto(int v[], int p, int r) {
    if (p >= r) {
        return;
    }
    int j = separa(v, p, r);
    quick_lomuto(v, p, j - 1);
    quick_lomuto(v, j + 1, r);
}

// três montes: v[p..lt-1] < pivô, v[lt..gt] == pivô, v[gt+1..r] > pivô
void quick_3vias(int v[], int p, int r) {
    if (p >= r) {
        return;
    }
    int pivo = v[r];
    int lt = p, i = p, gt = r;
    while (i <= gt) {
        comparacoes++;                  // uma comparação de três saídas
        if (v[i] < pivo) {
            troca(&v[lt], &v[i]);
            lt++;
            i++;
        } else if (v[i] > pivo) {
            troca(&v[i], &v[gt]);
            gt--;                       // o que veio de gt ainda não foi olhado
        } else {
            i++;
        }
    }
    quick_3vias(v, p, lt - 1);          // os iguais ficam de fora
    quick_3vias(v, gt + 1, r);
}

void testa(const char *nome, const int origem[], int n) {
    int a[12], b[12];
    for (int i = 0; i < n; i++) {
        a[i] = b[i] = origem[i];
    }
    comparacoes = 0;
    quick_lomuto(a, 0, n - 1);
    int c1 = comparacoes;
    comparacoes = 0;
    quick_3vias(b, 0, n - 1);
    printf("%s Lomuto %2d, três vias %2d |", nome, c1, comparacoes);
    for (int i = 0; i < n; i++) {
        printf(" %d", b[i]);
    }
    printf("\n");
}

int main(void) {
    int estrelas[] = {2, 3, 1, 2, 2, 3, 1, 1, 2, 3, 2, 1};
    int iguais[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    testa("1 a 3 estrelas:", estrelas, 12);
    testa("todos iguais:  ", iguais, 12);
    return 0;
}
