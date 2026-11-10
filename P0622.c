// Lista · Módulo 06 · Ponteiros
// Exercício P0622 · ★★★ · O meu qsort de qualquer tipo
//
// Escreva a sua versão genérica de ordenação, com a mesma assinatura do
// qsort:
//
//   void ordenar(void *base, size_t n, size_t tam,
//                int (*cmp)(const void *, const void *));
//
// Use o método de inserção: para cada i de 1 a n - 1, enquanto o elemento
// j - 1 for maior que o j (segundo cmp), troque os dois e recue j. Como você
// não sabe o tipo, trabalhe com bytes: o elemento i começa em
// (unsigned char *) base + i * tam, e a troca é byte a byte (escreva void
// troca_bytes(void *a, void *b, size_t tam)). Teste com os três vetores:
//
//   int idades[6] = {34, 19, 52, 27, 19, 40};
//   double precos[5] = {9.90, 2.49, 15.00, 4.75, 2.10};
//   char cidades[5][12] = {"Tefe", "Coari", "Borba", "Manaus", "Autazes"};
//
//   Saída esperada:
//   Idades: 19 19 27 34 40 52
//   Preços: 2.10 2.49 4.75 9.90 15.00
//   Cidades: Autazes Borba Coari Manaus Tefe
//
// Dicas:
// 1. Aritmética com void * não é C padrão: converta para unsigned char * e
//    ande tam bytes por elemento.
// 2. troca_bytes: um for de 0 a tam - 1 trocando pa[k] com pb[k], onde pa e
//    pb são unsigned char *.
// 3. As comparações são as de sempre: para int, *(const int *) a; para a
//    matriz de char, o endereço da linha já é a string (strcmp direto).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    int idades[6] = {34, 19, 52, 27, 19, 40};
    double precos[5] = {9.90, 2.49, 15.00, 4.75, 2.10};
    char cidades[5][12] = {"Tefe", "Coari", "Borba", "Manaus", "Autazes"};
    (void) idades, (void) precos, (void) cidades; // apague esta linha quando escrever

    return 0;
}
