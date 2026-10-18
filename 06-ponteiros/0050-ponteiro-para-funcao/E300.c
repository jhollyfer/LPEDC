// 0050 · Ponteiro para função
// Exercício E300 · ★★★
//
// Você tem R$ 50 no bolso e quer ver os produtos da lojinha do mais perto
// desse valor ao mais longe. Ordene com qsort pela distância até 50
// (|preço - 50|); em caso de empate, o mais barato vem antes.
//
//   int precos[7] = {47, 58, 50, 39, 53, 61, 44};
//
// A função de comparação só recebe dois endereços, então guarde o alvo
// numa variável global static. Depois de mostrar a ordem para 50, mude o
// alvo para 60 (você achou mais R$ 10), ordene de novo e mostre.
//
//   Saída esperada:
//   50 47 53 44 58 39 61
//   61 58 53 50 47 44 39
//
// Dicas:
// 1. Calcule as distâncias de x e y com abs() (stdlib.h).
// 2. Compare primeiro as distâncias; se forem iguais, compare os preços.
// 3. Resposta esperada: 50 47 53 44 58 39 61 e, com alvo 60,
//    61 58 53 50 47 44 39 (61 está a 1 do alvo, 58 está a 2).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
