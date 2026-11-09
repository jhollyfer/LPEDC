// Lista · Módulo 08 · Tipos compostos
// Exercício P0826 · ★★★ · Os conflitos da agenda
//
// A agenda de uma fisioterapeuta está fora de ordem e tem compromissos que se
// sobrepõem. Crie:
//
//   typedef enum { SEG, TER, QUA, QUI, SEX } Dia;
//   typedef struct { int h, m; } Horario;
//   typedef struct { char titulo[24]; Dia dia; Horario ini, fim; } Compromisso;
//
// Ordene com qsort por dia e, no mesmo dia, pelo horário de início. Depois
// mostre a agenda e, para cada par de compromissos SEGUIDOS (na ordem) do
// mesmo dia que se sobrepõem, uma linha de conflito com quantos minutos se
// cruzam. Encostar (um termina 10:00 e o outro começa 10:00) não é conflito:
//
//   Saída esperada:
//   seg 08:00-09:15 RPG Larissa
//   seg 09:00-10:00 Hidroterapia Seu Juca
//   seg 14:30-15:30 Avaliação Sr. Moacir
//   qua 09:00-10:00 Pilates Dona Cleide
//   qua 09:40-11:00 Reunião da clínica
//   qua 11:00-11:30 Retorno Paulinho
//   sex 18:00-20:00 Curso online
//   Conflito (seg): "RPG Larissa" e "Hidroterapia Seu Juca", 15 min
//   Conflito (qua): "Pilates Dona Cleide" e "Reunião da clínica", 20 min
//
// Dicas:
// 1. int minutos(Horario t) { return t.h * 60 + t.m; } simplifica tudo.
// 2. Na comparação: primeiro a->dia - b->dia; depois minutos(a->ini) -
//    minutos(b->ini).
// 3. Depois de ordenar, o compromisso i e o i + 1 do mesmo dia se cruzam se
//    minutos(v[i + 1].ini) < minutos(v[i].fim). Os minutos cruzados são
//    (o menor dos dois fins) - (início do segundo).
// 4. Resposta esperada: a saída acima (dois conflitos).
//
// Escreva sua resposta abaixo:

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
    (void) v; // apague esta linha quando escrever

    return 0;
}
