// Lista · Módulo 15 · Tabelas hash
// Exercício P1521 · ★★★ · O contador da feira que cresce sozinho
//
// Conte as frutas da lista da feira com uma tabela de encadeamento que
// CRESCE: ela começa com m = 3 baldes e, sempre que uma palavra NOVA faz
// n > m (α > 1), faz rehash para 2m + 1 baldes. No rehash, os nós são
// MOVIDOS para as correntes novas (nada de malloc nem de copiar palavras).
//
//   typedef struct No { char palavra[16]; int vezes; struct No *prox; } No;
//   typedef struct { No **baldes; int m, n; } Tabela;
//
// Use djb2 % m como balde e insira no início da corrente. A lista é:
// banana maca uva banana pera maca banana limao uva kiwi manga pera banana
// caju coco figo. No fim, mostre os baldes, as estatísticas e libere tudo
// (os nós e o vetor de baldes).
//
//   Saída esperada:
//   rehash depois de "pera": 3 -> 7 baldes
//   rehash depois de "caju": 7 -> 15 baldes
//   0: figo=1
//   1: maca=2 uva=2
//   2:
//   3:
//   4:
//   5:
//   6: coco=1
//   7: manga=1
//   8:
//   9: limao=1
//   10: banana=4
//   11:
//   12: kiwi=1 caju=1
//   13: pera=2
//   14:
//   16 palavras, 10 distintas, m = 15, alfa = 0.67, maior corrente = 2
//
// Dicas:
// 1. Crie os baldes com calloc(m, sizeof(No *)): todos começam NULL.
// 2. No rehash, percorra cada corrente guardando o prox ANTES de religar o
//    nó na corrente nova; depois, free no vetor velho.
// 3. Só palavra nova aumenta n; repetida só soma no contador.
// 4. Como m dobra, o custo dos rehashes somados é O(n): em média, O(1) por
//    palavra.
// 5. Resposta esperada: a saída acima, limpa no AddressSanitizer.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char palavra[16];
    int vezes;
    struct No *prox;
} No;

typedef struct {
    No **baldes;
    int m, n;
} Tabela;

int main(void) {
    const char *feira[] = {"banana", "maca", "uva", "banana", "pera", "maca", "banana", "limao",
                           "uva", "kiwi", "manga", "pera", "banana", "caju", "coco", "figo"};
    (void)feira;

    return 0;
}
