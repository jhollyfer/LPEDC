// 0019 · Juntando tudo: a conta de luz
// Exercício E113 · ★★★
//
// Resposta, os quatro erros:
// 1. if (idade = 0) atribuía 0 à idade (e nunca era verdade): o certo é ==.
// 2. O ";" depois de if (idade < 12 || idade >= 60) fazia todo mundo pagar meia.
// 3. Faltava break no case 'T': a terça caía no sábado e somava R$ 5.
// 4. O else ficava com o if (dia == 'S'); com chaves no if de dentro, ele
//    volta para o if (idade < 18).

#include <stdio.h>

int main(void) {
    int idade;
    char dia;
    double preco = 30.0;

    printf("Idade e dia (ex.: 30 T): ");
    if (scanf("%d %c", &idade, &dia) != 2) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (idade == 0) {
        printf("Idade inválida.\n");
        return 1;
    }

    if (idade < 12 || idade >= 60) {
        preco = preco / 2;
    }

    switch (dia) {
    case 'T':
        preco = preco - 10;
        break;
    case 'S':
        preco = preco + 5;
        break;
    }
    printf("Ingresso: R$ %.2f\n", preco);

    if (idade < 18) {
        if (dia == 'S') {
            printf("Aviso: a sessão da meia-noite é só para maiores.\n");
        }
    } else {
        printf("Boa sessão!\n");
    }
    return 0;
}
