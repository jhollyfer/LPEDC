// 0117 · Limite inferior da ordenação
// Exercício E699 · ★★☆
//
// Para achar o mínimo E o máximo de n temperaturas, o jeito óbvio compara
// cada uma com o mínimo e com o máximo: 2(n - 1) comparações. Dá para
// fazer com bem menos. Complete pares(): ande de DOIS em dois; compare os
// dois entre si (1 comparação), e só o menor do par disputa o mínimo e só
// o maior disputa o máximo (mais 2). São 3 comparações para cada 2
// elementos, em vez de 4. Use a função menor() para contar.
//
//   Saída esperada:
//   10 dias: mín 18, máx 35 | ingênuo 18 comparações | pares 13
//   11 dias: mín 18, máx 35 | ingênuo 20 comparações | pares 15
//
// Escreva sua resposta abaixo (complete pares):

#include <stdio.h>

int comparacoes = 0;

int menor(int a, int b) {
    comparacoes++;
    return a < b;
}

// cada elemento contra o mínimo e contra o máximo: 2(n - 1)
void ingenuo(const int v[], int n, int *mn, int *mx) {
    *mn = *mx = v[0];
    for (int i = 1; i < n; i++) {
        if (menor(v[i], *mn)) {
            *mn = v[i];
        }
        if (menor(*mx, v[i])) {
            *mx = v[i];
        }
    }
}

// de dois em dois: o menor do par disputa o mínimo, o maior disputa o máximo
void pares(const int v[], int n, int *mn, int *mx) {
    // escreva aqui (apague as quatro linhas abaixo)
    (void)v;
    (void)n;
    *mn = 0;
    *mx = 0;
}

void testa(const int v[], int n) {
    int mn, mx;
    comparacoes = 0;
    ingenuo(v, n, &mn, &mx);
    int c1 = comparacoes;
    comparacoes = 0;
    pares(v, n, &mn, &mx);
    printf("%d dias: mín %d, máx %d | ingênuo %d comparações | pares %d\n", n, mn, mx, c1, comparacoes);
}

int main(void) {
    int temp[11] = {23, 31, 18, 27, 35, 22, 19, 30, 26, 21, 33};
    testa(temp, 10);
    testa(temp, 11);
    return 0;
}
