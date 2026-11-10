// Lista · Módulo 08 · Tipos compostos
// Exercício P0801 · ★☆☆ · A distância entre as paradas
//
// No mapa da linha de ônibus, cada parada tem coordenadas (x, y) em km.
// Crie typedef struct { double x, y; } Ponto; e escreva:
//
//   double distancia(Ponto a, Ponto b);   // sqrt((bx - ax)² + (by - ay)²)
//   Ponto meio(Ponto a, Ponto b);         // o ponto médio, para o abrigo
//
// Para as paradas abaixo, mostre a distância de cada trecho, o total do
// percurso e o ponto médio entre a primeira e a última:
//
//   Ponto paradas[4] = {{0.0, 0.0}, {3.0, 4.0}, {6.0, 8.0}, {6.0, 11.5}};
//
//   Saída esperada:
//   Parada 1 -> 2: 5.00 km
//   Parada 2 -> 3: 5.00 km
//   Parada 3 -> 4: 3.50 km
//   Total: 13.50 km
//   Abrigo no meio: (3.00, 5.75)
//
// Dicas:
// 1. Uma struct pode ser parâmetro e retorno, como um int: a função recebe
//    uma cópia e devolve uma struct nova.
// 2. No meio: return (Ponto) {(a.x + b.x) / 2, (a.y + b.y) / 2}; (literal
//    composto) ou declare um Ponto m e preencha os campos.
// 3. sqrt está no math.h.
// 4. Resposta esperada: a saída acima (13.50 km no total).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <math.h>

int main(void) {

    return 0;
}
