// Lista · Módulo 15 · Tabelas hash
// Exercício P1514 · ★★☆ · A tabela que cresce sozinha
//
// Uma tabela com endereçamento aberto (sondagem linear, h(k) = k % m) começa
// com m = 5 e não deixa o fator de carga passar de 0,5. Antes de cada
// inserção, se 2 · (n + 1) > m, ela faz REHASH: cria uma tabela com m novo =
// o primeiro primo >= 2 · m, reinsere todas as chaves (com o m novo!) e
// libera a antiga. Use
//
//   typedef struct { int *t; int m, n; } Tabela;
//
// e malloc para o vetor. Insira 12, 7, 33, 21, 18, 40, 9, mostrando a tabela
// depois de cada inserção (e avisando cada rehash).
//
//   Saída esperada:
//   +12
//     m =  5: _ _ 12 _ _
//   +7
//     m =  5: _ _ 12 7 _
//   rehash: 5 -> 11
//   +33
//     m = 11: 33 12 _ _ _ _ _ 7 _ _ _
//   +21
//     m = 11: 33 12 _ _ _ _ _ 7 _ _ 21
//   +18
//     m = 11: 33 12 _ _ _ _ _ 7 18 _ 21
//   rehash: 11 -> 23
//   +40
//     m = 23: _ _ _ _ _ _ _ 7 _ _ 33 _ 12 _ _ _ _ 40 18 _ _ 21 _
//   +9
//     m = 23: _ _ _ _ _ _ _ 7 _ 9 33 _ 12 _ _ _ _ 40 18 _ _ 21 _
//   n = 7, alfa = 0.30
//
// Dicas:
// 1. Não dá para copiar o vetor velho para o começo do novo: com m diferente,
//    cada chave tem outra casa (o 12 sai da 2 e vai para a 1, e depois para a
//    12). Reinsira uma por uma.
// 2. Escreva eh_primo, proximo_primo, cria(m) e coloca(t, m, k).
// 3. Um rehash custa O(n), mas como m dobra, ele acontece cada vez mais raro:
//    o custo médio por inserção continua O(1).
// 4. Resposta esperada: a saída acima, limpa no AddressSanitizer.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define VAZIO -1

typedef struct {
    int *t;
    int m, n;
} Tabela;

int main(void) {

    return 0;
}
