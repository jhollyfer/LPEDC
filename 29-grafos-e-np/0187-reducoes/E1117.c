// 0187 · Reduções
// Exercício E1117 · ★☆☆
//
// Num torneio de várzea todos devem jogar contra todos. Cinco times (Azul,
// Verde, Rubro, Preto, Branco; 0 a 4) já fizeram estes jogos:
//
//   Azul x Verde, Azul x Rubro, Verde x Preto, Rubro x Preto,
//   Preto x Branco, Azul x Branco
//
// Os jogos que faltam são exatamente as arestas do grafo complemento.
// Escreva void complemento(int g[V][V], int c[V][V]) e use-a para mostrar
// os jogos que faltam (pares a < b) e a conta de conferência.
//
//   Saída esperada:
//   Jogos que faltam:
//     Azul x Preto
//     Verde x Rubro
//     Verde x Branco
//     Rubro x Branco
//   6 jogos feitos + 4 faltando = 10
//
// Dicas:
// 1. c[a][b] = 1 quando a != b e g[a][b] == 0. Sem o a != b, todo time
//    "jogaria contra si mesmo" no complemento.
// 2. O grafo completo com V vértices tem V(V-1)/2 arestas: G e o
//    complemento dividem essas arestas entre si.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
