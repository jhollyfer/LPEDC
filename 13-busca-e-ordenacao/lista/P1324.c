// Lista · Módulo 13 · Busca e ordenação
// Exercício P1324 · ★★★ · O quick sort com dois defeitos
//
// Este quick sort deveria ordenar os tempos de corrida de 9 entregadores,
// em minutos: 23, 8, 41, 15, 4, 36, 19, 2, 30. A partição de Lomuto tem DOIS
// erros de propósito. O programa não quebra; só ordena errado. Ache os dois,
// conserte e rode até sair:
//
//   Saída esperada:
//    2 4 8 15 19 23 30 36 41
//
// Dicas:
// 1. Faça o teste de mesa da primeira partição (pivô 30): quais elementos o
//    for olha? O 2, vizinho do pivô, é examinado?
// 2. Depois do for, onde está o pivô? A função devolve i + 1, mas o que tem
//    em v[i + 1]?
// 3. Na Lomuto do Cormen, j vai de p até r - 1 (inclusive) e, no fim, o pivô
//    troca de lugar com v[i + 1].
// 4. Resposta esperada: o for deve ser j < r (e não j < r - 1), e falta
//    troca(&v[i + 1], &v[r]); antes do return. Com os dois consertos, a
//    saída fica igual à de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particiona(int v[], int p, int r) {
    int pivo = v[r];
    int i = p - 1;
    for (int j = p; j < r - 1; j++) {
        if (v[j] <= pivo) {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    return i + 1;
}

void quick(int v[], int p, int r) {
    if (p < r) {
        int q = particiona(v, p, r);
        quick(v, p, q - 1);
        quick(v, q + 1, r);
    }
}

int main(void) {
    int corridas[] = {23, 8, 41, 15, 4, 36, 19, 2, 30};
    int n = 9;

    quick(corridas, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf(" %d", corridas[i]);
    }
    printf("\n");
    return 0;
}
