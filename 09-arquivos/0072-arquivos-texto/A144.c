// A144 · Acrescentar e somar

#include <stdio.h>

// Grava duas contas com "w", acrescenta uma terceira com "a" e depois lê tudo
// com fscanf para somar. No fim apaga o arquivo com remove.
int main(void) {
    const char *caminho = "/tmp/contas-do-mes.txt";

    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "Aluguel 1200.00\n");
    fprintf(arq, "Academia 89.90\n");
    fclose(arq);

    arq = fopen(caminho, "a"); // "a": escreve no fim, sem apagar nada
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "Streaming 39.90\n");
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    char nome[30];
    double valor;
    double total = 0.0;
    // fscanf devolve quantos campos conseguiu ler: 2 = linha completa
    while (fscanf(arq, "%29s %lf", nome, &valor) == 2) {
        printf("%-10s R$ %8.2f\n", nome, valor);
        total += valor;
    }
    fclose(arq);
    printf("%-10s R$ %8.2f\n", "Total", total);

    remove(caminho); // apaga o arquivo do disco
    return 0;
}
// Saída:
// Aluguel    R$  1200.00
// Academia   R$    89.90
// Streaming  R$    39.90
// Total      R$  1329.80
