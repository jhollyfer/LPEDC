// playlist.c · TAD playlist sobre lista duplamente encadeada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

typedef struct faixa {
    Musica musica;
    struct faixa *ant;
    struct faixa *prox;
} Faixa;

struct playlist {
    Faixa *inicio;
    Faixa *fim;
    Faixa *atual;   // a que está tocando
    int tamanho;
    bool repetir;
};

Playlist *playlist_cria(void) {
    Playlist *p = malloc(sizeof(Playlist));
    if (p == NULL) return NULL;
    p->inicio = p->fim = p->atual = NULL;
    p->tamanho = 0;
    p->repetir = false;
    return p;
}

void playlist_libera(Playlist *p) {
    if (p == NULL) return;
    Faixa *f = p->inicio;
    while (f != NULL) {
        Faixa *seguinte = f->prox;
        free(f);
        f = seguinte;
    }
    free(p);
}

bool playlist_adiciona(Playlist *p, const char *titulo, const char *artista, int segundos) {
    Faixa *nova = malloc(sizeof(Faixa));
    if (nova == NULL) return false;
    // snprintf corta o texto se não couber: nunca estoura o vetor
    snprintf(nova->musica.titulo, sizeof nova->musica.titulo, "%s", titulo);
    snprintf(nova->musica.artista, sizeof nova->musica.artista, "%s", artista);
    nova->musica.segundos = segundos;
    nova->prox = NULL;
    nova->ant = p->fim;
    if (p->fim != NULL) p->fim->prox = nova;
    else p->inicio = nova;
    p->fim = nova;
    if (p->atual == NULL) p->atual = nova;
    p->tamanho++;
    return true;
}

bool playlist_remove(Playlist *p, const char *titulo) {
    Faixa *f = p->inicio;
    while (f != NULL && strcmp(f->musica.titulo, titulo) != 0) f = f->prox;
    if (f == NULL) return false;
    if (p->atual == f) p->atual = (f->prox != NULL) ? f->prox : f->ant;
    if (f->ant == NULL) p->inicio = f->prox;
    else f->ant->prox = f->prox;
    if (f->prox == NULL) p->fim = f->ant;
    else f->prox->ant = f->ant;
    free(f);
    p->tamanho--;
    return true;
}

const Musica *playlist_atual(const Playlist *p) {
    return p->atual != NULL ? &p->atual->musica : NULL;
}

const Musica *playlist_proxima(Playlist *p) {
    if (p->atual == NULL) return NULL;
    if (p->atual->prox != NULL) p->atual = p->atual->prox;
    else if (p->repetir) p->atual = p->inicio;  // dá a volta
    else return NULL;                           // fim da playlist
    return &p->atual->musica;
}

const Musica *playlist_anterior(Playlist *p) {
    if (p->atual == NULL) return NULL;
    if (p->atual->ant != NULL) p->atual = p->atual->ant;
    else if (p->repetir) p->atual = p->fim;
    else return NULL;
    return &p->atual->musica;
}

void playlist_repetir(Playlist *p, bool ligado) {
    p->repetir = ligado;
}

int playlist_tamanho(const Playlist *p) {
    return p->tamanho;
}

int playlist_duracao(const Playlist *p) {
    int total = 0;
    for (const Faixa *f = p->inicio; f != NULL; f = f->prox) total += f->musica.segundos;
    return total;
}

void playlist_imprime(const Playlist *p) {
    int n = 1;
    for (const Faixa *f = p->inicio; f != NULL; f = f->prox) {
        printf("%s%d. %s - %s (%d:%02d)\n", f == p->atual ? "> " : "  ", n++,
               f->musica.titulo, f->musica.artista,
               f->musica.segundos / 60, f->musica.segundos % 60);
    }
}

void playlist_para_cada(const Playlist *p, void (*acao)(const Musica *m, void *extra), void *extra) {
    for (const Faixa *f = p->inicio; f != NULL; f = f->prox) acao(&f->musica, extra);
}

bool playlist_salva(const Playlist *p, const char *caminho) {
    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) return false;
    for (const Faixa *f = p->inicio; f != NULL; f = f->prox) {
        fprintf(arq, "%s;%s;%d\n", f->musica.titulo, f->musica.artista, f->musica.segundos);
    }
    fclose(arq);
    return true;
}

Playlist *playlist_carrega(const char *caminho) {
    FILE *arq = fopen(caminho, "r");
    if (arq == NULL) return NULL;
    Playlist *p = playlist_cria();
    if (p == NULL) {
        fclose(arq);
        return NULL;
    }
    char linha[100], titulo[40], artista[30];
    int segundos;
    while (fgets(linha, sizeof linha, arq) != NULL) {
        // %39[^;] lê até 39 caracteres que não sejam ';'
        if (sscanf(linha, "%39[^;];%29[^;];%d", titulo, artista, &segundos) == 3) {
            playlist_adiciona(p, titulo, artista, segundos);
        }
    }
    fclose(arq);
    return p;
}
