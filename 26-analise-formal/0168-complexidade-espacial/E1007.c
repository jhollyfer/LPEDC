// 0168 · Complexidade espacial
// Exercício E1007 · ★★★
//
// O estacionamento registrou as placas (números) que entraram no dia, em
// ordem crescente, com repetições. A função sem_repetidas deixa uma cópia
// de cada placa no começo do vetor e devolve quantas sobraram, mas faz
// isso com um vetor auxiliar de n posições. Reescreva a função para usar
// Θ(1) de espaço extra, sem malloc, mexendo no próprio vetor. A saída não
// muda:
//
//   Saída esperada:
//   12 placas, 7 distintas: 1020 1033 1047 1050 1062 1071 1088
//
// Dicas:
// 1. Use dois índices: le, que percorre todo o vetor, e escreve, que marca
//    a próxima posição livre do resultado.
// 2. Como o vetor está ordenado, uma placa é nova quando é diferente da
//    última que você escreveu, placas[escreve - 1].
// 3. escreve nunca passa de le: você só sobrescreve posições que já leu.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (reescreva a função):

#include <stdio.h>
#include <stdlib.h>

int sem_repetidas(int placas[], int n) {
    int *aux = malloc(n * sizeof(int));
    if (aux == NULL) {
        return 0;
    }
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (m == 0 || placas[i] != aux[m - 1]) {
            aux[m++] = placas[i];
        }
    }
    for (int i = 0; i < m; i++) {
        placas[i] = aux[i];
    }
    free(aux);
    return m;
}

int main(void) {
    int placas[12] = {1020, 1020, 1033, 1047, 1047, 1047, 1050, 1062, 1062, 1071, 1088, 1088};
    int m = sem_repetidas(placas, 12);
    printf("12 placas, %d distintas:", m);
    for (int i = 0; i < m; i++) {
        printf(" %d", placas[i]);
    }
    printf("\n");
    return 0;
}
