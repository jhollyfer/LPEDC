// 0069 · Union
// Exercício E412 · ★★☆
//
// Um app de reforma calcula a área de peças de formatos diferentes. Crie uma
// union etiquetada:
//
//   typedef enum { CIRCULO, RETANGULO, TRIANGULO } TipoForma;
//   typedef struct {
//       TipoForma tipo;
//       union {
//           double raio;
//           struct { double largura, altura; } ret;
//           struct { double base, altura; } tri;
//       } medida;
//   } Forma;
//
// Escreva double area(const Forma *f) com um switch no tipo e some as
// áreas de: um círculo de raio 2, um retângulo 3 x 4 e um triângulo de base 6
// e altura 5.
//
//   Saída esperada:
//   círculo: 12.57 m2
//   retângulo: 12.00 m2
//   triângulo: 15.00 m2
//   Total: 39.57 m2
//
// Dicas:
// 1. O -std=c17 não define M_PI: use #define PI 3.14159265358979.
// 2. Inicialize com nome de campo: {CIRCULO, .medida.raio = 2}.
// 3. Triângulo: base * altura / 2.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
