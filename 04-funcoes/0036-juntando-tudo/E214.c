// 0036 · Juntando tudo: o caixa da lanchonete
// Exercício E214 · ★★☆
//
// Tudo do módulo num programa só. Escreva as peças e o main:
//
//   #define DOBRO(x)            o dobro, à prova de precedência
//   int total = 0;              global
//   int proximo_id(void)        static id começando em 10; soma 1 e devolve
//   int soma_ate(int n)         recursiva: 0 + 1 + ... + n; soma 1 na global
//                               total a cada chamada
//   int altera(int total)       põe 99 no parâmetro e devolve
//
// O main mostra, nesta ordem: um id; a soma de mais dois ids; soma_ate(4); a
// global total; chama altera(total) sem guardar o retorno e mostra a global
// de novo; e por fim DOBRO(total + 1).
//
//   Saída esperada:
//   id: 11
//   dois ids somados: 25
//   soma_ate(4) = 10
//   chamadas: 5
//   depois de altera: 5
//   DOBRO(total + 1) = 12
//
// Dicas:
// 1. Para os dois ids, guarde cada um numa variável e some depois: a ordem
//    em que o C avalia os dois lados de um + não é garantida.
// 2. soma_ate(4) chama soma_ate 5 vezes (de 4 até 0). O parâmetro total de
//    altera esconde a global: o 99 vai para a cópia.
// 3. Resposta esperada: a saída acima. DOBRO(5 + 1) = ((5 + 1) * 2) = 12.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
