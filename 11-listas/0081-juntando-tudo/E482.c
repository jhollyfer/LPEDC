// 0081 · Juntando tudo
// Exercício E482 · ★☆☆
//
// Sem rodar, preveja as nove linhas deste programa. Releia em playlist.h o
// que acontece nas pontas e quando a música removida é a que está tocando.
// Depois rode e confira.
//
// O código está no arquivo, logo abaixo deste enunciado.
//
// Dicas:
// 1. Com repetir desligado, andar além da ponta devolve NULL e não sai do
//    lugar.
// 2. Removendo a música que toca, passa a tocar a seguinte; se ela era a
//    última, a anterior.
// 3. Com uma música só e repetir ligado, a próxima da última é... ela mesma.
// 4. Resposta esperada:
//    Um
//    (nada)
//    Tres
//    (nada)
//    Um
//    Tres
//    Dois
//    1 música, 200 s
//    Dois
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>
#include "playlist.h"

static void mostra(const Musica *m) {
    printf("%s\n", m != NULL ? m->titulo : "(nada)");
}

int main(void) {
    Playlist *p = playlist_cria();
    if (p == NULL) return 1;
    playlist_adiciona(p, "Um", "Banda A", 100);
    playlist_adiciona(p, "Dois", "Banda B", 200);
    playlist_adiciona(p, "Tres", "Banda C", 300);

    mostra(playlist_atual(p));
    mostra(playlist_anterior(p));
    playlist_proxima(p);
    mostra(playlist_proxima(p));
    mostra(playlist_proxima(p));

    playlist_repetir(p, true);
    mostra(playlist_proxima(p));
    mostra(playlist_anterior(p));

    playlist_remove(p, "Tres");
    mostra(playlist_atual(p));
    playlist_remove(p, "Um");
    printf("%d música, %d s\n", playlist_tamanho(p), playlist_duracao(p));
    mostra(playlist_proxima(p));

    playlist_libera(p);
    return 0;
}
