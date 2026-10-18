// 0103 · Heapsort
// Exercício E614 · ★☆☆
//
// A tabela do campeonato precisa dos pontos em ordem DECRESCENTE (o líder
// primeiro). Troque o heap de máximo por um heap de mínimo e o mesmo
// heapsort passa a deixar o menor no fim de cada passo. Complete desce_min,
// que desce v[i] trocando com o MENOR filho enquanto ele for menor que v[i].
//
//   Pontos: 45 62 38 70 51 29 66
//
//   Saída esperada:
//   Tabela: 70 66 62 51 45 38 29
//
// Dicas:
// 1. Copie o desce do texto e inverta as duas comparações.
// 2. Escolha f como o menor dos filhos; pare se v[i] <= v[f].
// 3. Resposta esperada: Tabela: 70 66 62 51 45 38 29
//
// Escreva sua resposta abaixo (complete desce_min):

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void desce_min(int v[], int n, int i) {
    (void)v; // apague estas três linhas
    (void)n;
    (void)i;
}

void heapsort_decrescente(int v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce_min(v, n, i);
    }
    for (int fim = n - 1; fim > 0; fim--) {
        troca(&v[0], &v[fim]); // o MENOR vai para o fim
        desce_min(v, fim, 0);
    }
}

int main(void) {
    int pontos[] = {45, 62, 38, 70, 51, 29, 66};
    heapsort_decrescente(pontos, 7);
    printf("Tabela:");
    for (int i = 0; i < 7; i++) {
        printf(" %d", pontos[i]);
    }
    printf("\n");
    return 0;
}
