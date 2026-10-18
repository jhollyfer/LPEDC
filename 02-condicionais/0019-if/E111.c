// 0019 · if
// Exercício E111 · ★★☆
//
// O cinema quer barrar menores de 18 anos neste filme. Mas o programa
// abaixo mostra "Entrada proibida" até para quem tem 25 anos. Rode com 25,
// leia o aviso do compilador (ele existe de propósito), explique o erro e
// conserte.
//
// Dicas:
// 1. Olhe com atenção o fim da linha do if.
// 2. O que fica sendo o corpo do if? E o bloco entre chaves, de quem é?
// 3. Resposta esperada: o ";" depois de if (idade < 18) é uma instrução
//    vazia e vira o corpo do if; o bloco embaixo roda sempre. Tirando o ";",
//    25 mostra só "Bom filme!" e 15 mostra as duas mensagens.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int idade;
    printf("Idade: ");
    if (scanf("%d", &idade) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (idade < 18);
    {
        printf("Entrada proibida para menores.\n");
    }
    printf("Bom filme!\n");
    return 0;
}
