// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2419 · ★★☆ · Anagramas escondidos
//
// Na frase "a roma de amor e o ramo de mora", quantos trechos de 4 letras
// são anagramas de "amor" (as mesmas letras, em qualquer ordem)? Escreva
// do zero com uma janela deslizante de CONTAGENS: quer[c] conta as letras
// do padrão e janela[c] as da janela atual; a cada passo, sai uma letra
// pela esquerda e entra outra pela direita. Mostre a posição e o trecho de
// cada anagrama e o total.
//
//   Saída esperada:
//    2: roma
//   10: amor
//   19: ramo
//   27: mora
//   Anagramas de "amor": 4
//
// Dicas:
// 1. Use vetores de 256 posições indexados por (unsigned char). Monte a
//    primeira janela com as m primeiras letras.
// 2. Comparar os dois vetores custa 256 por janela, mas não depende de m:
//    a busca toda é O(256 n), e não O(n m · m).
// 3. Resposta esperada: roma, amor, ramo e mora, nas posições 2, 10, 19 e
//    27.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
