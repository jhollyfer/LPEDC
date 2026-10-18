// 0073 · Invariantes de laço e corretude
// Exercício E438 · ★★★
//
// Resposta: Sobraram 4: 25 40 15 30.

#include <stdio.h>

// Recebe n >= 0 e v; tira os zeros de v[0..n-1], mantendo a ordem dos
// outros, e devolve quantos sobraram (eles ficam em v[0..i-1]).
int remove_zeros(int v[], int n) {
    int i = 0;
    for (int j = 0; j < n; j++) {
        // invariante: i <= j e v[0..i-1] são os não nulos de v[0..j-1]
        // original, na mesma ordem
        if (v[j] != 0) {
            v[i] = v[j];
            i++;
        }
    }
    return i;
}

int main(void) {
    int pedidos[8] = {25, 0, 0, 40, 0, 15, 30, 0};

    int n = remove_zeros(pedidos, 8);
    printf("Sobraram %d:", n);
    for (int k = 0; k < n; k++) {
        printf(" %d", pedidos[k]);
    }
    printf("\n");
    return 0;
}
