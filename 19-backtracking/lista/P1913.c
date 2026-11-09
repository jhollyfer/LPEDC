// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1913 · ★★☆ · ARARA em pedaços palíndromos
//
// Um palíndromo se lê igual dos dois lados (ARA, ARARA, A). De quantos
// jeitos dá para cortar a palavra ARARA em pedaços que sejam todos
// palíndromos? Escreva do zero um backtracking: a partir da posição ini,
// tente cada pedaço s[ini..fim]; se ele for palíndromo, guarde e continue
// a partir de fim + 1. Mostre cada corte com os pedaços separados por | e
// o total.
//
//   Saída esperada:
//   A|R|A|R|A
//   A|R|ARA
//   A|RAR|A
//   ARA|R|A
//   ARARA
//   Total: 5 jeitos
//
// Dicas:
// 1. eh_pal(s, i, j) compara s[i] com s[j], s[i + 1] com s[j - 1]... até
//    os índices se cruzarem.
// 2. Guarde onde cada pedaço termina num vetor fimp[] e o número de pedaços
//    em np. Quando ini == tamanho, mostre os pedaços.
// 3. Resposta esperada: 6 jeitos, do A|R|A|R|A até o ARARA inteiro.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
