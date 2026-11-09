// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2923 · ★★★ · O carteiro e as duas esquinas ímpares
//
// O carteiro precisa passar por toda rua do bairro e voltar ao correio
// (esquina 0). Se o grafo tem exatamente duas esquinas ímpares, ele terá de
// repetir ruas: o mínimo a mais é a distância mais curta entre essas duas
// esquinas (problema do carteiro chinês). Ruas com o comprimento em metros:
//
//   0-1 100, 1-2 80, 2-3 120, 3-0 90, 2-4 60, 4-5 70, 5-2 50, 1-4 200
//
// Escreva o programa: some os comprimentos, ache as esquinas ímpares, rode
// Floyd-Warshall (0155) e mostre a distância extra e o total percorrido.
//
//   Saída esperada:
//   Ruas: 770 m
//   Esquinas ímpares: 1 e 4
//   Extra: 140 m
//   Total: 910 m
//
// Dicas:
// 1. Use INF = 1000000 para "sem rua" e d[i][i] = 0 antes do Floyd.
// 2. Com 0 esquinas ímpares o extra seria 0 (circuito euleriano). Aqui são 2.
// 3. Resposta esperada: a saída acima. Repare que o carteiro não repete a rua
//    1-4 (200 m): ele refaz 1-2-4, que soma 140 m.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
