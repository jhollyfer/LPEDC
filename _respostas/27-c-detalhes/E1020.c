// 0170 · Precedência e ordem de avaliação
// Exercício E1020 · ★★★

#include <stdio.h>

int procurar(const int *v, int n, int alvo, int *lidos) {
    *lidos = 0;
    int i = 0;
    // i < n primeiro: se for falso, o && nem olha v[i]
    while (i < n && (++*lidos, v[i] != alvo)) {
        i++;
    }
    return i < n ? i : -1;
}

int main(void) {
    int codigos[] = {12, 7, 30, 7, 55};
    int lidos;

    int i = procurar(codigos, 5, 30, &lidos);
    printf("procurar 30: indice %d, leituras %d\n", i, lidos);

    i = procurar(codigos, 5, 99, &lidos);
    printf("procurar 99: indice %d, leituras %d\n", i, lidos);

    i = procurar(codigos, 0, 30, &lidos);
    printf("vetor vazio: indice %d, leituras %d\n", i, lidos);
    return 0;
}
