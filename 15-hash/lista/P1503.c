// Lista · Módulo 15 · Tabelas hash
// Exercício P1503 · ★☆☆ · Sondagem linear nos armários
//
// Os armários da academia usam endereçamento aberto com m = 11 posições,
// h(k) = k % 11 e sondagem LINEAR: (h(k) + i) % 11, para i = 0, 1, 2, ...
// Escreva int insere(int tab[], int k), que devolve quantas posições olhou
// até achar uma vazia (VAZIO = -1). Insira 35, 46, 13, 24, 57, 10, 21, 2,
// mostre as sondagens de cada um e a tabela final (_ para posição vazia).
//
//   Saída esperada:
//   35 (h = 2): sondagens 1
//   46 (h = 2): sondagens 2
//   13 (h = 2): sondagens 3
//   24 (h = 2): sondagens 4
//   57 (h = 2): sondagens 5
//   10 (h = 10): sondagens 1
//   21 (h = 10): sondagens 2
//   2 (h = 2): sondagens 6
//   tabela: 21 _ 35 46 13 24 57 2 _ _ 10
//
// Dicas:
// 1. pos = (h + i) % M: o % faz a sondagem dar a volta (o 21 cai em 10,
//    ocupado, e vai para 0).
// 2. O 2 chega por último e paga 6 sondagens, porque o bloco 2..7 já está
//    todo ocupado. É o agrupamento primário: quanto maior o bloco, mais
//    chaves caem nele e mais ele cresce.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define M 11
#define VAZIO -1

int main(void) {

    return 0;
}
