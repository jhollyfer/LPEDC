// A189 · Duas pontas que se encontram: a separação de Hoare

#include <stdio.h>

static int trocas;

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
    trocas++;
}

// Lomuto (a do texto): um índice só, varrendo da esquerda para a direita
int lomuto(int v[], int p, int r) {
    int pivo = v[r], j = p;
    for (int k = p; k < r; k++) {
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

void quick_lomuto(int v[], int p, int r) {
    if (p >= r) return;
    int j = lomuto(v, p, r);
    quick_lomuto(v, p, j - 1);
    quick_lomuto(v, j + 1, r);
}

// Hoare: i vem da esquerda, j vem da direita; só troca quem está do lado errado.
// Devolve j tal que v[p..j] <= pivô <= v[j+1..r] (o pivô não fica "no lugar").
int hoare(int v[], int p, int r) {
    int pivo = v[p + (r - p) / 2];
    int i = p - 1, j = r + 1;
    while (1) {
        do { i++; } while (v[i] < pivo);    // para num que é >= pivô
        do { j--; } while (v[j] > pivo);    // para num que é <= pivô
        if (i >= j) {
            return j;                        // as pontas se cruzaram
        }
        troca(&v[i], &v[j]);
    }
}

void quick_hoare(int v[], int p, int r) {
    if (p >= r) return;
    int j = hoare(v, p, r);
    quick_hoare(v, p, j);                    // repare: j, e não j - 1
    quick_hoare(v, j + 1, r);
}

void mostra(const char *nome, const int v[], int n) {
    printf("%-7s %2d trocas:", nome, trocas);
    for (int i = 0; i < n; i++) printf(" %d", v[i]);
    printf("\n");
}

int main(void) {
    // idades na fila da vacinação
    int a[] = {67, 23, 81, 45, 30, 72, 18, 55, 39, 60};
    int b[] = {67, 23, 81, 45, 30, 72, 18, 55, 39, 60};
    int n = 10;

    trocas = 0;
    quick_lomuto(a, 0, n - 1);
    mostra("Lomuto:", a, n);

    trocas = 0;
    quick_hoare(b, 0, n - 1);
    mostra("Hoare:", b, n);
    return 0;
}
// O Lomuto conta até as trocas de alguém com ele mesmo; o Hoare só troca
// pares que estão do lado errado.
// Saída:
// Lomuto: 17 trocas: 18 23 30 39 45 55 60 67 72 81
// Hoare:   8 trocas: 18 23 30 39 45 55 60 67 72 81
