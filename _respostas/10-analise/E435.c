// 0073 · Invariantes de laço e corretude
// Exercício E435 · ★★☆

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// true se x não aparece em v[ini..fim-1]. Pedaço vazio: true.
bool nao_esta(const int v[], int ini, int fim, int x) {
    for (int j = ini; j < fim; j++) {
        if (v[j] == x) {
            return false;
        }
    }
    return true;
}

// Recebe n >= 0, v e x; devolve o maior k tal que v[k] == x, ou -1 se não há.
int ultima(const int v[], int n, int x) {
    int k = n - 1;
    while (k >= 0 && v[k] != x) {
        // invariante: x não está em v[k+1..n-1]
        assert(nao_esta(v, k + 1, n, x));
        k--;
    }
    // término: parou porque k == -1 (x não está em nada) ou porque v[k] == x
    assert(nao_esta(v, k + 1, n, x));
    assert(k == -1 || v[k] == x);
    return k;
}

int main(void) {
    int notas[5] = {7, 9, 4, 9, 6};

    printf("última nota 9: posição %d\n", ultima(notas, 5, 9));
    printf("última nota 5: posição %d\n", ultima(notas, 5, 5));
    printf("última nota 7: posição %d\n", ultima(notas, 5, 7));
    printf("vetor vazio: posição %d\n", ultima(notas, 0, 9));
    return 0;
}
