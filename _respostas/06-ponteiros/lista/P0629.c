// Lista · Módulo 06 · Ponteiros
// Exercício P0629 · ★★★ · Embaralhar qualquer vetor

#include <stdio.h>

unsigned sorteio(unsigned *semente, unsigned n) {
    *semente = *semente * 1103515245u + 12345u; // dá a volta sem problema
    return (*semente / 65536) % n;
}

void troca_bytes(void *a, void *b, size_t tam) {
    unsigned char *pa = a, *pb = b;
    for (size_t k = 0; k < tam; k++) {
        unsigned char aux = pa[k];
        pa[k] = pb[k];
        pb[k] = aux;
    }
}

void embaralhar(void *v, size_t n, size_t tam, unsigned *semente) {
    unsigned char *base = v;
    for (size_t i = n - 1; i >= 1; i--) {
        size_t j = sorteio(semente, (unsigned) (i + 1));
        if (j != i) {
            troca_bytes(base + i * tam, base + j * tam, tam);
        }
    }
}

int main(void) {
    int bolas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char nomes[4][12] = {"Dona Lia", "Seu Ze", "Rita", "Padre Joao"};
    unsigned semente = 2026;

    embaralhar(bolas, 10, sizeof bolas[0], &semente);
    printf("Bolas:");
    for (int i = 0; i < 10; i++) {
        printf(" %d", bolas[i]);
    }
    printf("\n");

    embaralhar(nomes, 4, sizeof nomes[0], &semente);
    printf("Ordem de chamada:");
    for (int i = 0; i < 4; i++) {
        printf(" %s%s", nomes[i], i < 3 ? "," : "\n");
    }
    printf("Semente final: %u\n", semente);
    return 0;
}
