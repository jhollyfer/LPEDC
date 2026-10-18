// 0018 · Lógicos: E, OU, NÃO
// Exercício E106 · ★★☆

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
    bool barrado2 = idade < 18 || !tem_ingresso; // De Morgan

    printf("barrado (original):  %d\n", barrado);
    printf("barrado (De Morgan): %d\n", barrado2);
    return 0;
}
