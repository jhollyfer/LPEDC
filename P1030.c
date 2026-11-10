// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1030 · ★★★ · Moda e mediana sem ordenar nada
//
// As notas do simulado são inteiras de 0 a 10. Como só existem 11 notas
// possíveis, dá para guardar um HISTOGRAMA (quantas vezes cada nota saiu)
// em vez da lista de notas. Escreva o TAD Histograma, num arquivo só
// ("histograma.h", "histograma.c" e cliente):
//
//   Histograma *hist_cria(void);
//   bool hist_adiciona(Histograma *h, int nota);   // false se fora de 0..10
//   int hist_quantidade(const Histograma *h);
//   int hist_moda(const Histograma *h, int *vezes); // a menor, no empate
//   int hist_mediana(const Histograma *h);  // o elemento (n + 1) / 2 na ordem
//   double hist_media(const Histograma *h);
//   void hist_libera(Histograma *h);
//
// adiciona custa O(1); moda e mediana percorrem as 11 contagens, custo que
// NÃO depende de quantas notas existem. Teste com 7, 8, 5, 10, 7, 6, 9, 7,
// 4, 8, 7; depois acrescente doze notas 10 e mostre de novo moda e mediana.
//
//   Saída esperada:
//   Notas: 11
//   Moda: 7 (4 vezes)
//   Mediana: 7
//   Média: 7.09
//   Depois de mais doze notas 10: moda 10 (13 vezes), mediana 10
//
// Dicas:
// 1. struct histograma { int cont[11]; int n; long soma; };
// 2. Mediana: ande pelas notas de 0 a 10 somando as contagens; a mediana é
//    a primeira nota em que a soma acumulada chega a (n + 1) / 2.
// 3. Ordenar n notas custaria pelo menos O(n log n) com comparações; aqui o
//    truque é que o universo de valores é pequeno e fixo.
// 4. Resposta esperada: a saída acima (com 23 notas, a 12ª da fila é 10).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
