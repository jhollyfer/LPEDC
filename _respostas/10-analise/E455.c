// 0076 · Eficiência: contar passos
// Exercício E455 · ★★★
//
// Resposta: (1) o passos++ vem antes do if, para contar também a comparação
// que acerta; (2) o contador é zerado dentro do for do main, antes de cada
// busca. Saída: 1, 4 e 6.

#include <stdio.h>

int passos = 0;

int busca(const int v[], int n, int alvo) {
    for (int i = 0; i < n; i++) {
        passos++;
        if (v[i] == alvo) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int senhas[6] = {12, 5, 30, 8, 19, 27};
    int alvos[3] = {12, 8, 40};

    for (int k = 0; k < 3; k++) {
        passos = 0;
        busca(senhas, 6, alvos[k]);
        printf("senha %d: passos %d\n", alvos[k], passos);
    }
    return 0;
}
