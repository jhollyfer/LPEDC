// 0026 · Do-while
// Exercício E154 · ★★☆
//
// Resposta: a condição "opcao < 1 && opcao > 3" é sempre falsa, então o laço
// nunca repete. O certo é "opcao < 1 || opcao > 3". Com 7 e 2, o totem
// pergunta duas vezes e mostra "Sessão 2 escolhida.".

#include <stdio.h>

int main(void) {
    int opcao;

    do {
        printf("Sessão (1, 2 ou 3): ");
        if (scanf("%d", &opcao) != 1) {
            return 1;
        }
    } while (opcao < 1 || opcao > 3);

    printf("Sessão %d escolhida.\n", opcao);
    return 0;
}
