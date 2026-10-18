// 0042 · Lendo strings
// Exercício E249 · ★★☆
//
// Este programa lê a quantidade de ingressos e o nome do comprador. Rode
// digitando 2 e Enter: ele nem espera você digitar o nome, e mostra o
// comprador vazio. O erro é de propósito. Explique por que acontece e
// conserte.
//
//   Exemplo de execução depois do conserto:
//   Quantidade de ingressos: 2
//   Nome do comprador: Ana Lima
//   2 ingresso(s) para Ana Lima
//
// Dicas:
// 1. O scanf("%d") lê o 2. E o Enter que você apertou depois do 2?
// 2. O fgets para no primeiro '\n' que encontrar.
// 3. Resposta esperada: o scanf deixa o '\n' na entrada; o fgets lê esse
//    '\n' na hora e devolve uma linha vazia. Conserto: depois do scanf,
//    descarte o resto da linha com
//    int c; while ((c = getchar()) != '\n' && c != EOF) {}
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

int main(void) {
    int quantidade;
    char nome[40];

    printf("Quantidade de ingressos: ");
    if (scanf("%d", &quantidade) != 1) {
        return 1;
    }

    printf("Nome do comprador: ");
    if (fgets(nome, sizeof(nome), stdin) == NULL) {
        return 1;
    }
    nome[strcspn(nome, "\n")] = '\0';

    printf("%d ingresso(s) para %s\n", quantidade, nome);
    return 0;
}
