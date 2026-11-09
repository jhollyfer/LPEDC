// Lista · Módulo 13 · Busca e ordenação
// Exercício P1306 · ★☆☆ · Intercalando as filas de embarque
//
// No aeroporto, os passageiros dos portões A e B chegam já em ordem de
// assento: A tem 4, 11, 18, 25, 30 e B tem 2, 9, 13. Complete a função
// intercala, que junta as duas filas numa só, em ordem, e devolve quantas
// comparações a[i] <= b[j] ela fez.
//
//   Saída esperada:
//   fila: 2 4 9 11 13 18 25 30
//   comparações: 5
//
// Dicas:
// 1. Enquanto as duas filas têm gente, compare as frentes e copie a menor.
// 2. Quando uma acaba, copie o resto da outra sem comparar nada.
// 3. O B acaba depois de 5 comparações (sai o 13); o 18, o 25 e o 30
//    descem direto. O pior caso seria na + nb - 1 = 7.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

// junta a[0..na-1] e b[0..nb-1] (ordenados) em c; devolve as comparações
int intercala(const int a[], int na, const int b[], int nb, int c[]) {
    int i = 0, j = 0, k = 0, comparacoes = 0;
    // complete aqui
    (void)a;
    (void)na;
    (void)b;
    (void)nb;
    (void)c;
    (void)i;
    (void)j;
    (void)k;
    return comparacoes;
}

int main(void) {
    int portao_a[] = {4, 11, 18, 25, 30};
    int portao_b[] = {2, 9, 13};
    int fila[8] = {0};

    int comp = intercala(portao_a, 5, portao_b, 3, fila);
    printf("fila:");
    for (int k = 0; k < 8; k++) {
        printf(" %d", fila[k]);
    }
    printf("\ncomparações: %d\n", comp);
    return 0;
}
