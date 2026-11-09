// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1908 · ★☆☆ · O fogo que pula na diagonal
//
// No mapa de uma área de reserva, # é aceiro (faixa sem mato, o fogo não
// passa) e . é mato. O fogo começa na casa (0, 0) e, com o vento, pula
// também na DIAGONAL: são 8 vizinhos, não 4. Escreva do zero o flood fill
// recursivo queima(l, c), que troca por * cada casa de mato alcançada.
// Mostre o mapa depois do fogo e quantas casas queimaram.
//
//   Saída esperada:
//   **#****
//   **#*#**
//   ##*##**
//   ###**#*
//   ..#*#**
//   Queimadas: 20 casas
//
// Dicas:
// 1. Saia logo se (l, c) está fora do mapa ou não é '.'. Senão marque '*',
//    conte e chame para os 8 vizinhos.
// 2. Os 8 vizinhos cabem em dois laços: for dl de -1 a 1, for dc de -1 a 1,
//    pulando dl == 0 && dc == 0.
// 3. Resposta esperada: 20 casas queimadas. Com só 4 vizinhos, o fogo
//    pararia nas 4 do canto. As 2 casas de mato do canto de baixo à
//    esquerda escapam mesmo com o vento.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
