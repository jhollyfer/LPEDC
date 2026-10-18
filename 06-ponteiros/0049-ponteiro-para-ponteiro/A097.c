// A097 · A lista de chamada termina em NULL

#include <stdio.h>

// alunos é um const char **: aponta para a primeira casa de um vetor de
// ponteiros. A lista termina numa casa NULL, então nem precisa do tamanho
int conta_com_letra(const char **alunos, char letra) {
    int total = 0;
    for (const char **p = alunos; *p != NULL; p++) { // *p: um nome
        if (**p == letra) {                          // **p: a 1ª letra dele
            total++;
        }
    }
    return total;
}

int main(void) {
    const char *turma[] = {"Bruna", "Caio", "Beto", "Davi", "Bia", NULL};

    for (const char **p = turma; *p != NULL; p++) {
        printf("%-6s começa com %c\n", *p, **p);
    }
    printf("Com B: %d alunos\n", conta_com_letra(turma, 'B'));
    printf("Com Z: %d alunos\n", conta_com_letra(turma, 'Z'));

    // caso de borda: lista vazia, só a marca do fim
    const char *vazia[] = {NULL};
    printf("Lista vazia, com B: %d\n", conta_com_letra(vazia, 'B'));

    // p + 1 anda uma casa do vetor: 8 bytes, o tamanho de um ponteiro
    printf("sizeof turma[0] = %zu\n", sizeof turma[0]);
    return 0;
}
// Saída:
// Bruna  começa com B
// Caio   começa com C
// Beto   começa com B
// Davi   começa com D
// Bia    começa com B
// Com B: 3 alunos
// Com Z: 0 alunos
// Lista vazia, com B: 0
// sizeof turma[0] = 8
