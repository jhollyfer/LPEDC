// A001 · O aviso da padaria

// Aviso do painel da padaria
#include <stdio.h>

int main(void) {
    printf("Padaria Pão Quente\n");
    printf("Pão francês saindo às 17h\n");
    printf("R$ 0,90 a unidade\n");
    return 0; // 0 = terminou bem
}
// Saída:
// Padaria Pão Quente
// Pão francês saindo às 17h
// R$ 0,90 a unidade
//
// Experimente no terminal, dentro desta pasta:
//   gcc -E A001.c | wc -l     quantas linhas depois do pré-processador
//   gcc -S A001.c             gera A001.s (assembly): procure "call"
//   gcc -c A001.c             gera A001.o (código objeto)
//   gcc A001.o -o padaria     liga e gera o executável
//   ./padaria
//   echo $?                   mostra o 0 do return
