// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2401 · ★☆☆ · O último Pix do extrato
//
// O extrato do dia veio numa linha só:
//
//   "pix 50; boleto 120; pix 35; ted 900; pix 18; tarifa 12"
//
// Você quer o ÚLTIMO lançamento de cada tipo. Escreva do zero
// int ultima(const char *texto, const char *padrao, int *alinhamentos): a
// força bruta andando de trás para a frente (i de n - m até 0), que devolve
// a posição da última ocorrência (ou -1) e conta os alinhamentos testados.
// Procure "pix", "ted" e "doc" e mostre as 10 letras a partir da posição
// achada com "%.10s".
//
//   Saída esperada:
//   pix: última em 37 -> "pix 18; ta" (15 alinhamentos)
//   ted: última em 28 -> "ted 900; p" (24 alinhamentos)
//   doc: não aparece (52 alinhamentos)
//
// Dicas:
// 1. Andando de trás para a frente, a primeira ocorrência que aparece é a
//    última do texto: pode devolver na hora.
// 2. Quando o padrão não aparece, são testados todos os n - m + 1
//    alinhamentos.
// 3. Resposta esperada: "pix" na posição 37 depois de 15 alinhamentos;
//    "doc" não aparece (52 alinhamentos, o texto tem 54 letras).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
