// 0027 · Juntando tudo
// Exercício E160 · ★★☆
//
// Resposta: (1) faltava break no fim do case 1, então toda venda também
// repunha 10; (2) "vendidos = 0;" estava dentro do laço e zerava o acumulador
// a cada volta, inclusive na volta do 0. Agora ele começa em 0 antes do
// do-while.

#include <stdio.h>

int main(void) {
    int estoque = 20;
    int vendidos = 0;
    int opcao, qtd;

    do {
        printf("1 Vender | 2 Repor | 0 Sair: ");
        if (scanf("%d", &opcao) != 1) {
            opcao = 0;
        }
        switch (opcao) {
        case 1:
            printf("Quantos? ");
            if (scanf("%d", &qtd) == 1 && qtd > 0 && qtd <= estoque) {
                estoque -= qtd;
                vendidos += qtd;
            } else {
                printf("Venda recusada.\n");
            }
            break;
        case 2:
            estoque += 10;
            printf("Repôs 10.\n");
            break;
        case 0:
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    printf("Estoque: %d | Vendidos: %d\n", estoque, vendidos);
    return 0;
}
