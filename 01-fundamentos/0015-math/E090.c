// 0015 · math.h
// Exercício E090 · ★★★
//
// Do alto de uma laje de 1.5 m, você joga uma bola para cima a 20 m/s.
// Desprezando o ar, a altura depois de t segundos é
// h(t) = -5t² + 20t + 1.5. Calcule:
//
// a) o instante em que a bola chega ao chão (h = 0), com a fórmula de
//    Bhaskara: t = (-b - raiz(delta)) / (2a), com delta = b² - 4ac;
// b) o instante da altura máxima, t = -b / (2a), e a altura nesse instante.
//
//   Saída esperada:
//   Delta: 430.00
//   Chega ao chão em 4.07 s
//   Altura máxima: 21.50 m, em 2.00 s
//
// Dicas:
// 1. a = -5, b = 20, c = 1.5, todos double.
// 2. Com a negativo, das duas raízes a que interessa (t positivo) é a do
//    "- raiz(delta)". A outra dá um tempo negativo, antes do lançamento.
// 3. Resposta esperada: delta = 400 + 30 = 430; t = (-20 - 20.736) / -10 =
//    4.07 s; altura máxima em t = 2 s, h(2) = -20 + 40 + 1.5 = 21.50 m.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <math.h>

int main(void) {

    return 0;
}
