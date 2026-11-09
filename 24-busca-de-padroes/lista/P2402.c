// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2402 · ★☆☆ · Quantos kk tem a risada
//
// A mensagem no grupo foi "kkkkk ri muito kkk". Quantos "kk" tem nela?
// Depende: contando sobrepostas (como a busca de padrões conta) ou não
// (como quem risca o texto e não reaproveita letra). Escreva do zero
// int conta(texto, padrao, pulo_inteiro), que usa strstr num laço: depois
// de cada achado, avança 1 letra (pulo_inteiro = 0) ou o tamanho do padrão
// (pulo_inteiro = 1). Conte "kk" e "kkk" dos dois jeitos.
//
//   Saída esperada:
//   "kk" com sobreposição: 6
//   "kk" sem sobreposição: 3
//   "kkk" com sobreposição: 4
//   "kkk" sem sobreposição: 2
//
// Dicas:
// 1. strstr(p, padrao) devolve o ponteiro para a primeira ocorrência a
//    partir de p, ou NULL. Continue a partir de p + 1 ou p + strlen(padrao).
// 2. Num bloco de r letras k, há r - m + 1 ocorrências sobrepostas e
//    r / m sem sobrepor.
// 3. Resposta esperada: "kk" dá 6 e 3; "kkk" dá 4 e 2.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
