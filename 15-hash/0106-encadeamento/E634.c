// 0106 · Encadeamento
// Exercício E634 · ★★☆
//
// Um colega sugeriu usar o tamanho do nome como função hash ("é rápido!").
// Compare as duas funções numa tabela com 8 baldes e estas 10 cidades:
//
//   recife natal manaus belem santos maceio osasco palmas macapa cuiaba
//
// Para cada função (tamanho: strlen(s); polinômio: h = h * 31 + byte, em
// unsigned), mostre quantas cidades caem em cada balde, o tamanho da maior
// corrente e a média de comparações para achar uma cidade que está na
// tabela. Use um ponteiro para função para não escrever a análise duas vezes.
//
//   Saída esperada:
//   tamanho  : 0 0 0 0 0 2 8 0 | maior: 8 | média: 3.9
//   polinomio: 2 2 1 1 3 1 0 0 | maior: 3 | média: 1.5
//
// Dicas:
// 1. Não precisa montar as listas: para medir, basta contar quantas chaves
//    caem em cada balde.
// 2. Numa corrente de k nós, achar o 1º custa 1 comparação, o 2º custa 2...
//    o total da corrente é 1 + 2 + ... + k = k * (k + 1) / 2. Some todas e
//    divida por 10.
// 3. Resposta esperada: a saída acima. Com o tamanho, só existem nomes de 5
//    e 6 letras, então 8 cidades amontoam num balde: a tabela vira quase uma
//    lista.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
