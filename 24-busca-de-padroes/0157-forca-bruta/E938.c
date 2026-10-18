// 0157 · Força bruta
// Exercício E938 · ★☆☆
//
// O extrato do mês veio numa linha só. Complete o laço para mostrar a posição
// de cada "R$" e o valor que vem depois dele (as letras a partir de 3 casas
// depois do "R$", até o ';' ou o fim do texto). Use strstr.
//
//   Saída esperada:
//   posição 4: 50,00
//   posição 19: 23,90
//   posição 37: 187,45
//   3 valores
//
// Dicas:
// 1. A posição é a diferença de endereços p - extrato; mostre com %td.
// 2. Para o valor, um ponteiro c começa em p + 3 e anda até achar ';' ou '\0',
//    mostrando cada letra com putchar.
// 3. A próxima busca começa depois do "R$" atual: strstr(p + 2, "R$").
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o laço):

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *extrato = "Pix R$ 50,00; Uber R$ 23,90; Mercado R$ 187,45";
    int total = 0;

    const char *p = strstr(extrato, "R$");
    while (p != NULL) {
        total++;
        // 1. mostre a posição de p dentro do extrato
        // 2. mostre o valor (de p + 3 até o ';' ou o fim) e pule a linha
        // 3. procure o próximo "R$" depois deste
        p = NULL; // apague esta linha quando escrever o passo 3
    }
    printf("%d valores\n", total);
    return 0;
}
