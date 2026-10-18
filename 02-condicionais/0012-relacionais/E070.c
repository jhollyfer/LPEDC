// 0012 · Relacionais e a verdade em C
// Exercício E070 · ★★☆
//
// A bala custa R$ 0,70 e a criança pagou com sete moedas de 10 centavos. O
// programa abaixo diz que ela NÃO pagou o valor exato. Rode, acrescente um
// printf que mostre pago com 20 casas e conserte de dois jeitos, mostrando
// as duas linhas: (a) com uma tolerância usando fabs; (b) trabalhando com
// centavos em int.
//
// Dicas:
// 1. Mostre pago com printf("%.20f") e veja o que tem lá dentro.
// 2. (a) fabs(pago - preco) < 1e-9; (b) int preco = 70; int pago = 7 * 10;
// 3. Resposta esperada: o printf mostra 0.70000000000000006661 (0.1 não é
//    exato em binário), diferente de 0.7. Consertado, os dois jeitos
//    mostram "Pagou o valor exato? 1".
//
// Escreva sua resposta abaixo (conserte o código):

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    double preco = 0.7;
    double pago = 0.1 * 7; // sete moedas de 10 centavos

    bool exato = pago == preco;
    printf("Pagou o valor exato? %d\n", exato);
    return 0;
}
