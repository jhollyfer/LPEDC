// 0080 · Lista circular
// Exercício E477 · ★★☆
//
// Rita, Davi e Lia vão de carro de Belo Horizonte a Vitória e voltam: são
// 1000 km de estrada.
// Eles revezam ao volante, nesta ordem, cada um dirigindo um trecho de
// 150 km (o último trecho é o que sobrar). Escreva o programa com uma lista
// circular de structs (nome e km dirigidos) e mostre cada trecho e, no fim,
// quanto cada um dirigiu.
//
//   Saída esperada:
//   trecho 1: Rita dirige 150 km
//   trecho 2: Davi dirige 150 km
//   trecho 3: Lia dirige 150 km
//   trecho 4: Rita dirige 150 km
//   trecho 5: Davi dirige 150 km
//   trecho 6: Lia dirige 150 km
//   trecho 7: Rita dirige 100 km
//   Rita: 400 km
//   Davi: 300 km
//   Lia: 300 km
//
// Escreva tudo neste arquivo, com uma struct sua (por exemplo
// struct motorista { char nome[20]; int km; struct motorista *prox; }).
//
// Dicas:
// 1. Monte a roda com inserção no fim guardando o último, como no lista.c.
// 2. O laço da viagem: enquanto faltar km, o trecho é 150 ou o que falta (o
//    menor dos dois); some no km de quem dirige e passe para o próximo.
// 3. Para o resumo, uma volta com do-while a partir do primeiro.
// 4. Para liberar, corte o círculo (ultimo->prox = NULL) e libere como lista
//    comum. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
