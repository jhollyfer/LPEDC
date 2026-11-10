// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0914 · ★★☆ · O extrato com sujeira
//
// O app do banco exportou os valores do mês num arquivo texto, separados
// por espaço, mas alguns campos vieram corrompidos. Grave em
// /tmp/p0914_extrato.txt exatamente esta linha:
//
//   150 abc 32 -10 x9 20 7a
//
// Depois leia o arquivo palavra por palavra com fscanf("%31s") e use
// strtol para decidir se cada palavra é um inteiro válido (a palavra
// inteira tem que ser número). Some os válidos e mostre, na ordem, os que
// foram ignorados. Apague o arquivo no fim.
//
//   Saída esperada:
//   Válidos: 4 (soma 192)
//   Ignorados: abc x9 7a
//
// Dicas:
// 1. long v = strtol(palavra, &fim, 10): fim aponta para o primeiro
//    caractere que NÃO entrou no número.
// 2. A palavra é um número válido se fim != palavra (leu algum dígito) e
//    *fim == '\0' (não sobrou nada). O "7a" para no 'a': inválido.
// 3. Resposta esperada: válidos 150, 32, -10 e 20 (soma 192); ignorados
//    abc, x9 e 7a.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
