// A208 · A recepção digitando comandos

#include <stdio.h>
#include "cadastro.h"

// comandos, um por linha:
//   i MATRICULA NOME TREINOS   insere      b MATRICULA   busca
//   r MATRICULA                remove      l             lista
//   q                          sai
int main(void) {
    NoAluno *cad = NULL;
    char cmd;

    while (scanf(" %c", &cmd) == 1 && cmd != 'q') {
        Aluno a;
        int mat;
        if (cmd == 'i' && scanf("%d %19s %d", &a.matricula, a.nome, &a.treinos) == 3) {
            cad = cad_insere(cad, a);
            printf("ok: %s entrou\n", a.nome);
        } else if (cmd == 'b' && scanf("%d", &mat) == 1) {
            Aluno *achou = cad_busca(cad, mat);
            if (achou != NULL) {
                printf("%d: %s, %d treinos\n", mat, achou->nome, achou->treinos);
            } else {
                printf("%d: não encontrado\n", mat);
            }
        } else if (cmd == 'r' && scanf("%d", &mat) == 1) {
            cad = cad_remove(cad, mat);
            printf("ok: %d saiu\n", mat);
        } else if (cmd == 'l') {
            printf("%d alunos, altura %d:\n", cad_conta(cad), cad_altura(cad));
            cad_lista(cad);
        } else {
            printf("comando inválido\n");
        }
    }

    cad = cad_libera(cad);
    return 0;
}
// Teste: printf 'i 50 Ana 12\ni 30 Bruno 8\ni 70 Carla 15\nb 30\nr 50\nb 50\nl\nq\n' | ~/LPEDC/rodar 14-arvores/0104-juntando-tudo/A208.c
// Saída:
// ok: Ana entrou
// ok: Bruno entrou
// ok: Carla entrou
// 30: Bruno, 8 treinos
// ok: 50 saiu
// 50: não encontrado
// 2 alunos, altura 1:
//    30  Bruno     8 treinos
//    70  Carla    15 treinos
