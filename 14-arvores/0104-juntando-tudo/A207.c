// A207 · Trocar a matrícula não é editar o campo

#include <stdio.h>
#include "cadastro.h"

void confere(NoAluno *cad, int matricula) {
    Aluno *a = cad_busca(cad, matricula);
    printf("  busca %d: %s\n", matricula, a != NULL ? a->nome : "não achou");
}

int main(void) {
    Aluno turma[] = {
        {45, "Lia", 10}, {25, "Rui", 6}, {65, "Teo", 14}, {15, "Ivo", 3}, {35, "Mel", 8},
    };
    NoAluno *cad = NULL;
    for (int i = 0; i < 5; i++) {
        cad = cad_insere(cad, turma[i]);
    }

    // Ivo ganhou a matrícula 90. Jeito ERRADO: mudar o campo pelo ponteiro
    Aluno *ivo = cad_busca(cad, 15);
    ivo->matricula = 90;
    printf("Editando o campo:\n");
    cad_lista(cad);   // o 90 aparece no começo: está no lugar do 15
    confere(cad, 90); // a busca vai para a direita e nunca o encontra
    ivo->matricula = 15; // desfaz, para seguir com a árvore certa

    // jeito CERTO: copia o aluno, remove pela chave velha, insere com a nova
    Aluno copia = *cad_busca(cad, 15); // copia antes: o remove dá free no nó
    cad = cad_remove(cad, 15);
    copia.matricula = 90;
    cad = cad_insere(cad, copia);
    printf("Removendo e inserindo:\n");
    cad_lista(cad);
    confere(cad, 90);
    confere(cad, 15);

    cad = cad_libera(cad);
    return 0;
}
// Saída:
// Editando o campo:
//    90  Ivo       3 treinos
//    25  Rui       6 treinos
//    35  Mel       8 treinos
//    45  Lia      10 treinos
//    65  Teo      14 treinos
//   busca 90: não achou
// Removendo e inserindo:
//    25  Rui       6 treinos
//    35  Mel       8 treinos
//    45  Lia      10 treinos
//    65  Teo      14 treinos
//    90  Ivo       3 treinos
//   busca 90: Ivo
//   busca 15: não achou
