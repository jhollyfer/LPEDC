// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2913 · ★★☆ · Todos os caminhos hamiltonianos de s a t
//
// Um fiscal precisa visitar as seis obras de uma avenida (0 a 5), cada uma
// uma vez, saindo do escritório na obra 0 e terminando em casa, perto da
// obra 5. As vias entre as obras são:
//
//   0-1, 0-2, 1-2, 1-3, 2-3, 2-4, 3-4, 3-5, 4-5
//
// Escreva o backtracking que lista TODOS os caminhos hamiltonianos de 0 a
// 5 (vizinhos em ordem de índice) e conta as chamadas da recursão.
//
//   Saída esperada:
//   Caminho 1: 0 1 2 3 4 5
//   Caminho 2: 0 1 2 4 3 5
//   Caminho 3: 0 1 3 2 4 5
//   Caminho 4: 0 2 1 3 4 5
//   Total: 4 caminhos, 26 chamadas
//
// Dicas:
// 1. Fixe rota[0] = 0. Quando a rota tiver os 6 vértices, aceite só se o
//    último for 5. Pode podar antes: não entre no 5 enquanto faltarem outros.
// 2. Conte uma chamada no começo da função, antes de qualquer teste.
// 3. Resposta esperada: a saída acima (com a poda do 5).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
