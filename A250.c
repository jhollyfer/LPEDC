// A250 · Dois sabores na casquinha: só os subconjuntos de tamanho k

#include <stdio.h>

#define N 5
#define K 2

const char *sabores[N] = {"açaí", "coco", "limão", "manga", "uva"};
int escolha[K];
int total = 0;

// escolhe o sabor da posição pos da casquinha, a partir do sabor inicio
void combina(int pos, int inicio) {
    if (pos == K) {
        total++;
        printf("%2d: %s + %s\n", total, sabores[escolha[0]], sabores[escolha[1]]);
        return;
    }
    // só sabores depois do último escolhido: "coco + açaí" não aparece,
    // porque é a mesma casquinha que "açaí + coco"
    for (int s = inicio; s < N; s++) {
        escolha[pos] = s;
        combina(pos + 1, s + 1);
    }
}

int main(void) {
    combina(0, 0);
    printf("C(%d, %d) = %d casquinhas\n", N, K, total);
    return 0;
}
// Saída:
//  1: açaí + coco
//  2: açaí + limão
//  3: açaí + manga
//  4: açaí + uva
//  5: coco + limão
//  6: coco + manga
//  7: coco + uva
//  8: limão + manga
//  9: limão + uva
// 10: manga + uva
// C(5, 2) = 10 casquinhas
