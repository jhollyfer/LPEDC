// A009 · Olá, LPEDC!

#include <stdio.h>

int main(void) {
    printf("Olá, LPEDC!\n");
    return 0;
}
// Saída:
// Olá, LPEDC!
//
// Experimente no terminal, dentro desta pasta:
//   gcc -E A009.c | wc -l     quantas linhas depois do pré-processador
//   gcc -S A009.c             gera A009.s (assembly): procure "puts"
//   gcc -c A009.c             gera A009.o (código objeto)
//   gcc A009.o -o ola         liga e gera o executável
//   ./ola
