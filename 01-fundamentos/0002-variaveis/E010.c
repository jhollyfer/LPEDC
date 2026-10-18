// 0002 · Variáveis
// Exercício E010 · ★★☆
//
// O operador do placar eletrônico digitou invertido: o programa abaixo
// mostra Casa 1 x 3 Visitante, mas o certo é Casa 3 x 1 Visitante. Sem
// mudar as duas primeiras linhas da main, acrescente instruções que TROQUEM
// os valores de casa e visitante antes do printf.
//
//   Saída esperada:
//   Casa 3 x 1 Visitante
//
// Dicas:
// 1. Escrever casa = visitante; apaga o valor antigo de casa. Ele se perde.
// 2. Use uma terceira variável para guardar um valor enquanto troca, como
//    um copo vazio para trocar o suco de dois copos.
// 3. Resposta esperada: int aux = casa; casa = visitante; visitante = aux;
//    e a saída "Casa 3 x 1 Visitante".
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

int main(void) {
    int casa = 1;
    int visitante = 3;

    printf("Casa %d x %d Visitante\n", casa, visitante);
    return 0;
}
