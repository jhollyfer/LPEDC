// 0058 · Pilha e heap
// Exercício E343 · ★☆☆
//
// Leia o trecho abaixo (não precisa rodar) e diga em que região da memória
// mora cada item: código, dados, heap ou pilha.
//
//   int recorde = 0;
//   
//   int *ler_placar(int jogos) {
//       static int chamadas = 0;
//       int gols = 2;
//       int *placar = malloc(jogos * sizeof(int));
//       chamadas++;
//       return placar;
//   }
//
// a) recorde; b) chamadas; c) jogos; d) gols;
// e) a variável placar (o ponteiro);
// f) o bloco para onde placar aponta;
// g) as instruções de ler_placar.
//
// Depois responda: quais desses itens ainda existem quando ler_placar
// retorna?
//
// Dicas:
// 1. static dentro de função não mora no frame: mora junto das globais.
// 2. O ponteiro e o bloco apontado são duas coisas diferentes, em lugares
//    diferentes.
// 3. Resposta esperada: a) dados; b) dados; c) pilha (parâmetro é local);
//    d) pilha; e) pilha; f) heap; g) código. Depois do return continuam vivos
//    recorde, chamadas, o bloco do heap e o código. jogos, gols e o ponteiro
//    placar somem com o frame; por isso o endereço precisa voltar no return.
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>

int main(void) {

    return 0;
}
