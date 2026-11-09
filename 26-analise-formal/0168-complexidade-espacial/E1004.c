// 0168 · Complexidade espacial
// Exercício E1004 · ★☆☆
//
// A função separa abaixo copia as senhas pares para um vetor e as ímpares
// para outro, só para depois contar quantas há em cada um. Isso gasta
// 2n inteiros de espaço extra (80 bytes para 10 senhas, 8 MB para 1 milhão).
// Reescreva separa SEM malloc e sem nenhum vetor auxiliar: Θ(1) de espaço
// extra. O main e a saída não mudam:
//
//   Saída esperada:
//   pares: 6, ímpares: 4
//
// Dicas:
// 1. Para contar, não é preciso guardar: basta somar 1 no contador certo.
// 2. Faça *pares = 0 e *impares = 0 no começo e percorra senhas uma vez.
// 3. Tire o #include <stdlib.h> quando não usar mais malloc.
// 4. Resposta esperada: pares: 6, ímpares: 4.
//
// Escreva sua resposta abaixo (reescreva a função):

#include <stdio.h>
#include <stdlib.h>

void separa(const int senhas[], int n, int *pares, int *impares) {
    int *vp = malloc(n * sizeof(int));
    int *vi = malloc(n * sizeof(int));
    if (vp == NULL || vi == NULL) {
        free(vp);
        free(vi);
        return;
    }
    int np = 0, ni = 0;
    for (int i = 0; i < n; i++) {
        if (senhas[i] % 2 == 0) {
            vp[np++] = senhas[i];
        } else {
            vi[ni++] = senhas[i];
        }
    }
    *pares = np;
    *impares = ni;
    free(vp);
    free(vi);
}

int main(void) {
    int senhas[10] = {41, 12, 7, 30, 18, 25, 4, 16, 9, 22};
    int pares = 0, impares = 0;
    separa(senhas, 10, &pares, &impares);
    printf("pares: %d, ímpares: %d\n", pares, impares);
    return 0;
}
