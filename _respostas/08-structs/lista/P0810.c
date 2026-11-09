// Lista · Módulo 08 · Tipos compostos
// Exercício P0810 · ★☆☆ · A configuração com campos nomeados

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int volume, graves, agudos, balanco;
    bool loudness;
    char fonte[12];
} Config;

void mostrar(const char *nome, const Config *c) {
    printf("%-8s vol %2d, graves %d, agudos %d, balanço %2d, loudness %s, fonte \"%s\"\n",
           nome, c->volume, c->graves, c->agudos, c->balanco,
           c->loudness ? "sim" : "não", c->fonte);
}

int main(void) {
    Config padrao = {0};
    Config estrada = {.volume = 22, .graves = 3, .loudness = true, .fonte = "Radio FM"};
    Config show = {.fonte = "Pendrive", .agudos = 4, .graves = 5, .volume = 30,
                   .balanco = -2};

    mostrar("padrao", &padrao);
    mostrar("estrada", &estrada);
    mostrar("show", &show);
    return 0;
}
