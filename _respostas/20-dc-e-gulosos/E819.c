// 0137 · Juntando tudo
// Exercício E819 · ★★☆

#include <stdio.h>
#include "compactador.h"

int main(void) {
    const char *linha = "Pão francês ..... R$ 0,75 a unidade\n";
    int vezes[] = {1, 10, 30, 60, 100, 300};

    printf("linhas  original  compactado\n");
    for (int k = 0; k < 6; k++) {
        FILE *f = fopen("padaria.txt", "w");
        if (f == NULL) {
            return 1;
        }
        for (int i = 0; i < vezes[k]; i++) {
            fputs(linha, f);
        }
        fclose(f);
        long antes = arq_tamanho("padaria.txt");
        long depois = huf_compacta("padaria.txt", "padaria.huf");
        printf("%6d  %8ld  %10ld  %s\n", vezes[k], antes, depois,
               depois < antes ? "compensa" : "não compensa");
    }
    remove("padaria.txt");
    remove("padaria.huf");
    return 0;
}
