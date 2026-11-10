// 0081 · Juntando tudo
// Exercício E483 · ★★☆
//
// A playlist não deixa você ver os nós, mas playlist_para_cada chama uma
// função SUA para cada música, levando junto um void *extra com o que você
// quiser (assuntos 0050 e 0051). Com a playlist do main, escreva duas
// funções de callback:
//
//   acha_longa: descobre a música mais longa (extra aponta para um
//               const Musica * que guarda a maior até agora)
//   soma_artista: conta quantas músicas e quantos segundos tem um artista
//               (extra aponta para uma struct com o nome, a contagem e a soma)
//
//   Saída esperada:
//   mais longa: Tempo Perdido (5:02)
//   Jorge Ben: 2 músicas, 6:11
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include "playlist.h"

int main(void) {
    Playlist *p = playlist_cria();
    if (p == NULL) return 1;
    playlist_adiciona(p, "Aquarela", "Toquinho", 252);
    playlist_adiciona(p, "Mas Que Nada", "Jorge Ben", 182);
    playlist_adiciona(p, "Evidências", "Chitãozinho e Xororó", 279);
    playlist_adiciona(p, "Tempo Perdido", "Legião Urbana", 302);
    playlist_adiciona(p, "Taj Mahal", "Jorge Ben", 189);

    // chame playlist_para_cada com os seus callbacks e mostre os resultados

    playlist_libera(p);
    return 0;
}
