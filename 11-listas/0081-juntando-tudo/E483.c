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
// Dicas:
// 1. A assinatura é fixa: void acha_longa(const Musica *m, void *extra).
// 2. Dentro dela: const Musica **maior = extra; e compare com *maior (que
//    começa NULL).
// 3. Para o artista: typedef struct { const char *nome; int quantas; int
//    segundos; } Filtro; e no callback, Filtro *f = extra; e strcmp.
// 4. Resposta esperada: a saída acima (182 + 189 = 371 s = 6:11).
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
