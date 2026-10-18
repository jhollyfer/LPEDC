// 0075 · Juntando tudo
// Exercício E446 · ★☆☆
//
// Preveja a saída antes de rodar. O programa grava os mesmos quatro números
// num arquivo texto (um por linha) e num binário, e mostra o tamanho de cada
// um. Leia o código do E446.c, preveja e depois rode com:
//
//   $ rodar E446.c medidas
//
// Dicas:
// 1. No texto, cada número vira um caractere por dígito, mais o '\n'.
// 2. No binário, cada int ocupa sizeof(int) bytes, seja 7 ou 4000000.
// 3. argc conta o nome do programa.
// 4. Resposta esperada: "2 argumentos"; "/tmp/medidas.txt: 20 bytes";
//    "/tmp/medidas.bin: 16 bytes" (texto: 2 + 4 + 6 + 8 = 20; binário: 4 ints
//    de 4 bytes = 16).
//
// Escreva sua resposta abaixo (um comentário com a saída prevista) e depois
// rode para conferir:

#include <stdio.h>

long tamanho(const char *caminho) {
    FILE *arq = fopen(caminho, "rb");
    if (arq == NULL) {
        return -1;
    }
    fseek(arq, 0, SEEK_END);
    long t = ftell(arq);
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
        fprintf(t, "%d\n", v[i]);
    }
    fwrite(v, sizeof(int), 4, b);
    fclose(t);
    fclose(b);

    printf("%d argumentos\n", argc);
    printf("%s: %ld bytes\n", txt, tamanho(txt));
    printf("%s: %ld bytes\n", bin, tamanho(bin));
    remove(txt);
    remove(bin);
    return 0;
}
