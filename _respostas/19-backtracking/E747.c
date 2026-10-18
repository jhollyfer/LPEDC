// 0125 · Subconjuntos
// Exercício E747 · ★★☆

#include <stdio.h>

#define N 6
#define CREDITO 30

typedef struct {
    const char *nome;
    int preco;
} Produto;

int main(void) {
    Produto p[N] = {{"queijo", 12}, {"café", 7}, {"carne", 18},
                    {"pão", 5},     {"frutas", 9}, {"frango", 14}};
    int achadas = 0;

    for (int m = 0; m < (1 << N); m++) {
        int soma = 0;
        for (int i = 0; i < N; i++) {
            if (m & (1 << i)) {
                soma += p[i].preco;
            }
        }
        if (soma != CREDITO) {
            continue;
        }
        achadas++;
        int primeiro = 1;
        for (int i = 0; i < N; i++) {
            if (m & (1 << i)) {
                printf(primeiro ? "%s" : " %s", p[i].nome);
                primeiro = 0;
            }
        }
        printf("\n");
    }
    printf("%d combinações de %d\n", achadas, 1 << N);
    return 0;
}
