// 0031 · Aleatórios
// Exercício E183 · ★★☆
//
// O jogo clássico: o programa sorteia um número de 1 a 100 (com
// srand(time(NULL))) e a pessoa tenta adivinhar. A cada palpite, ele diz
// "Mais alto" ou "Mais baixo". No acerto, mostra quantas tentativas foram.
// Se o scanf falhar (letra ou fim da entrada), o jogo encerra mostrando o
// número sorteado.
//
//   Exemplo (o número sorteado muda a cada vez):
//   Palpite: 50
//   Mais baixo.
//   Palpite: 25
//   Mais alto.
//   Palpite: 37
//   Acertou em 3 tentativas!
//
// Dicas:
// 1. Sorteie uma vez só, antes do laço. O laço repete enquanto o palpite for
//    diferente do segredo (do-while combina bem).
// 2. Para testar sem depender da sorte, troque time(NULL) por uma semente
//    fixa enquanto desenvolve, e depois volte.
// 3. Resposta esperada: o jogo funciona para qualquer sorteio. Chutando
//    sempre o meio do intervalo que sobrou, você acerta em no máximo 7
//    tentativas, porque 2 elevado a 7 = 128 >= 100.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    return 0;
}
