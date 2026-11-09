// Lista · Módulo 04 · Funções e modularização
// Exercício P0426 · ★★★ · De quantas formas dar o troco
//
// O caixa tem moedas de 1, 5, 10, 25 e 50 centavos e de R$ 1. De quantas
// formas diferentes dá para formar R$ 1,00 (100 centavos)? Escreva "int
// moeda(int i)", que devolve o valor da moeda i (0 é a de 100, 5 é a de 1), e a
// função recursiva "int formas(int valor, int i)", que conta as formas usando
// só as moedas de i em diante: ou você usa a moeda i (e continua podendo usar),
// ou desiste dela de vez. Conte também as chamadas:
//
//   Saída esperada:
//   R$ 0,10: 4 forma(s), 43 chamada(s)
//   R$ 0,25: 13 forma(s), 251 chamada(s)
//   R$ 1,00: 293 forma(s), 15501 chamada(s)
//
// Dicas:
// 1. Casos base: valor == 0 é 1 forma (deu certo); valor < 0, ou acabaram as
//    moedas (i == 6), é 0.
// 2. Caso recursivo: formas(valor - moeda(i), i) + formas(valor, i + 1).
// 3. Zere o contador global antes de cada valor.
// 4. Resposta esperada: 4, 13 e 293 formas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
