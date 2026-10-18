// 0068 · Arquivos binários
// Exercício E404 · ★☆☆

#include <stdio.h>

// lê um int da posição atual e mostra o valor e onde o arquivo parou
void ler_e_mostrar(FILE *arq, const char *rotulo) {
    int x;
    if (fread(&x, sizeof x, 1, arq) == 1) {
        printf("%s %d, agora na posição %ld\n", rotulo, x, ftell(arq));
    } else {
        printf("%s nada lido\n", rotulo);
    }
}

int main(void) {
    const char *caminho = "/tmp/quatro.bin";
    int v[4] = {10, 20, 30, 40};

    FILE *arq = fopen(caminho, "wb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fwrite(v, sizeof(int), 4, arq);
    fclose(arq);

    arq = fopen(caminho, "rb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fseek(arq, 8, SEEK_SET);  // byte 8: o 3º int
    ler_e_mostrar(arq, "a)");
    fseek(arq, -8, SEEK_CUR); // de 12 volta para 4: o 2º int
    ler_e_mostrar(arq, "b)");
    fseek(arq, -4, SEEK_END); // 4 bytes antes do fim: o último int
    ler_e_mostrar(arq, "c)");
    rewind(arq);              // byte 0: o 1º int
    ler_e_mostrar(arq, "d)");

    fclose(arq);
    remove(caminho);
    return 0;
}
