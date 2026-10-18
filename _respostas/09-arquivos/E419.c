// 0070 · Juntando tudo
// Exercício E419 · ★★★
//
// Resposta: (1) "w" apagava o diário a cada execução: o certo é "a".
// (2) Faltava fclose(arq) antes de abrir para leitura: o texto ainda estava no
// buffer da RAM e a leitura achava o arquivo vazio. (3) "anota <texto>" tem
// argc == 3; com argc < 2, "rodar E419.c anota" chegava ao fprintf com
// argv[2] == NULL.

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const char *caminho = "/tmp/diario.txt";
    if (argc != 3 || strcmp(argv[1], "anota") != 0) {
        fprintf(stderr, "Uso: %s anota <texto>\n", argv[0]);
        return 1;
    }

    FILE *arq = fopen(caminho, "a");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "%s\n", argv[2]);
    fclose(arq); // descarrega o buffer antes de ler

    FILE *leitura = fopen(caminho, "r");
    if (leitura == NULL) {
        perror(caminho);
        return 1;
    }
    char linhas[50][100];
    int n = 0;
    while (n < 50 && fgets(linhas[n], sizeof linhas[n], leitura) != NULL) {
        n++;
    }
    fclose(leitura);

    printf("%d anotações:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%s", linhas[i]);
    }
    return 0;
}
