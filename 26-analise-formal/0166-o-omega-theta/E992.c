// 0166 · O, Ω e Θ de verdade
// Exercício E992 · ★☆☆
//
// Montar as duplas de um campeonato de n jogadores faz f(n) = n² - 6n
// comparações. Agora o limite é de baixo: prove que f(n) é Ω(n²). Escreva
// acha_n0(c), que testa todo n de 1 até 10000 e devolve o menor n0 a
// partir do qual custo(n) >= c * n² sempre vale (ou LIMITE + 1 se não
// houver). Mostre o resultado para c = 0.5, 0.9 e 1.0:
//
//   Saída esperada:
//   c = 0.5: n0 = 12
//   c = 0.9: n0 = 60
//   c = 1.0: nenhum n0 até 10000
//
// Dicas:
// 1. É a mesma busca do texto, com o sinal trocado: a falha agora é
//    custo(n) < c * n * n.
// 2. Use double para c; n * n em long vira double na conta c * n * n.
// 3. À mão: n² - 6n >= 0.5 n² vira 0.5 n >= 6, n >= 12. Com c = 1, seria
//    -6n >= 0, que nunca vale para n >= 1. O piso precisa de c < 1.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
