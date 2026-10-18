// 0014 · if
// Exercício E083 · ★★★
//
// O controle de estoque da padaria tem duas regras: com menos de 10 pães,
// mostra "Estoque baixo." e "Pedir mais pão."; com 0 pão, mostra também
// "Esgotado!" e "Desligar a vitrine.". O recuo do programa abaixo promete
// isso, mas o compilador não olha recuo: com 40 pães aparecem duas linhas
// que não deviam. Rode com 40, leia os avisos (o código está quebrado de
// propósito) e conserte. Depois, acrescente uma terceira regra: com mais de
// 100 pães, mostre quantos passaram do ideal.
//
//   Pães no estoque: 130
//   Excesso: 30 pães acima do ideal.
//   Estoque: 130
//
// Dicas:
// 1. Sem chaves, o if manda só na primeira instrução depois dele.
// 2. Ponha chaves em todos os if. A regra nova é outro if solto, com
//    estoque - 100 no printf.
// 3. Resposta esperada: 40 → só "Estoque: 40"; 6 → "Estoque baixo.",
//    "Pedir mais pão." e "Estoque: 6"; 0 → as quatro mensagens e
//    "Estoque: 0"; 130 → a linha do excesso e "Estoque: 130".
//
// Escreva sua resposta abaixo (conserte e estenda o código):

#include <stdio.h>

int main(void) {
    int estoque;
    printf("Pães no estoque: ");
    if (scanf("%d", &estoque) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    if (estoque < 10)
        printf("Estoque baixo.\n");
        printf("Pedir mais pão.\n");
    if (!estoque)
        printf("Esgotado!\n");
        printf("Desligar a vitrine.\n");
    printf("Estoque: %d\n", estoque);
    return 0;
}
