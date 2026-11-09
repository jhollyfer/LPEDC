// Lista · Módulo 08 · Tipos compostos
// Exercício P0818 · ★★☆ · Os números complexos
//
// Crie typedef struct { double re, im; } Complexo; e escreva soma,
// multiplica (as duas devolvem um Complexo novo), double modulo(Complexo z)
// e void mostrar(const char *rotulo, Complexo z), que mostra no formato
// "a + bi" ou "a - bi". Com z = 1 + 2i e w = 3 - i, mostre z + w, z * w e
// |z * w|. Depois mostre as potências de i, de i¹ a i⁸, multiplicando uma de
// cada vez:
//
//   Saída esperada:
//   z + w = 4 + 1i
//   z * w = 5 + 5i
//   |z * w| = 7.0711
//   i^1 = 0 + 1i
//   i^2 = -1 + 0i
//   i^3 = 0 - 1i
//   i^4 = 1 + 0i
//   i^5 = 0 + 1i
//   i^6 = -1 + 0i
//   i^7 = 0 - 1i
//   i^8 = 1 + 0i
//
// Dicas:
// 1. (a + bi)(c + di) = (ac - bd) + (ad + bc)i.
// 2. |a + bi| = sqrt(a² + b²).
// 3. No mostrar, se z.im < 0, mostre " - " e o valor absoluto (fabs).
// 4. As potências de i se repetem a cada 4: i, -1, -i, 1.
// 5. Na conta de i³, a parte real sai como -0 (o double tem zero com sinal:
//    -1 * 0 = -0) e o printf mostra "-0". Teste z.re == 0 (que vale para os
//    dois zeros) e mostre 0.
// 6. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <math.h>

int main(void) {

    return 0;
}
