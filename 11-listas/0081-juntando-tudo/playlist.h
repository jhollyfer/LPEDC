// playlist.h · TAD playlist (lista duplamente encadeada de músicas)
//
// Quem usa a playlist não vê os nós: só as músicas (Musica) e as operações.
// A playlist sabe qual música está tocando, anda para a próxima e para a
// anterior, e no modo repetir dá a volta.

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stdbool.h>

typedef struct {
    char titulo[40];
    char artista[30];
    int segundos;
} Musica;

typedef struct playlist Playlist;

// cria uma playlist vazia (NULL se faltar memória)
Playlist *playlist_cria(void);

// devolve a memória da playlist e de todas as músicas
void playlist_libera(Playlist *p);

// põe a música no fim; a primeira música adicionada vira a que está tocando
bool playlist_adiciona(Playlist *p, const char *titulo, const char *artista, int segundos);

// tira a primeira música com esse título; se era a que tocava, passa a tocar
// a seguinte (ou a anterior, se era a última). false se não achou
bool playlist_remove(Playlist *p, const char *titulo);

// a música que está tocando (NULL se a playlist está vazia)
const Musica *playlist_atual(const Playlist *p);

// anda para a próxima / anterior e devolve a música. Na ponta: com repetir
// ligado dá a volta; desligado, fica onde está e devolve NULL
const Musica *playlist_proxima(Playlist *p);
const Musica *playlist_anterior(Playlist *p);

// liga ou desliga o modo repetir
void playlist_repetir(Playlist *p, bool ligado);

// quantas músicas e quantos segundos no total
int playlist_tamanho(const Playlist *p);
int playlist_duracao(const Playlist *p);

// mostra as músicas numeradas, com "> " na que está tocando
void playlist_imprime(const Playlist *p);

// chama acao(musica, extra) para cada música, da primeira à última
void playlist_para_cada(const Playlist *p, void (*acao)(const Musica *m, void *extra), void *extra);

// grava em arquivo texto, uma música por linha: titulo;artista;segundos
bool playlist_salva(const Playlist *p, const char *caminho);

// lê um arquivo gravado por playlist_salva (NULL se não conseguir abrir)
Playlist *playlist_carrega(const char *caminho);

#endif
