// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0903 · ★☆☆ · O livro-caixa que esquece vendas

#include <stdio.h>

int main(void) {
    const char *caminho = "/tmp/p0903_caixa.txt";

    // manhã
    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "12\n30\n8\n");
    fclose(arq);

    // tarde: "a" acrescenta no fim sem apagar o que já existe
    arq = fopen(caminho, "a");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "25\n");
    fprintf(arq, "15\n");
    fclose(arq); // despeja o buffer no disco antes de ler

    // fim do dia
    FILE *leitura = fopen(caminho, "r");
    if (leitura == NULL) {
        perror(caminho);
        return 1;
    }
    int venda, total = 0;
    while (fscanf(leitura, "%d", &venda) == 1) {
        printf("Venda: %d\n", venda);
        total += venda;
    }
    fclose(leitura);
    remove(caminho);

    printf("Total do dia: R$ %d\n", total);
    return 0;
}
