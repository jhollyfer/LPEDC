// Lista · Módulo 08 · Tipos compostos
// Exercício P0812 · ★★☆ · Ordenar os ponteiros, não as fichas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int idade;
    char historico[200];
} Ficha;

Ficha *nova_ficha(const char *nome, int idade, const char *hist) {
    if (strlen(nome) >= 20 || strlen(hist) >= 200) {
        return NULL; // não cabe
    }
    Ficha *f = malloc(sizeof *f);
    if (f == NULL) {
        return NULL;
    }
    strcpy(f->nome, nome);
    f->idade = idade;
    strcpy(f->historico, hist);
    return f;
}

int mais_velho_primeiro(const void *pa, const void *pb) {
    const Ficha *a = *(Ficha * const *) pa; // o elemento é um ponteiro
    const Ficha *b = *(Ficha * const *) pb;
    return b->idade - a->idade;
}

int main(void) {
    const char *nomes[4] = {"Raimundo", "Jéssica", "Benedito", "Karina"};
    int idades[4] = {58, 31, 74, 45};
    const char *hist[4] = {"hipertensão", "asma", "diabetes tipo 2", "nenhum"};
    Ficha *fichas[4];

    for (int i = 0; i < 4; i++) {
        fichas[i] = nova_ficha(nomes[i], idades[i], hist[i]);
        if (fichas[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(fichas[j]);
            }
            return 1;
        }
    }
    Ficha *primeira = fichas[0];

    qsort(fichas, 4, sizeof fichas[0], mais_velho_primeiro);
    for (int i = 0; i < 4; i++) {
        printf("%d. %d anos: %s (%s)\n", i + 1, fichas[i]->idade, fichas[i]->nome,
               fichas[i]->historico);
    }
    int pos = 0;
    while (fichas[pos] != primeira) {
        pos++;
    }
    printf("A ficha do Raimundo continua no mesmo endereço, agora na posição %d\n", pos + 1);
    printf("Bytes por troca: %zu (ponteiro) contra %zu (ficha)\n",
           sizeof fichas[0], sizeof *fichas[0]);
    for (int i = 0; i < 4; i++) {
        free(fichas[i]);
    }
    return 0;
}
