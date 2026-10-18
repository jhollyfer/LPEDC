// 0055 · Ponteiro para função
// Exercício E326 · ★☆☆

#include <stdio.h>

void para_cada(int *v, int n, void (*acao)(int *)) {
    for (int i = 0; i < n; i++) {
        acao(&v[i]);
    }
}

void dobra(int *x) { *x *= 2; }
void mostra(int *x) { printf("%d ", *x); }

int main(void) {
    int brindes[4] = {1, 2, 3, 4};

    para_cada(brindes, 4, mostra);
    printf("\n");
    para_cada(brindes, 4, dobra);
    para_cada(brindes, 4, mostra);
    printf("\n");
    return 0;
}
