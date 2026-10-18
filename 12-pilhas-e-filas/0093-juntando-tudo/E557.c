// 0093 · Juntando tudo: a calculadora de expressões
// Exercício E557 · ★★★
//
// O estacionamento da vila é um beco sem saída onde cabem 4 carros em fila
// indiana: quem entrou por último fica na boca do beco. Para um carro do
// fundo sair, todos os que estão na frente dele saem para a rua (cada um
// conta uma MANOBRA), ele vai embora, e os outros voltam na mesma ordem.
// Com o beco cheio, quem chega espera numa fila na rua e entra assim que
// abrir uma vaga.
//
// Simule com uma pilha (o beco), uma pilha auxiliar (a rua, na manobra) e
// uma fila (a espera). Os eventos são: entram 1, 2, 3, 4 e 5; saem 2, 1, 4,
// 3 e 5. Ao sair, mostre quantas manobras aquele carro fez.
//
//   Saída esperada:
//   Carro 5 espera na rua
//   Carro 2 saiu; manobras: 0
//   Carro 5 entrou (vinha da fila)
//   Carro 1 saiu; manobras: 0
//   Carro 4 saiu; manobras: 2
//   Carro 3 saiu; manobras: 2
//   Carro 5 saiu; manobras: 3
//
// Dicas:
// 1. Guarde as manobras num vetor int manobras[6], indexado pelo número do
//    carro.
// 2. Para tirar o carro X: desempilhe do beco para a auxiliar até achar X
//    (somando 1 nas manobras de cada um que saiu), descarte X e devolva
//    todos da auxiliar para o beco.
// 3. Depois de cada saída, se a fila de espera não estiver vazia, o
//    primeiro entra no beco.
// 4. Represente os eventos com dois vetores: char tipo[] = "EEEEESSSSS" e
//    int carro[] = {1, 2, 3, 4, 5, 2, 1, 4, 3, 5}.
// 5. Resposta esperada: as sete linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "fila.h"
#include "pilha.h"

int main(void) {

    return 0;
}
