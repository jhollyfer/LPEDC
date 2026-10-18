// A135 · Ler em lotes: o retorno do fread

#include <stdio.h>

// O fread devolve quantos itens leu de verdade. Pedindo 3 de cada vez num
// arquivo com 7, vêm 3, 3, 1 e depois 0. O último lote vem incompleto, e é o
// retorno (não o tamanho do vetor) que diz quantos valem.
int main(void) {
    const char *caminho = "/tmp/passos.bin";
    int passos[7] = {8200, 10450, 6300, 12010, 9800, 4100, 11500}; // da semana

    FILE *arq = fopen(caminho, "wb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fwrite(passos, sizeof(int), 7, arq);
    fclose(arq);

    arq = fopen(caminho, "rb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    int lote[3];
    size_t lidos;
    long total = 0;
    int dia = 1;
    while ((lidos = fread(lote, sizeof(int), 3, arq)) > 0) {
        printf("Pedi 3, vieram %zu:", lidos);
        for (size_t i = 0; i < lidos; i++) { // só os que vieram
            printf(" dia %d=%d", dia, lote[i]);
            total += lote[i];
            dia++;
        }
        printf("\n");
    }
    printf("Pedi 3, vieram 0: fim (feof = %d)\n", feof(arq) != 0);

    // fseek para depois do fim não dá erro, mas o fread não acha nada
    fseek(arq, 100 * (long) sizeof(int), SEEK_SET);
    long posicao = ftell(arq);
    int x = -1;
    size_t r = fread(&x, sizeof x, 1, arq);
    printf("No byte %ld: fread devolveu %zu, x continua %d\n", posicao, r, x);
    fclose(arq);
    remove(caminho);

    printf("Total da semana: %ld passos\n", total);
    return 0;
}
// Saída:
// Pedi 3, vieram 3: dia 1=8200 dia 2=10450 dia 3=6300
// Pedi 3, vieram 3: dia 4=12010 dia 5=9800 dia 6=4100
// Pedi 3, vieram 1: dia 7=11500
// Pedi 3, vieram 0: fim (feof = 1)
// No byte 400: fread devolveu 0, x continua -1
// Total da semana: 62360 passos
