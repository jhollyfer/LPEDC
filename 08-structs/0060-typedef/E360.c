// 0060 · Typedef
// Exercício E360 · ★★★
//
// A sonda Mars Climate Orbiter se perdeu em 1999 porque um programa mandava
// valores em libra-força e outro esperava newtons. Para o computador, eram
// todos números. Vamos fazer o compilador trabalhar a seu favor.
//
// a) Crie Celsius e Fahrenheit como structs de um campo só:
//    typedef struct { double graus; } Celsius; (e o mesmo para Fahrenheit).
//    Escreva Fahrenheit para_fahrenheit(Celsius c) e
//    Celsius para_celsius(Fahrenheit f), e converta 100 °C e 98.6 °F.
// b) Escreva no main a linha Celsius errado = febre; (febre é Fahrenheit).
//    O que acontece? E se os dois fossem typedef double?
//
//   Saída esperada (sem a linha errada):
//   100.0 °C = 212.0 °F
//   98.6 °F = 37.0 °C
//
// Dicas:
// 1. F = C * 9 / 5 + 32 e C = (F - 32) * 5 / 9.
// 2. Para criar o valor: Celsius agua = {100.0}; acesse com agua.graus.
// 3. Resposta esperada: a saída acima. Em (b), não compila (o gcc diz
//    "invalid initializer"): duas structs diferentes nunca se misturam. Com
//    typedef double, compilaria e o erro passaria calado.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
