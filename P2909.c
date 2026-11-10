// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2909 · ★☆☆ · O verificador do caixeiro viajante
//
// A versão de decisão do caixeiro viajante é: "existe uma volta por todas
// as cidades com custo no máximo L?". Cinco cidades (0 a 4) têm a matriz
// de distâncias (km) do main abaixo; -1 quer dizer "sem estrada". Escreva
// bool aceita(const int r[], int n, int limite), que confere o certificado
// (é uma permutação das 5 cidades, toda estrada existe, a volta incluída)
// e compara o custo com o limite. Teste:
//
//   0 1 2 3 4 com L = 90      0 2 4 1 3 com L = 100
//   0 1 3 2 4 com L = 100     0 1 3 2 4 com L = 90
//
//   Saída esperada:
//   aceito (custo 87)
//   rejeitado (sem estrada 4-1)
//   aceito (custo 94)
//   rejeitado (custo 94 > 90)
//
// Dicas:
// 1. Use a matriz
//    {{0, 12, 30, -1, 25}, {12, 0, 18, 20, -1}, {30, 18, 0, 15, 22},
//    {-1, 20, 15, 0, 17}, {25, -1, 22, 17, 0}}.
// 2. Mostre "aceito (custo C)", "rejeitado (custo C > L)", "rejeitado (sem
//    estrada X-Y)" ou "rejeitado (repete cidade)".
// 3. Resposta esperada: a saída acima. O mesmo certificado pode ser aceito
//    para um L e rejeitado para outro.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
