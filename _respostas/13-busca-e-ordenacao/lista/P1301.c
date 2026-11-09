// Lista · Módulo 13 · Busca e ordenação
// Exercício P1301 · ★☆☆ · A placa no estacionamento, com sentinela

#include <stdio.h>

// busca com sentinela: x vai para v[n], e o laço não testa o fim do vetor
int busca_sentinela(int v[], int n, int x, int *comparacoes) {
    v[n] = x;
    int i = 0;
    *comparacoes = 1;
    while (v[i] != x) {
        i++;
        (*comparacoes)++;
    }
    return i < n ? i : -1;
}

int main(void) {
    int placas[9] = {4821, 1307, 9954, 2210, 6638, 7012, 3389, 5146}; // 8 + 1 vaga para a sentinela
    int n = 8;
    int procuradas[] = {2210, 5146, 1000};
    int c;

    for (int k = 0; k < 3; k++) {
        int pos = busca_sentinela(placas, n, procuradas[k], &c);
        printf("Placa %d: posição %d (%d comparações)\n", procuradas[k], pos, c);
    }
    return 0;
}
