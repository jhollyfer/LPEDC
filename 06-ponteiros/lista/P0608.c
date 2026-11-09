// Lista · Módulo 06 · Ponteiros
// Exercício P0608 · ★☆☆ · Conserte os ponteiros soltos
//
// O programa da bilheteria tem DOIS erros de propósito, e o gcc avisa dos
// dois. Um ponteiro é usado sem apontar para nada, e uma função devolve o
// endereço de uma variável que deixa de existir quando ela termina. Rode, leia
// os avisos (warning) e conserte sem mudar o que o programa mostra:
//
//   Saída esperada:
//   Público do dia: 229
//   Sessão mais cheia: 142
//
// Dicas:
// 1. Um ponteiro declarado e não inicializado guarda lixo: *p = ... escreve
//    num endereço qualquer. Faça p apontar para uma variável de verdade.
// 2. A variável local de uma função mora no frame dela, que some no return.
//    Devolva o VALOR (int), não o endereço.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int *mais_cheia(int a, int b) {
    int maior = a > b ? a : b;
    return &maior;
}

int main(void) {
    int sessao_tarde = 87;
    int sessao_noite = 142;
    int *p;

    *p = sessao_tarde + sessao_noite;
    printf("Público do dia: %d\n", *p);
    printf("Sessão mais cheia: %d\n", *mais_cheia(sessao_tarde, sessao_noite));
    return 0;
}
