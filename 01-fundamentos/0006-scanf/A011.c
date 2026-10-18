// A011 · Dois valores numa linha e a sobra que atrapalha

#include <stdio.h>

int main(void) {
    int quantidade = 0;
    double preco = 0.0;
    int parcelas = 1;

    // um scanf, dois valores: o %lf pula o espaço entre eles
    printf("Quantidade e preço (ex.: 3 4.99): ");
    int lidos = scanf("%d%lf", &quantidade, &preco);
    printf("Itens lidos: %d\n", lidos);

    printf("Parcelas: ");
    lidos = scanf("%d", &parcelas);
    printf("Itens lidos: %d\n", lidos);

    printf("%d unidade(s) de R$ %.2f em %d parcela(s)\n", quantidade, preco, parcelas);
    return 0;
}
// Exemplo de execução:
// Quantidade e preço (ex.: 3 4.99): 3 4.99
// Itens lidos: 2
// Parcelas: 2
// Itens lidos: 1
// 3 unidade(s) de R$ 4.99 em 2 parcela(s)
//
// Teste: printf '3 4.99\n2\n' | ~/LPEDC/rodar <este arquivo>
//
// Agora digite "3 4.99 reais" na primeira pergunta:
//   printf '3 4.99 reais\n2\n' | ~/LPEDC/rodar <este arquivo>
// O " reais" fica na fila. O %d das parcelas tropeça no 'r', devolve 0
// ("Itens lidos: 0") e parcelas continua com 1. O 2 nem chega a ser lido.
