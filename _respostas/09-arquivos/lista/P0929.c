// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0929 · ★★★ · O recado cifrado da linha de comando

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gira(int c, int k) {
    if (islower(c)) {
        return 'a' + ((c - 'a' + k) % 26 + 26) % 26;
    }
    if (isupper(c)) {
        return 'A' + ((c - 'A' + k) % 26 + 26) % 26;
    }
    return c;
}

int main(int argc, char *argv[]) {
    char *fim;
    long k = argc >= 3 ? strtol(argv[1], &fim, 10) : 0;
    if (argc < 3 || fim == argv[1] || *fim != '\0') {
        printf("uso: P0929 chave palavra1 palavra2 ...\n");
        return 1;
    }
    k %= 26;
    const char *caminho = "/tmp/p0929_recado.txt";

    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    for (int i = 2; i < argc; i++) {
        if (i > 2) {
            fputc(' ', arq);
        }
        for (size_t j = 0; argv[i][j] != '\0'; j++) {
            fputc(gira((unsigned char) argv[i][j], (int) k), arq);
        }
    }
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    char texto[1000] = "";
    if (fgets(texto, sizeof texto, arq) == NULL) {
        texto[0] = '\0';
    }
    fseek(arq, 0, SEEK_END);
    long bytes = ftell(arq);
    fclose(arq);
    remove(caminho);

    printf("Cifrado: %s\n", texto);
    printf("Arquivo: %ld bytes\n", bytes);
    for (size_t j = 0; texto[j] != '\0'; j++) {
        texto[j] = (char) gira((unsigned char) texto[j], (int) -k);
    }
    printf("Decifrado: %s\n", texto);
    return 0;
}
