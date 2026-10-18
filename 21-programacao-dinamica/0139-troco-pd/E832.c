// 0139 · Troco com programação dinâmica
// Exercício E832 · ★★☆
//
// Você vai pagar um lanche de R$ 7 com moedas de R$ 1, cédulas de R$ 2 e
// cédulas de R$ 5. Duas perguntas diferentes:
//
// a) Quantas COMBINAÇÕES de dinheiro somam R$ 7? (5 + 2 e 2 + 5 são a mesma)
// b) A máquina de autoatendimento aceita uma nota ou moeda por vez. Quantas
//    SEQUÊNCIAS diferentes de inserção somam R$ 7? (5 + 2 e 2 + 5 contam
//    separado)
//
// Escreva as funções long long combinacoes(int total) e long long
// sequencias(int total), cada uma com o seu vetor de PD, e mostre as duas
// respostas.
//
//   Saída esperada:
//   combinações: 6
//   sequências:  26
//
// Dicas:
// 1. As duas começam com w[0] = 1 e fazem w[v] += w[v - valor].
// 2. A diferença é só a ordem dos laços. Combinações: valor do dinheiro por
//    fora, total por dentro. Sequências: total por fora (w[v] = soma de
//    w[v - valor] para cada valor <= v, "qual foi a última inserção?").
// 3. Confira a) à mão: 5+2, 5+1+1, 2+2+2+1, 2+2+1+1+1, 2+1+1+1+1+1 e
//    sete moedas de 1.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
