// Lista · Módulo 08 · Tipos compostos
// Exercício P0826 · ★★★ · Os conflitos da agenda

#include <stdio.h>
#include <stdlib.h>

typedef enum { SEG, TER, QUA, QUI, SEX } Dia;

typedef struct {
    int h, m;
} Horario;

typedef struct {
    char titulo[24];
    Dia dia;
    Horario ini, fim;
} Compromisso;

int minutos(Horario t) {
    return t.h * 60 + t.m;
}

int compara(const void *pa, const void *pb) {
    const Compromisso *a = pa, *b = pb;
    if (a->dia != b->dia) {
        return (int) a->dia - (int) b->dia;
    }
    return minutos(a->ini) - minutos(b->ini);
}

int main(void) {
    Compromisso v[7] = {
        {"Pilates Dona Cleide", QUA, {9, 0}, {10, 0}},
        {"Avaliação Sr. Moacir", SEG, {14, 30}, {15, 30}},
        {"RPG Larissa", SEG, {8, 0}, {9, 15}},
        {"Reunião da clínica", QUA, {9, 40}, {11, 0}},
        {"Hidroterapia Seu Juca", SEG, {9, 0}, {10, 0}},
        {"Retorno Paulinho", QUA, {11, 0}, {11, 30}},
        {"Curso online", SEX, {18, 0}, {20, 0}},
    };
    const char *dias[5] = {"seg", "ter", "qua", "qui", "sex"};
    int n = 7;

    qsort(v, n, sizeof v[0], compara);
    for (int i = 0; i < n; i++) {
        printf("%s %02d:%02d-%02d:%02d %s\n", dias[v[i].dia], v[i].ini.h, v[i].ini.m,
               v[i].fim.h, v[i].fim.m, v[i].titulo);
    }
    for (int i = 0; i + 1 < n; i++) {
        const Compromisso *a = &v[i], *b = &v[i + 1];
        if (a->dia == b->dia && minutos(b->ini) < minutos(a->fim)) {
            int fim = minutos(a->fim) < minutos(b->fim) ? minutos(a->fim) : minutos(b->fim);
            printf("Conflito (%s): \"%s\" e \"%s\", %d min\n", dias[a->dia], a->titulo,
                   b->titulo, fim - minutos(b->ini));
        }
    }
    return 0;
}
