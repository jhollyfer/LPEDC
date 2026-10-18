// 0081 · Juntando tudo
// Exercício E481 · ★☆☆
//
// Monte a playlist do churrasco usando só playlist.h, nesta ordem:
//
//   Deixa a Vida Me Levar, Zeca Pagodinho, 233 s
//   Ai Se Eu Te Pego, Michel Teló, 166 s
//   País Tropical, Jorge Ben, 196 s
//   Velha Infância, Tribalistas, 251 s
//   Garota de Ipanema, Tom Jobim, 194 s
//
// Avance três músicas, volte uma, mostre a playlist, o total em min:seg e o
// que está tocando.
//
//   Saída esperada:
//     1. Deixa a Vida Me Levar - Zeca Pagodinho (3:53)
//     2. Ai Se Eu Te Pego - Michel Teló (2:46)
//   > 3. País Tropical - Jorge Ben (3:16)
//     4. Velha Infância - Tribalistas (4:11)
//     5. Garota de Ipanema - Tom Jobim (3:14)
//   5 músicas, 17:20
//   tocando agora: País Tropical - Jorge Ben
//
// Dicas:
// 1. playlist_cria, cinco playlist_adiciona, e confira se a criação não
//    devolveu NULL.
// 2. Para min:seg, use total / 60 e total % 60 com "%d:%02d".
// 3. playlist_atual devolve um const Musica *: acesse m->titulo e m->artista.
// 4. Resposta esperada: a saída acima. Libere a playlist no fim.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "playlist.h"

int main(void) {

    return 0;
}
