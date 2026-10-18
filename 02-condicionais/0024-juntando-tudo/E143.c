// 0024 · Juntando tudo: a conta de luz
// Exercício E143 · ★★★
//
// O cinema cobra R$ 30. Menores de 12 e pessoas de 60 ou mais pagam meia.
// Na terça ('T'), o ingresso tem R$ 10 de desconto; no sábado ('S'), custa
// R$ 5 a mais; nos outros dias, preço normal. Idade 0 é inválida. E, por
// fim, quem é menor de 18 recebe um aviso no sábado; quem tem 18 ou mais
// recebe "Boa sessão!".
//
// Este programa tem QUATRO erros, todos pegadinhas do módulo. Rode, leia os
// avisos do compilador, ache e conserte os quatro.
//
// Dicas:
// 1. Os quatro: um sinal de igual, um ponto e vírgula, uma palavra que falta
//    no switch e um else que mudou de dono.
// 2. Conserte um de cada vez e rode de novo. Teste com 30 T, 8 S e 65 Q.
// 3. Resposta esperada: if (idade = 0) → ==; o ";" depois do if da meia;
//    falta break no case 'T'; o else é do if (dia == 'S'), precisa de
//    chaves no if de dentro. Consertado: 30 T → R$ 20.00 e "Boa sessão!";
//    8 S → R$ 20.00 e o aviso; 65 Q → R$ 15.00 e "Boa sessão!";
//    0 → "Idade inválida.".
//
// Escreva sua resposta abaixo (conserte o código):

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

    if (idade = 0) {
        printf("Idade inválida.\n");
        return 1;
    }

    if (idade < 12 || idade >= 60);
    {
        preco = preco / 2;
    }

    switch (dia) {
    case 'T':
        preco = preco - 10;
    case 'S':
        preco = preco + 5;
        break;
    }
    printf("Ingresso: R$ %.2f\n", preco);

    if (idade < 18)
        if (dia == 'S')
            printf("Aviso: a sessão da meia-noite é só para maiores.\n");
    else
        printf("Boa sessão!\n");
    return 0;
}
