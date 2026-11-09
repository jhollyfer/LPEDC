// Lista · Módulo 06 · Ponteiros
// Exercício P0620 · ★★☆ · Três ordens para o mesmo vetor
//
// O sorteio de uma rifa tirou estes números:
//
//   int sorteados[8] = {47, 12, 85, 30, 9, 66, 21, 58};
//
// Escreva void ordenar_e_mostrar(const char *nome, const int *orig, int n,
// int (*cmp)(const void *, const void *)), que copia orig para um vetor
// local, ordena a cópia com qsort usando a comparação recebida e mostra o
// resultado. Escreva três comparações:
// - crescente;
// - decrescente;
// - pares_primeiro: pares antes dos ímpares; dentro de cada grupo, crescente.
//
//   Saída esperada:
//   Crescente:       9 12 21 30 47 58 66 85
//   Decrescente:    85 66 58 47 30 21 12  9
//   Pares primeiro: 12 30 58 66  9 21 47 85
//
// Dicas:
// 1. A cópia evita que uma ordenação estrague a próxima: int v[8]; e um for.
// 2. Em pares_primeiro, calcule o "grupo" de cada um (x % 2: 0 para par e 1
//    para ímpar). Grupos diferentes: devolva a diferença dos grupos. Grupos
//    iguais: compare os valores.
// 3. O qsort não sabe nada de pares e ímpares: quem decide a ordem é só a
//    comparação que você passa.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int sorteados[8] = {47, 12, 85, 30, 9, 66, 21, 58};
    (void) sorteados; // apague esta linha quando escrever

    return 0;
}
