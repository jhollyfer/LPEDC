// 0148 · Union-find
// Exercício E887 · ★★★

#include <stdio.h>

#define N 6

int pai[N];
int grupos = N;

int acha(int x) {
    while (pai[x] != x) {
        x = pai[x];
    }
    return x;
}

void une(int a, int b) {
    int ra = acha(a), rb = acha(b);
    if (ra != rb) {
        pai[ra] = rb; // pendura a RAIZ do grupo de a na raiz do grupo de b
        grupos--;
    }
}

int main(void) {
    const char *aluno[N] = {"Ana", "Bia", "Lia", "Rui", "Tom", "Vic"};
    for (int i = 0; i < N; i++) {
        pai[i] = i;
    }
    une(2, 0); // Lia estuda com Ana
    une(1, 0); // Bia estuda com Ana
    une(1, 2); // Bia e Lia (já estão juntas: nada muda)
    une(3, 4); // Rui estuda com Tom
    une(5, 4); // Vic estuda com Tom
    une(2, 5); // Lia estuda com Vic: os dois grupos viram um só

    int raizes = 0;
    for (int i = 0; i < N; i++) {
        raizes += pai[i] == i;
    }
    printf("grupos (contador): %d\n", grupos);
    printf("grupos (raízes):   %d\n", raizes);
    printf("%s e %s juntas? %s\n", aluno[0], aluno[2], acha(0) == acha(2) ? "sim" : "não");
    printf("%s e %s juntos? %s\n", aluno[0], aluno[3], acha(0) == acha(3) ? "sim" : "não");
    return 0;
}
