// A011 · O aviso da padaria

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
//   gcc -E A011.c | wc -l     quantas linhas depois do pré-processador
//   gcc -S A011.c             gera A011.s (assembly): procure "call"
//   gcc -c A011.c             gera A011.o (código objeto)
//   gcc A011.o -o padaria     liga e gera o executável
//   ./padaria
//   echo $?                   mostra o 0 do return
