// 0072 · Arquivos texto
// Exercício E431 · ★★★
//
// Resposta: a) feof só fica verdadeiro depois que uma leitura falha. Depois do
// 20 ainda sobra o '\n', então o laço roda uma quarta vez: o fscanf falha, valor
// continua 20 e é somado de novo. b) Teste o retorno da própria leitura.

#include <stdio.h>

int main(void) {
    const char *caminho = "/tmp/pix.txt";

    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "50.00\n30.00\n20.00\n");
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    double valor = 0.0;
    double total = 0.0;
    while (fscanf(arq, "%lf", &valor) == 1) {
        printf("Pix: %.2f\n", valor);
        total += valor;
    }
    fclose(arq);
    remove(caminho);

    printf("Total: %.2f\n", total);
    return 0;
}
