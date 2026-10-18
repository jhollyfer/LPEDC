// A267 · Quantas salas? Todas as aulas, o mínimo de salas

#include <stdio.h>
#include <stdlib.h>

#define MAX_SALAS 10

typedef struct {
    const char *materia;
    int ini, fim; // [ini, fim), em horas
} Aula;

int por_inicio(const void *a, const void *b) {
    const Aula *x = a;
    const Aula *y = b;
    if (x->ini != y->ini) {
        return (x->ini > y->ini) - (x->ini < y->ini);
    }
    return (x->fim > y->fim) - (x->fim < y->fim); // empate: a que acaba antes
}

// outro problema de intervalos: agora TODAS as aulas acontecem, e a pergunta
// é quantas salas são precisas. Guloso: pela hora de INÍCIO, cada aula vai
// para uma sala que já ficou livre; se nenhuma ficou, abre uma sala nova.
int main(void) {
    Aula a[] = {
        {"Química", 10, 12}, {"Português", 8, 10}, {"Física", 9, 11},
        {"História", 11, 13}, {"Matemática", 8, 9}, {"Inglês", 12, 14},
        {"Biologia", 9, 12},  {"Redação", 13, 15},
    };
    int n = 8;
    int livre_em[MAX_SALAS]; // hora em que cada sala aberta fica livre
    int salas = 0;

    qsort(a, n, sizeof a[0], por_inicio);
    for (int i = 0; i < n; i++) {
        int s = 0;
        while (s < salas && livre_em[s] > a[i].ini) {
            s++;                // esta sala ainda está ocupada
        }
        if (s == salas) {
            salas++;            // nenhuma livre: abre a próxima
        }
        livre_em[s] = a[i].fim;
        printf("%2dh-%2dh  sala %d  %s\n", a[i].ini, a[i].fim, s + 1, a[i].materia);
    }
    printf("Salas necessárias: %d\n", salas);
    // 3 é o mínimo: às 9h, Português, Física e Biologia acontecem juntas.
    // O número de salas nunca passa do maior número de aulas simultâneas.
    return 0;
}
// Saída:
//  8h- 9h  sala 1  Matemática
//  8h-10h  sala 2  Português
//  9h-11h  sala 1  Física
//  9h-12h  sala 3  Biologia
// 10h-12h  sala 2  Química
// 11h-13h  sala 1  História
// 12h-14h  sala 2  Inglês
// 13h-15h  sala 1  Redação
// Salas necessárias: 3
