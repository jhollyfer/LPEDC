// 0159 · Horspool
// Exercício E950 · ★☆☆
//
// No cinema, a tela de pedidos mostra "COMPRE PIPOCA DOCE". Escreva
// int horspool(const char *texto, const char *padrao), que procura a PRIMEIRA
// ocorrência, mostra cada alinhamento (a letra sob a última casa e o salto)
// e devolve quantos alinhamentos testou. Procure "PIPOCA":
//
//   Saída esperada:
//   i =  0: 'E' sob a última casa, salta 6
//   i =  6: 'C' sob a última casa, salta 1
//   i =  7: achou
//   3 alinhamentos
//
// Dicas:
// 1. Monte a tabela como no texto: tudo m, depois m - 1 - j para j de 0 até
//    m - 2.
// 2. Em cada alinhamento i, compare de j = m - 1 descendo enquanto as letras
//    batem. Se j ficou negativo, achou: mostre e devolva.
// 3. Senão, a letra sob a última casa é texto[i + m - 1], com ou sem acerto
//    antes. Some salto[dela] ao i.
// 4. Resposta esperada: a saída acima. O 'E' de COMPRE não está em PIPOCA:
//    o padrão pula inteiro.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define ALFABETO 256

int main(void) {

    return 0;
}
