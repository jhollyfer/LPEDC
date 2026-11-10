// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2620 · ★★☆ · A tabela de distâncias pela metade
//
// A tabela de distâncias entre n bairros é simétrica (d[i][j] = d[j][i]) e
// tem zeros na diagonal. Em vez de uma matriz n × n de double, guarde só os
// pares i < j num vetor compacto de n(n-1)/2 posições, com o índice
// pos(i, j) = i * n - i * (i + 1) / 2 + (j - i - 1). Preencha com
// d(i, j) = 2.5 * (i + j) + 1 (só para ter valores), mostre os bytes da
// matriz e do vetor para n = 100 e confira que os valores lidos pela
// função distancia(i, j) (que aceita i > j e i == j) batem com a fórmula
// em todos os pares:
//
//   Saída esperada:
//   matriz: 80000 bytes
//   vetor:  39600 bytes
//   pares conferidos: 10000, erros: 0
//   distancia(7, 3) = 26.0
//
// Dicas:
// 1. distancia(i, j): se i == j devolve 0; se i > j troca os dois; senão lê
//    v[pos(i, j)].
// 2. Matriz: n² × 8 = 80000 bytes. Vetor: n(n-1)/2 × 8 = 39600 bytes. Mesma
//    classe Θ(n²), menos da metade da memória.
// 3. Para conferir, conte quantos pares (i, j), com i e j de 0 a 99, dão
//    diferença maior que 1e-9.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

    return 0;
}
