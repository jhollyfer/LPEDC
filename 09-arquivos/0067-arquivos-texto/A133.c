// A133 · O caderno de despesas

#include <stdio.h>

int main(void) {
    const char *caminho = "/tmp/despesas.txt";

    // 1. Gravar: "w" cria o arquivo (ou apaga o que tinha)
    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror("Erro ao criar o arquivo");
        return 1;
    }
    fprintf(arq, "Mercado %.2f\n", 152.40);  // igual ao printf, mas vai pro arquivo
    fprintf(arq, "Luz %.2f\n", 98.75);
    fprintf(arq, "Internet %.2f\n", 99.90);
    fclose(arq); // descarrega o buffer no disco e libera o FILE

    // 2. Ler de volta, linha por linha
    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    char linha[100];
    int n = 0;
    while (fgets(linha, sizeof linha, arq) != NULL) { // NULL = acabou o arquivo
        n++;
        printf("%d: %s", n, linha); // a linha já traz o '\n'
    }
    fclose(arq);

    printf("%d linhas em %s\n", n, caminho);
    return 0;
}
// Saída:
// 1: Mercado 152.40
// 2: Luz 98.75
// 3: Internet 99.90
// 3 linhas em /tmp/despesas.txt
//
// O arquivo continua lá: confira com  cat /tmp/despesas.txt
