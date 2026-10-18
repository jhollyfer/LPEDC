// 0025 · Padrões de laço
// Exercício E150 · ★★★
//
// O app de corrida registra a distância de 6 treinos, em km inteiros. Leia os
// 6 valores (inteiros) e faça o programa mostrar a resposta de duas perguntas:
//
// a) Os treinos estão em ordem crescente (cada um MAIOR que o anterior)?
// b) Qual foi a maior sequência de treinos seguidos em alta?
//
//   Treino 1: 3
//   Treino 2: 5
//   Treino 3: 8
//   Treino 4: 2
//   Treino 5: 4
//   Treino 6: 9
//   Em ordem crescente? não
//   Maior sequência em alta: 3 treinos
//
// Dicas:
// 1. Guarde o valor anterior numa variável. A partir do 2º treino, compare
//    o atual com o anterior. No fim de cada volta, anterior = atual.
// 2. Flag: bool crescente = true no começo; vira false na primeira descida
//    (ou empate) e nunca mais volta. Para (b), um contador da sequência atual,
//    que zera (volta a 1) quando a alta acaba, e um "maior" que guarda o
//    recorde.
// 3. Resposta esperada: com 3 5 8 2 4 9, "não" e 3 treinos (3 5 8 ou 2 4 9).
//    Com 1 2 3 4 5 6: "sim" e 6. Com 5 5 5 5 5 5: "não" e 1.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
