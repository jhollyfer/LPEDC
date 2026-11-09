// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1022 · ★★★ · Turmas como conjuntos ordenados
//
// O cursinho quer cruzar as matrículas das turmas de Python e de C. Escreva
// um TAD Conjunto, num arquivo só ("conjunto.h", "conjunto.c" e cliente),
// guardado como um vetor ORDENADO e sem repetidos (o invariante), que cresce
// com realloc dobrando a capacidade:
//
//   Conjunto *conj_cria(void);
//   bool conj_insere(Conjunto *c, int x);  // mantém a ordem; ignora repetido
//   Conjunto *conj_uniao(const Conjunto *a, const Conjunto *b, long *comp);
//   Conjunto *conj_intersecao(const Conjunto *a, const Conjunto *b, long *comp);
//   void conj_imprime(const Conjunto *c);
//   void conj_libera(Conjunto *c);
//
// União e interseção devem ser feitas por INTERCALAÇÃO, andando com um
// índice em cada vetor: O(n + m). Conte 1 comparação por volta do laço em
// que os dois vetores ainda têm itens. No cliente, compare com a interseção
// ingênua (para cada item de a, percorre b inteiro: O(n · m)), que pode ser
// escrita usando um vetor comum com os mesmos números.
//
// Python: 25, 3, 12, 8, 20 (inseridos nesta ordem). C: 30, 8, 5, 20, 8.
//
//   Saída esperada:
//   Python: 3 8 12 20 25
//   C: 5 8 20 30
//   União: 3 5 8 12 20 25 30 (6 comparações)
//   Interseção: 8 20 (6 comparações)
//   Interseção ingênua: 8 20 (20 comparações)
//
// Dicas:
// 1. Na intercalação: se a[i] < b[j], o a[i] só está em a (avança i); se
//    a[i] > b[j], avança j; se são iguais, está nos dois (avança os dois).
// 2. Na união, quando um vetor acaba, copie o resto do outro sem comparar.
// 3. Como os dois já estão em ordem, os resultados saem em ordem, e o
//    invariante do TAD vale para eles sem ordenar nada.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
