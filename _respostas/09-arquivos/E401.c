// 0067 · Arquivos texto
// Exercício E401 · ★★★
//
// O feof só fica verdadeiro depois que uma leitura falha. Depois do 20 ainda
// sobra o '\n', então o laço rodava uma quarta vez: o fscanf falhava, valor
// continuava 20 e era somado de novo. O conserto testa o retorno da leitura.

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
