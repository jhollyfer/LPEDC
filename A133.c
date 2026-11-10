// A133 · A linha maior que o buffer

#include <stdio.h>
#include <string.h>

// O fgets nunca passa do tamanho que você dá: se a linha não cabe, ela chega
// em pedaços. Quem diz se a linha acabou é o '\n' no fim do pedaço.
int main(void) {
    const char *caminho = "/tmp/recados.txt";

    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fputs("Pagar luz\n", arq);                         // 9 letras + '\n'
    fputs("Levar o carro na revisao de sabado\n", arq); // não cabe em 12
    fputs("Pix\n", arq);
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    char pedaco[12]; // cabem 11 caracteres + o '\0'
    int chamadas = 0;
    int linhas = 0;
    while (fgets(pedaco, sizeof pedaco, arq) != NULL) {
        chamadas++;
        size_t n = strlen(pedaco);
        int fim_da_linha = n > 0 && pedaco[n - 1] == '\n';
        if (fim_da_linha) {
            pedaco[n - 1] = '\0'; // tira o '\n' só para mostrar
            linhas++;
        }
        printf("fgets %d: [%s]%s\n", chamadas, pedaco,
               fim_da_linha ? " <- fim da linha" : "");
    }
    fclose(arq);
    remove(caminho);

    printf("%d chamadas do fgets, %d linhas\n", chamadas, linhas);
    return 0;
}
// Saída:
// fgets 1: [Pagar luz] <- fim da linha
// fgets 2: [Levar o car]
// fgets 3: [ro na revis]
// fgets 4: [ao de sabad]
// fgets 5: [o] <- fim da linha
// fgets 6: [Pix] <- fim da linha
// 6 chamadas do fgets, 3 linhas
