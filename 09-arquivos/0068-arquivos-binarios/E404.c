// 0068 · Arquivos binários
// Exercício E404 · ★☆☆
//
// Preveja a saída antes de rodar. O arquivo tem 4 ints, gravados em
// binário: 10, 20, 30 e 40. Cada int ocupa 4 bytes. Siga as chamadas de
// fseek, fread e ftell no E404.c e escreva o que cada printf mostra.
//
// Dicas:
// 1. SEEK_SET conta do começo, SEEK_CUR da posição atual e SEEK_END do fim.
//    O deslocamento pode ser negativo.
// 2. Cada fread de um int anda 4 bytes para a frente.
// 3. Resposta esperada: a) 30 (byte 8); b) posição 12; c) 20 (voltou 8
//    bytes: de 12 para 4); d) 40 (último int: 4 bytes antes do fim);
//    e) posição 16.
//
// Escreva sua resposta abaixo (um comentário com a saída prevista) e depois
// rode para conferir:

#include <stdio.h>

int main(void) {
    const char *caminho = "/tmp/quatro.bin";
    int v[4] = {10, 20, 30, 40};
    int x = 0;

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
    fseek(arq, 8, SEEK_SET);
    if (fread(&x, sizeof x, 1, arq) == 1) printf("a) %d\n", x);
    printf("b) posição %ld\n", ftell(arq));

    fseek(arq, -8, SEEK_CUR);
    if (fread(&x, sizeof x, 1, arq) == 1) printf("c) %d\n", x);

    fseek(arq, -4, SEEK_END);
    if (fread(&x, sizeof x, 1, arq) == 1) printf("d) %d\n", x);
    printf("e) posição %ld\n", ftell(arq));

    fclose(arq);
    remove(caminho);
    return 0;
}
