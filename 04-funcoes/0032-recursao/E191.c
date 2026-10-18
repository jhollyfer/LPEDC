// 0032 · Recursão
// Exercício E191 · ★★★
//
// Esta função deveria somar os dígitos de um número (2026 -> 10), mas tem
// DOIS erros. O rodar mostra dois avisos, um para cada erro; leia os dois.
// Se você rodar mesmo assim, o programa morre com stack-overflow. Conserte
// os dois erros e rode até aparecer "2026 -> 10" e "99999 -> 45", sem
// nenhum aviso.
//
// Dicas:
// 1. Leia o aviso "suggest parentheses around assignment": o que n = 0 faz
//    dentro do if? Quanto vale essa expressão?
// 2. Leia "control reaches end of non-void function": a conta do caso
//    recursivo é feita e jogada fora. Quem chamou recebe o quê?
// 3. Resposta esperada: (1) "n = 0" atribui 0 a n e vale 0 (falso): o caso
//    base nunca é aceito, e a chamada seguinte é soma_digitos(0) de novo, para
//    sempre. O certo é n == 0. (2) Falta o return na linha do caso recursivo.
//    Consertado: 2026 -> 10 e 99999 -> 45.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int soma_digitos(int n) {
    if (n = 0) {
        return 0;
    }
    n % 10 + soma_digitos(n / 10);
}

int main(void) {
    printf("2026 -> %d\n", soma_digitos(2026));
    printf("99999 -> %d\n", soma_digitos(99999));
    return 0;
}
