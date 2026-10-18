// 0070 · Juntando tudo
// Exercício E416 · ★☆☆

#include <stdio.h>

long tamanho(const char *caminho) {
    FILE *arq = fopen(caminho, "rb");
    if (arq == NULL) {
        return -1;
    }
    fseek(arq, 0, SEEK_END);
    long t = ftell(arq); // posição no fim = tamanho em bytes
    fclose(arq);
    return t;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <nome>\n", argv[0]);
        return 1;
    }
    int v[4] = {7, 250, 31000, 4000000};
    char txt[64], bin[64];
    snprintf(txt, sizeof txt, "/tmp/%s.txt", argv[1]); // monta o caminho
    snprintf(bin, sizeof bin, "/tmp/%s.bin", argv[1]);

    FILE *t = fopen(txt, "w");
    FILE *b = fopen(bin, "wb");
    if (t == NULL || b == NULL) {
        perror("fopen");
        if (t != NULL) fclose(t);
        if (b != NULL) fclose(b);
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        fprintf(t, "%d\n", v[i]); // um caractere por dígito + '\n'
    }
    fwrite(v, sizeof(int), 4, b); // 4 bytes por int, qualquer valor
    fclose(t);
    fclose(b);

    printf("%d argumentos\n", argc);
    printf("%s: %ld bytes\n", txt, tamanho(txt));
    printf("%s: %ld bytes\n", bin, tamanho(bin));
    remove(txt);
    remove(bin);
    return 0;
}
