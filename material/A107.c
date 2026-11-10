// A107 · A foto que não cabe na pilha

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int largura = 4000;
    int altura = 3000; // uma foto de 12 megapixels, em tons de cinza

    // 12.000.000 de bytes: como vetor local, estouraria a pilha de 8 MiB.
    // No heap, o limite é a memória livre da máquina.
    size_t total = (size_t)largura * altura;
    unsigned char *brilho = malloc(total * sizeof *brilho);
    if (brilho == NULL) { // pedido grande: o NULL é possível de verdade
        printf("Sem memória para a foto\n");
        return 1;
    }
    printf("Pedi %zu bytes ao heap\n", total * sizeof *brilho);

    // simula a foto: um degradê que vai de 0 (preto) a 255 (branco)
    for (size_t i = 0; i < total; i++) {
        brilho[i] = (unsigned char)(i % 256);
    }

    long soma = 0;
    int claros = 0;
    for (size_t i = 0; i < total; i++) {
        soma += brilho[i];
        if (brilho[i] >= 200) {
            claros++;
        }
    }
    printf("Brilho médio: %.2f\n", (double)soma / total);
    printf("Pixels claros: %d\n", claros);

    free(brilho); // 12 MB de volta ao heap de uma vez
    brilho = NULL;
    return 0;
}
// Saída:
// Pedi 12000000 bytes ao heap
// Brilho médio: 127.50
// Pixels claros: 2625000
//
// Troque o malloc por unsigned char brilho[12000000]; dentro do main e rode:
// o AddressSanitizer acusa stack-overflow antes da primeira linha.
