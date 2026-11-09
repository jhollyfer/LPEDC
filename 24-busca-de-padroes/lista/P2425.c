// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2425 · ★★★ · Todos os palíndromos de uma palavra
//
// Escreva todos(s), que acha TODOS os trechos palíndromos de uma palavra
// pela expansão ao redor dos 2n - 1 centros: conte cada ocorrência (cada
// passo de expansão que deu certo é um palíndromo) e guarde os
// DIFERENTES numa tabela char achados[128][32], sem repetir. No fim,
// ordene com qsort (menores primeiro; mesmo tamanho, ordem do strcmp) e
// mostre. Teste com abacaba, arara, aaaa e tucano.
//
//   Saída esperada:
//   abacaba: 12 ocorrências, 7 diferentes: a b c aba aca bacab abacaba
//   arara: 9 ocorrências, 5 diferentes: a r ara rar arara
//   aaaa: 10 ocorrências, 4 diferentes: a aa aaa aaaa
//   tucano: 6 ocorrências, 6 diferentes: a c n o t u
//
// Dicas:
// 1. Um só laço cobre os dois tipos de centro: para c de 0 a 2n - 2,
//    e = c / 2 e d = e + c % 2.
// 2. O qsort ordena as linhas da matriz: qsort(achados, n, 32, compara),
//    e o compara recebe ponteiros para o começo de cada linha.
// 3. Resposta esperada: abacaba tem 12 ocorrências e 7 diferentes (a b c
//    aba aca bacab abacaba); tucano, só as 6 letras.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
