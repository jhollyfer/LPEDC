// 0073 · Arquivos binários
// Exercício E437 · ★★★
//
// Resposta: a) dentro de salvar, v é um ponteiro e sizeof(v) vale 8: o fwrite
// gravava só 8 bytes (2 ints). O certo é fwrite(v, sizeof(int), n, arq).
// b) o main ignorava o retorno do fread (que era 2) e mostrava os zeros da
// inicialização. Agora ele confere se vieram os 5.

#include <stdio.h>

void salvar(const char *caminho, int *v, int n) {
    FILE *arq = fopen(caminho, "wb");
    if (arq == NULL) {
        perror(caminho);
        return;
    }
    fwrite(v, sizeof *v, n, arq); // n itens do tamanho de um int
    fclose(arq);
}

int main(void) {
    const char *caminho = "/tmp/agua.bin";
    int leituras[5] = {112, 98, 105, 120, 101};
    int lidas[5] = {0};

    salvar(caminho, leituras, 5);

    FILE *arq = fopen(caminho, "rb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    size_t n = fread(lidas, sizeof(int), 5, arq);
    fclose(arq);
    remove(caminho);
    if (n != 5) {
        printf("Esperava 5 leituras, vieram %zu\n", n);
        return 1;
    }

    printf("Leituras:");
    for (int i = 0; i < 5; i++) {
        printf(" %d", lidas[i]);
    }
    printf("\n");
    return 0;
}
