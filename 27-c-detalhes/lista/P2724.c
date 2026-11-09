// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2724 · ★★★ · Figuras lidas de um arquivo
//
// Grave no arquivo p2724_figuras.txt as linhas abaixo (uma letra e as
// medidas) e depois leia o arquivo com fscanf. Cada figura vai para uma
// struct com etiqueta: typedef enum { CIRCULO, RETANGULO, TRIANGULO } Forma;
// e uma union com as medidas de cada forma. Calcule a área de cada uma com
// um switch (triângulo pelos três lados, com a fórmula de Heron) e a soma.
// Apague o arquivo no fim.
//
//   C 2
//   R 3 4
//   T 3 4 5
//
//   Saída esperada:
//   círculo de raio 2.0: 12.57
//   retângulo 3.0 x 4.0: 12.00
//   triângulo 3.0, 4.0, 5.0: 6.00
//   área total: 30.57
//
// Dicas:
// 1. Leia a letra com fscanf(f, " %c", &letra) e, conforme ela, leia 1, 2
//    ou 3 números.
// 2. Heron: s = (a + b + c) / 2 e área = sqrt(s(s - a)(s - b)(s - c)).
// 3. Use acos(-1.0) para o pi; o rodar já liga a libm (-lm).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

int main(void) {

    return 0;
}
