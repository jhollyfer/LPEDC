// 0002 · Variáveis
// Exercício E012 · ★★★
//
// Resposta: "A 65", "B", "7 55" e "[ ] 32". '7' é o caractere sete, que
// tem o código 55 na tabela ASCII; 7 é o número sete. São coisas diferentes.

#include <stdio.h>

int main(void) {
    char letra = 'A';
    printf("%c %d\n", letra, letra);
    letra = 66;
    printf("%c\n", letra);
    char digito = '7';
    printf("%c %d\n", digito, digito);
    char espaco = ' ';
    printf("[%c] %d\n", espaco, espaco);
    return 0;
}
