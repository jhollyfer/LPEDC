// A118 · Quem cria e quem libera

#include <stdio.h>
#include <stdlib.h>

// Divide um valor em n parcelas, em centavos. Os centavos que sobram vão
// para as primeiras parcelas. Devolve um bloco novo no heap: quem chama
// fica responsável pelo free.
int *parcelar(int total_centavos, int n) {
    int *parcelas = malloc(n * sizeof *parcelas); // sizeof *p: o tipo vem do ponteiro
    if (parcelas == NULL) {
        return NULL;
    }
    int base = total_centavos / n;
    int sobra = total_centavos % n;
    for (int i = 0; i < n; i++) {
        parcelas[i] = base + (i < sobra ? 1 : 0);
    }
    return parcelas; // o bloco sobrevive ao return
}

int main(void) {
    int n = 3;
    int *parcelas = parcelar(10000, n); // R$ 100,00 em 3 vezes
    if (parcelas == NULL) {
        printf("Sem memória\n");
        return 1;
    }

    printf("Bloco de %zu bytes no heap\n", n * sizeof *parcelas);
    for (int i = 0; i < n; i++) {
        printf("Parcela %d: R$ %d.%02d\n", i + 1, parcelas[i] / 100, parcelas[i] % 100);
    }

    free(parcelas);  // quem recebeu o bloco, libera
    parcelas = NULL;
    free(parcelas);  // free(NULL) não faz nada: é seguro
    return 0;
}
// Saída:
// Bloco de 12 bytes no heap
// Parcela 1: R$ 33.34
// Parcela 2: R$ 33.33
// Parcela 3: R$ 33.33
