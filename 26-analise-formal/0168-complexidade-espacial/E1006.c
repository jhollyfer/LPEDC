// 0168 · Complexidade espacial
// Exercício E1006 · ★★☆
//
// A escala de plantão da clínica tem 7 médicos, numerados de 1 a 7. Todo
// mês ela gira k posições para a direita: os k últimos passam para a
// frente. Escreva gira(v, n, k) usando Θ(1) de espaço extra, sem vetor
// auxiliar, com o truque das três inversões: inverta o vetor inteiro,
// depois os k primeiros, depois o resto. Gire 3 posições, mostre, e depois
// gire mais 11 posições e mostre de novo:
//
//   Saída esperada:
//   5 6 7 1 2 3 4
//   1 2 3 4 5 6 7
//
// Dicas:
// 1. Escreva antes inverte(v, ini, fim), que troca as pontas como a
//    inverte_no_lugar do texto, mas só entre ini e fim.
// 2. 1 2 3 4 5 6 7 → (inteiro) 7 6 5 4 3 2 1 → (3 primeiros) 5 6 7 4 3 2 1
//    → (resto) 5 6 7 1 2 3 4.
// 3. Girar 11 é o mesmo que girar 11 % 7 = 4. 3 + 4 = 7: volta ao início.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
