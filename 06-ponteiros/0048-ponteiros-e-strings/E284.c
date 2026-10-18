// 0048 · Ponteiros e strings
// Exercício E284 · ★☆☆
//
// Complete o programa, que já tem as declarações
//
//   char cidade[] = "Natal";
//   const char *estado = "RN";
//
// 1. O programa já mostra sizeof e strlen das duas.
// 2. Troque a primeira letra da cidade por 'n', faça estado apontar para
//    "PB" e mostre "cidade - estado".
// 3. Volte a cidade para "Natal" com strcpy e mostre de novo.
// 4. Tente também cidade = "Recife"; e estado[0] = 'r'; rode, leia o erro
//    do compilador e apague essas duas linhas.
//
//   Saída esperada:
//   sizeof cidade = 6, sizeof estado = 8
//   strlen cidade = 5, strlen estado = 2
//   natal - PB
//   Natal - PB
//
// Dicas:
// 1. Vetor: o sizeof inclui o '\0'. Ponteiro: o sizeof é o de um endereço.
// 2. Vetor não recebe outro endereço com =; const char * não deixa
//    escrever no texto apontado. Os dois erros aparecem na compilação.
// 3. Resposta esperada: a saída acima. "Natal" cabe nos 6 bytes de cidade
//    (5 letras + '\0'); "Recife" não caberia.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <string.h>

int main(void) {
    char cidade[] = "Natal";
    const char *estado = "RN";

    printf("sizeof cidade = %zu, sizeof estado = %zu\n", sizeof cidade, sizeof estado);
    printf("strlen cidade = %zu, strlen estado = %zu\n", strlen(cidade), strlen(estado));

    // 2. 'n', "PB" e a linha "cidade - estado"

    // 3. strcpy e a linha de novo

    return 0;
}
