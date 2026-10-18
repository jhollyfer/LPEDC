// 0053 · Pilha e heap
// Exercício E313 · ★☆☆
//
// Complete o programa do placar do campeonato. Ele já tem a global recorde
// e o protótipo de ler_placar. Escreva ler_placar(int jogos) assim:
//
// - uma static int chamadas, que soma 1 a cada chamada;
// - um bloco no heap com jogos ints (confira o NULL);
// - placar[i] = i * 2 para cada jogo i;
// - mostra "Chamada N:" e os gols, e devolve o ponteiro.
//
// No main, chame ler_placar(3), atualize recorde com o maior gol do bloco e
// libere o bloco; depois faça o mesmo com ler_placar(2). No fim, mostre o
// recorde. Ao lado de cada declaração, escreva num comentário a região onde
// ela mora: código, dados, pilha ou heap.
//
//   Saída esperada:
//   Chamada 1: 0 2 4
//   Chamada 2: 0 2
//   Recorde: 4
//
// Dicas:
// 1. static dentro da função não mora no frame: mora junto das globais, e
//    por isso chamadas lembra o valor de uma chamada para a outra.
// 2. O ponteiro placar (pilha) e o bloco apontado (heap) são duas coisas
//    diferentes: o ponteiro some no return, o bloco continua vivo. Por isso
//    o endereço precisa voltar no return.
// 3. Resposta esperada: a saída acima. Regiões: recorde e chamadas nos
//    dados; jogos, i e o ponteiro placar na pilha; o bloco no heap; as
//    instruções de ler_placar no código.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int recorde = 0;

int *ler_placar(int jogos);

int main(void) {

    return 0;
}

int *ler_placar(int jogos) {
    (void)jogos; // apague esta linha quando usar o parâmetro
    return NULL;
}
