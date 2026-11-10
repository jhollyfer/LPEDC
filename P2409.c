// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2409 · ★☆☆ · A batida que se repete
//
// O professor de percussão escreve as batidas como palavras. O PERÍODO
// de uma palavra é o tamanho do menor pedaço que, repetido (o último pode
// ficar pela metade), forma a palavra inteira. A tabela π dá o período de
// graça: periodo = m - pi[m - 1]. Escreva o programa do zero (pode copiar
// a calcula_pi do assunto 0158): mostre o período e o pedaço de cada
// batida e, quando o pedaço cabe um número inteiro de vezes (e mais de
// uma), quantas.
//
//   Batidas: "tumtatumtatumta", "tumtumpa", "abcabcab", "xxxxxx", "samba"
//
//   Saída esperada:
//   tumtatumtatumta  período  5 ("tumta"), repete 3 vezes inteiras
//   tumtumpa         período  8 ("tumtumpa")
//   abcabcab         período  3 ("abc")
//   xxxxxx           período  1 ("x"), repete 6 vezes inteiras
//   samba            período  5 ("samba")
//
// Dicas:
// 1. A maior borda b tem a propriedade: p[j] == p[j + m - b] para todo j.
//    Por isso a palavra "anda" de m - b em m - b.
// 2. "abcabcab" tem período 3 mas não é "abc" repetido inteiro: 8 não é
//    múltiplo de 3.
// 3. Resposta esperada: tumtatumtatumta tem período 5 e repete 3 vezes;
//    xxxxxx, período 1, 6 vezes.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
