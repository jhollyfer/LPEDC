// Lista · Módulo 03 · Laços
// Exercício P0320 · ★★☆ · A média da turma que dá errado
//
// O programa abaixo deveria somar as 5 notas do simulado (7, 9, 6, 8 e 10) e
// mostrar a média 8.0, mas mostra 2.0. São dois erros de acumulador, de
// propósito: um zera a soma no lugar errado e o outro faz a divisão inteira.
// Conserte os dois:
//
//   Saída esperada:
//   Soma: 40
//   Média: 8.0
//
// Dicas:
// 1. Uma variável zerada dentro do laço é zerada em toda volta.
// 2. soma / 5 entre dois int corta a parte decimal. Use 5.0 ou um cast.
// 3. Resposta esperada: Soma: 40, Média: 8.0.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int soma;

    for (int i = 1; i <= 5; i++) {
        soma = 0;
        int nota = (i == 1) ? 7 : (i == 2) ? 9 : (i == 3) ? 6 : (i == 4) ? 8 : 10;
        soma += nota;
    }
    double media = soma / 5;

    printf("Soma: %d\n", soma);
    printf("Média: %.1f\n", media);
    return 0;
}
