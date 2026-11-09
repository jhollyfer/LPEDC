// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2416 · ★★☆ · O maior palíndromo escondido
//
// Dentro de "bananas" está o palíndromo "anana". Escreva do zero
// maior(s), que acha o MAIOR trecho palíndromo da palavra pela expansão
// ao redor do centro: cada palíndromo tem um centro, que é uma letra
// (tamanho ímpar) ou o espaço entre duas letras (tamanho par). Para cada
// um dos 2n - 1 centros, abra as pontas enquanto forem iguais. Em empate,
// fica o primeiro achado.
//
//   Saída esperada:
//   bananas          "anana" (posição 1, 5 letra(s))
//   paralelepipedo   "epipe" (posição 7, 5 letra(s))
//   arrozzorra       "arrozzorra" (posição 0, 10 letra(s))
//   abcd             "a" (posição 0, 1 letra(s))
//   osso             "osso" (posição 0, 4 letra(s))
//   sopapos          "sopapos" (posição 0, 7 letra(s))
//
// Dicas:
// 1. expande(s, n, e, d) abre e-- e d++ enquanto s[e] == s[d] e devolve
//    d - e - 1. Chame com (c, c) e com (c, c + 1).
// 2. Um palíndromo de tamanho t centrado em c começa em c - t / 2 (ímpar)
//    ou c - t / 2 + 1 (par). Mostre com printf("%-16s ...") e "%.*s".
// 3. Resposta esperada: paralelepipedo esconde "epipe"; arrozzorra,
//    osso e sopapos são palíndromos inteiros.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *palavras[] = {"bananas", "paralelepipedo", "arrozzorra", "abcd", "osso", "sopapos"};
    printf("%s\n", palavras[0]);
    return 0;
}
