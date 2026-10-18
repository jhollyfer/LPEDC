// 0029 · Parâmetros e passagem por valor
// Exercício E169 · ★☆☆
//
// No app do cartão fidelidade, a promoção dobra os pontos. Escreva
// "int dobrar_pontos(int pontos)", que dobra o próprio parâmetro, mostra
// "dentro: <valor>" e devolve o valor dobrado. No main, comece com
// pontos = 150 e faça, nesta ordem:
//
//   1. chame dobrar_pontos(pontos) SEM guardar o retorno e mostre "main: ...";
//   2. chame de novo, agora com pontos = dobrar_pontos(pontos), e mostre
//      "main: ..." outra vez.
//
//   Saída esperada:
//   dentro: 300
//   main: 150
//   dentro: 300
//   main: 300
//
// Dicas:
// 1. Dentro da função: pontos = pontos * 2; printf(...); return pontos;
// 2. O "pontos" da função e o "pontos" do main são duas variáveis: mudar uma
//    não muda a outra.
// 3. Resposta esperada: a saída acima. Na primeira chamada, o 300 volta pelo
//    return e é jogado fora; só na segunda ele chega ao main.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
