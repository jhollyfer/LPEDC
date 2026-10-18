// 0122 · Bucket sort
// Exercício E730 · ★★☆
//
// O programa abaixo tem um bucket sort que só aceita valores em [0, 1),
// como as chances de chuva: com n valores, usa n baldes, e o balde de x é
// (int) (x * n). Temperaturas não cabem nisso: podem ser negativas e passar
// de 1. Estenda o programa com void bucket_sort_faixa(double v[], int n),
// que acha o menor e o maior valor, mostra a faixa e usa n baldes de mesma
// largura entre eles. Teste com as temperaturas e com um vetor de valores
// todos iguais.
//
//   Saída esperada:
//   0.05 0.35 0.41 0.62 0.80 0.97
//   faixa: -3.5 a 38.2, 12 baldes de 3.48
//   -3.50 -1.20 4.30 9.70 12.90 15.00 18.60 22.40 27.80 30.10 33.00 38.20
//   faixa: 7.0 a 7.0, 3 baldes de 0.00
//   7.00 7.00 7.00
//
// Dicas:
// 1. O balde de x é (int) ((x - menor) / (maior - menor) * n): o menor vai
//    para o balde 0.
// 2. O maior dá exatamente n, que não existe: mande para o n - 1.
// 3. Valores todos iguais: maior - menor é 0, e a divisão por zero dá NaN.
//    Teste esse caso antes e mande todos para o balde 0.
// 4. Reaproveite insere_ordenado e junta. Formato da faixa:
//    "faixa: %.1f a %.1f, %d baldes de %.2f\n".
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (estenda o programa):

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
    (void) temperaturas; // apague estas duas linhas e ordene os dois
    (void) iguais;       // vetores com bucket_sort_faixa
    return 0;
}
