// 0027 · Juntando tudo
// Exercício E160 · ★★☆
//
// O controle de estoque da cantina começa com 20 salgados. No menu, 1 vende
// (lê a quantidade), 2 repõe uma caixa de 10 e 0 sai, mostrando o estoque e o
// total vendido. Com as entradas 1, 5, 1, 3 e 0 (duas vendas e sair), o
// certo é:
//
//   Estoque: 12 | Vendidos: 8
//
// mas o programa abaixo mostra "Estoque: 32 | Vendidos: 0", e o rodar dá um
// aviso. O código, com DOIS erros, está logo abaixo. Teste com
//
//   printf '1\n5\n1\n3\n0\n' | ~/LPEDC/rodar 03-repeticoes/0027-juntando-tudo/E160.c
//
// leia o aviso, ache os dois erros e conserte.
//
// Dicas:
// 1. O aviso fala em "fall through": o que acontece no fim do case 1?
// 2. Em qual linha o total vendido volta para zero? Quantas vezes ela roda?
// 3. Resposta esperada: (1) falta break no fim do case 1, então toda venda
//    também repõe 10 (assunto 0018); (2) "vendidos = 0;" está dentro do laço
//    e zera o acumulador a cada volta, inclusive na volta do 0. Ele vai para
//    antes do do-while. Corrigido: "Estoque: 12 | Vendidos: 8".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int estoque = 20;
    int vendidos;
    int opcao, qtd;

    do {
        vendidos = 0;
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
