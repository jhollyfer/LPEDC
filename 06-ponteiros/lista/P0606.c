// Lista · Módulo 06 · Ponteiros
// Exercício P0606 · ★☆☆ · O pódio do campeonato
//
// Os pontos dos 8 times do campeonato amazonense, fora de ordem:
//
//   int pontos[8] = {21, 34, 18, 29, 34, 12, 25, 30};
//
// Ordene do MAIOR para o menor com qsort, escrevendo a função de comparação
// int decrescente(const void *a, const void *b). Mostre a tabela e o pódio:
//
//   Saída esperada:
//   Tabela: 34 34 30 29 25 21 18 12
//   1º: 34 pontos
//   2º: 34 pontos
//   3º: 30 pontos
//
// Dicas:
// 1. O qsort entrega dois const void *; converta: int x = *(const int *) a;
//    e o mesmo para b.
// 2. Para decrescente, devolva negativo quando x deve vir ANTES de y, ou
//    seja, quando x > y: return (x < y) - (x > y);
// 3. Evite return y - x: com números grandes a subtração estoura o int.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int pontos[8] = {21, 34, 18, 29, 34, 12, 25, 30};
    (void) pontos; // apague esta linha quando escrever

    return 0;
}
