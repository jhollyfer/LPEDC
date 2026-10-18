// 0009 · Atribuição, ++ e --
// Exercício E053 · ★★★
//
// Resposta: em senha = senha++, a variável recebe duas escritas na mesma
// expressão (a do = e a do ++), sem ordem definida. No printf, fila++ e fila
// são avaliados numa ordem que o padrão não fixa: o segundo argumento pode
// ver 7 ou 8. As duas linhas são comportamento indefinido, e o gcc avisa
// "operation on ... may be undefined" [-Wsequence-point]. Separando em
// passos, a intenção fica clara e o resultado é o mesmo em qualquer
// compilador.

#include <stdio.h>

int main(void) {
    int senha = 1234;
    senha++;
    printf("senha %d\n", senha);

    int fila = 7;
    printf("fila: atendendo %d, próximo %d\n", fila, fila + 1);
    fila++;
    return 0;
}
