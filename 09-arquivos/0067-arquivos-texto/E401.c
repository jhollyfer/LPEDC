// 0067 · Arquivos texto
// Exercício E401 · ★★★
//
// Este programa compila sem aviso e roda sem erro do sanitizer, mas a conta
// sai errada. Ele grava três Pix recebidos (R$ 50, R$ 30 e R$ 20) e depois
// soma. Rode e veja:
//
//   Pix: 50.00
//   Pix: 30.00
//   Pix: 20.00
//   Pix: 20.00
//   Total: 120.00
//
// O último Pix aparece duas vezes. Conserte o laço e rode de novo: a saída
// tem que mostrar só os três Pix e Total: 100.00.
//
// Dicas:
// 1. O feof só fica verdadeiro DEPOIS que uma leitura tenta passar do fim e
//    falha. Ele não "olha adiante".
// 2. Depois de ler o 20, ainda sobra o '\n': o feof continua falso. A quarta
//    chamada do fscanf falha, não mexe em valor (que ainda vale 20) e o código
//    soma assim mesmo.
// 3. Resposta esperada: troque o while (!feof(arq)) por
//    while (fscanf(arq, "%lf", &valor) == 1) { ... } e tire o fscanf de
//    dentro do laço. Saída: os três Pix e Total: 100.00.
//
// Escreva sua resposta abaixo (conserte o código):

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
    while (!feof(arq)) {
        if (fscanf(arq, "%lf", &valor) == EOF) {
            // fim: o fscanf não leu nada, mas o laço segue
        }
        printf("Pix: %.2f\n", valor);
        total += valor;
    }
    fclose(arq);
    remove(caminho);

    printf("Total: %.2f\n", total);
    return 0;
}
