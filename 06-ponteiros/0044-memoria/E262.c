// 0044 · Memória e endereços
// Exercício E262 · ★★☆
//
// Este programa da pizzaria tenta mostrar o endereço da variável pedidos de
// três jeitos, e os três estão errados DE PROPÓSITO. Rode com o rodar, leia
// os avisos do compilador e responda: o que cada linha mostra e por que está
// errada? Depois conserte para as três linhas mostrarem o endereço certo.
//
// Dicas:
// 1. Leia o aviso inteiro: ele diz o tipo que o formato espera e o tipo que
//    recebeu.
// 2. Um endereço tem 8 bytes; %d e %x leem um int de 4.
// 3. Resposta esperada: %d mostra um número cortado (às vezes negativo); %x
//    mostra só a metade de baixo do endereço; %p sem cast funciona na
//    prática, mas o padrão pede void *. As três viram
//    printf("Endereço: %p\n", (void *)&pedidos);
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int pedidos = 15;

    printf("Endereço: %d\n", &pedidos);
    printf("Endereço: %x\n", &pedidos);
    printf("Endereço: %p\n", &pedidos);
    return 0;
}
