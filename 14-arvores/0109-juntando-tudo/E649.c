// 0109 · Juntando tudo
// Exercício E649 · ★☆☆
//
// A academia dá um brinde para quem treinou pelo menos 10 vezes no mês.
// Complete conta_brinde(r), que percorre o cadastro e conta esses alunos, e
// mostra_brinde(r), que imprime o nome deles em ordem de matrícula.
//
//   Saída esperada:
//   Ganham brinde: Eva Ana Carla Gil
//   Total: 4
//
// Dicas:
// 1. Os dois são percursos da árvore inteira: o critério (treinos) não é a
//    chave, então não dá para podar nada.
// 2. mostra_brinde é uma em ordem com um if antes do printf.
// 3. Resposta esperada: Eva (20), Ana (12), Carla (15) e Gil (11). Total: 4.
//
// Escreva sua resposta abaixo (complete as duas funções):

#include <stdio.h>
#include "cadastro.h"

int conta_brinde(const NoAluno *r) {
    (void)r; // apague esta linha
    return 0;
}

void mostra_brinde(const NoAluno *r) {
    (void)r; // apague esta linha
}

int main(void) {
    Aluno turma[] = {
        {50, "Ana", 12}, {30, "Bruno", 8}, {70, "Carla", 15}, {20, "Davi", 4},
        {40, "Eva", 20}, {60, "Fabio", 9}, {80, "Gil", 11},
    };
    NoAluno *cad = NULL;
    for (int i = 0; i < 7; i++) {
        cad = cad_insere(cad, turma[i]);
    }

    printf("Ganham brinde:");
    mostra_brinde(cad);
    printf("\nTotal: %d\n", conta_brinde(cad));

    cad = cad_libera(cad);
    return 0;
}
