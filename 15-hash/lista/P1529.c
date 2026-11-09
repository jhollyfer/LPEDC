// Lista · Módulo 15 · Tabelas hash
// Exercício P1529 · ★★★ · As três palavras mais usadas
//
// Ache as 3 palavras mais frequentes do texto
//
//   o sol nasce e o mar brilha e o vento sopra e o barco sai do cais e o
//   sol se poe no mar
//
// em duas etapas: (1) conte com uma tabela de encadeamento (11 baldes,
// djb2 % 11); (2) monte um vetor de PONTEIROS para os nós (No **, com
// malloc do tamanho certo), ordene esse vetor com qsort (mais vezes
// primeiro; empate em ordem alfabética) e mostre os 3 primeiros. Libere o
// vetor e a tabela.
//
//   Saída esperada:
//   15 palavras distintas
//   1º o: 5
//   2º e: 4
//   3º mar: 2
//
// Dicas:
// 1. Faça conta() devolver 1 quando a palavra é nova: assim você já sabe o
//    tamanho do vetor.
// 2. O qsort entrega ponteiros para os elementos; como os elementos são
//    No *, a compara recebe No **: const No *x = *(const No *const *)a;
// 3. "mar" e "sol" empatam com 2: o desempate alfabético põe "mar" na frente.
// 4. Hash não guarda ordem; para ranquear, junte com ordenação (módulo 13).
//    O custo é O(n) para contar mais O(d log d) para ordenar as d distintas.
// 5. Resposta esperada: a saída acima, limpa no AddressSanitizer.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 11

typedef struct No {
    char palavra[16];
    int vezes;
    struct No *prox;
} No;

int main(void) {
    const char *texto = "o sol nasce e o mar brilha e o vento sopra e o barco sai do cais e o sol se poe no mar";
    (void)texto;

    return 0;
}
