// 0013 · Lógicos: E, OU, NÃO
// Exercício E076 · ★★☆
//
// Na portaria do show, a regra está escrita com um NÃO na frente de tudo.
// Use De Morgan para reescrever "barrado" sem o ! do lado de fora dos
// parênteses e mostre as duas versões lado a lado, para provar que dão o
// mesmo resultado.
//
//   Idade: 16
//   Tem ingresso (1 = sim, 0 = não): 1
//   barrado (original):  1
//   barrado (De Morgan): 1
//
// Dicas:
// 1. !(a && b) vira !a || !b.
// 2. !(idade >= 18) é idade < 18. E !tem_ingresso fica como está.
// 3. Resposta esperada: barrado = idade < 18 || !tem_ingresso.
//    Testes: 20 e 1 → 0; 16 e 1 → 1; 30 e 0 → 1.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int idade, resposta;
    printf("Idade: ");
    scanf("%d", &idade);
    printf("Tem ingresso (1 = sim, 0 = não): ");
    scanf("%d", &resposta);
    bool tem_ingresso = resposta;

    bool barrado = !(idade >= 18 && tem_ingresso);
    bool barrado2 = false; // reescreva aqui, sem o ! na frente dos parênteses

    printf("barrado (original):  %d\n", barrado);
    printf("barrado (De Morgan): %d\n", barrado2);
    return 0;
}
