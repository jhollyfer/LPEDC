// 0114 · Grafos
// Exercício E684 · ★★★
//
// Você está montando a "sugestão de amizade" de uma rede social. A amizade é
// recíproca (grafo não dirigido) e as pessoas são Ana (0), Bia (1), Caio (2),
// Duda (3), Edu (4) e Fabi (5). As amizades:
//
//   Ana-Bia, Ana-Caio, Bia-Caio, Bia-Duda, Caio-Duda, Caio-Edu, Duda-Fabi,
//   Edu-Fabi
//
// Para cada par que AINDA NÃO é amigo, conte os amigos em comum. Mostre os
// pares com 2 ou mais amigos em comum, cada par uma vez só:
//
//   Saída esperada:
//   Ana e Duda: 2 amigos em comum
//   Caio e Fabi: 2 amigos em comum
//   Duda e Edu: 2 amigos em comum
//
// Dicas:
// 1. Amigo em comum de i e j é um k com adj[i][k] e adj[k][j] valendo 1.
//    Isso é um caminho de comprimento 2 entre i e j.
// 2. Três laços: i, j > i (pares sem repetir) e k. Pule os pares que já são
//    amigos (adj[i][j] == 1).
// 3. Curiosidade: a contagem é exatamente a casa [i][j] do produto da matriz
//    por ela mesma (adj x adj).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
