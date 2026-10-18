// 0122 · Bucket sort
// Exercício E730 · ★★☆

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    double valor;
    struct No *prox;
} No;

No *insere_ordenado(No *lista, double x) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->valor = x;
    if (lista == NULL || x < lista->valor) {
        novo->prox = lista;
        return novo;
    }
    No *p = lista;
    while (p->prox != NULL && p->prox->valor <= x) {
        p = p->prox;
    }
    novo->prox = p->prox;
    p->prox = novo;
    return lista;
}

// junta os baldes de volta em v, liberando os nós
void junta(No *baldes[], int nb, double v[]) {
    int k = 0;
    for (int b = 0; b < nb; b++) {
        while (baldes[b] != NULL) {
            No *p = baldes[b];
            v[k++] = p->valor;
            baldes[b] = p->prox;
            free(p);
        }
    }
}

// valores em [0, 1): n baldes, o balde de x é (int) (x * n)
void bucket_sort_01(double v[], int n) {
    No **baldes = calloc(n, sizeof(No *));
    if (baldes == NULL) {
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        int b = (int) (v[i] * n);
        baldes[b] = insere_ordenado(baldes[b], v[i]);
    }
    junta(baldes, n, v);
    free(baldes);
}

// valores quaisquer: acha a faixa [menor, maior] e normaliza
void bucket_sort_faixa(double v[], int n) {
    double menor = v[0], maior = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < menor) {
            menor = v[i];
        }
        if (v[i] > maior) {
            maior = v[i];
        }
    }
    double largura = maior - menor;
    printf("faixa: %.1f a %.1f, %d baldes de %.2f\n", menor, maior, n, largura / n);
    No **baldes = calloc(n, sizeof(No *));
    if (baldes == NULL) {
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        int b = largura > 0 ? (int) ((v[i] - menor) / largura * n) : 0;
        if (b >= n) {
            b = n - 1; // o maior de todos cai no último balde
        }
        baldes[b] = insere_ordenado(baldes[b], v[i]);
    }
    junta(baldes, n, v);
    free(baldes);
}

void mostra(const double v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%.2f" : " %.2f", v[i]);
    }
    printf("\n");
}

int main(void) {
    double chuva[] = {0.35, 0.80, 0.05, 0.62, 0.41, 0.97};   // chance de chuva
    double temperaturas[] = {22.4, -3.5, 38.2, 15.0, 9.7, 30.1, -1.2, 27.8, 18.6, 4.3, 33.0, 12.9};

    bucket_sort_01(chuva, 6);
    mostra(chuva, 6);
    double iguais[] = {7.0, 7.0, 7.0};
    bucket_sort_faixa(temperaturas, 12);
    mostra(temperaturas, 12);
    bucket_sort_faixa(iguais, 3);
    mostra(iguais, 3);
    return 0;
}
