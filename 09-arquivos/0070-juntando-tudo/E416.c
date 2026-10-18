// 0070 · Juntando tudo
// Exercício E416 · ★☆☆
//
// Texto ou binário: quem ocupa mais? O programa recebe um nome pela linha de
// comando e monta dois caminhos, /tmp/<nome>.txt e /tmp/<nome>.bin. Complete
// as duas partes marcadas com TODO:
//
// a) a função tamanho, que devolve o tamanho do arquivo em bytes (ou -1 se
//    não abrir);
// b) a gravação dos quatro números de v: no texto, um por linha com
//    fprintf; no binário, todos de uma vez com UM fwrite.
//
//   $ rodar E416.c medidas
//   2 argumentos
//   /tmp/medidas.txt: 20 bytes
//   /tmp/medidas.bin: 16 bytes
//
// Dicas:
// 1. Tamanho: abra com "rb", fseek(arq, 0, SEEK_END), guarde o ftell e
//    feche o arquivo antes de devolver.
// 2. No texto, cada número vira um caractere por dígito, mais o '\n'. No
//    binário, cada int ocupa sizeof(int) bytes, seja 7 ou 4000000.
// 3. Resposta esperada: a saída acima (texto: 2 + 4 + 6 + 8 = 20; binário:
//    4 ints de 4 bytes = 16).
//
// Escreva sua resposta abaixo (complete onde estão os TODO):

#include <stdio.h>

long tamanho(const char *caminho) {
    // TODO a): abrir, ir para o fim, perguntar a posição, fechar
    (void) caminho; // apague esta linha quando usar o parâmetro
    return -1;
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
    // TODO b): gravar v no texto (um por linha) e no binário (um fwrite)
    (void) v; // apague esta linha quando usar v
    fclose(t);
    fclose(b);

    printf("%d argumentos\n", argc);
    printf("%s: %ld bytes\n", txt, tamanho(txt));
    printf("%s: %ld bytes\n", bin, tamanho(bin));
    remove(txt);
    remove(bin);
    return 0;
}
