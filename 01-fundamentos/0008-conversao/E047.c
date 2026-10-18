// 0008 · Conversão e cast
// Exercício E047 · ★★★
//
// Sistemas de pagamento guardam dinheiro em centavos inteiros, para fugir
// dos erros dos números reais. Este programa converte R$ 19.99 para
// centavos. Sem rodar, quanto você espera? Rode. Explique o que aconteceu e
// conserte para mostrar 1999.
//
//   Saída esperada (depois de consertar):
//   R$ 19.99 = 1999 centavos
//
// Dicas:
// 1. Mostre valor * 100 com %.15f e veja o número de verdade.
// 2. Real para int corta, não arredonda: 1998.9999... vira 1998.
// 3. Somar 0.5 antes de cortar arredonda para o inteiro mais próximo.
// 4. Resposta esperada: mostra 1998, porque 19.99 não existe exato em
//    binário e 19.99 * 100 dá 1998.99999999999977..., que o int corta.
//    Conserto: int centavos = valor * 100 + 0.5; (no assunto 0010, a função
//    round faz isso).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    double valor = 19.99;
    int centavos = valor * 100;

    printf("R$ %.2f = %d centavos\n", valor, centavos);
    return 0;
}
