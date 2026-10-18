// 0048 · Ponteiros e strings
// Exercício E284 · ★☆☆

#include <stdio.h>
#include <string.h>

int main(void) {
    char cidade[] = "Natal";
    const char *estado = "RN";

    printf("sizeof cidade = %zu, sizeof estado = %zu\n", sizeof cidade, sizeof estado);
    printf("strlen cidade = %zu, strlen estado = %zu\n", strlen(cidade), strlen(estado));

    cidade[0] = 'n';  // o vetor é seu: pode mudar
    estado = "PB";    // o ponteiro muda de alvo
    printf("%s - %s\n", cidade, estado);

    strcpy(cidade, "Natal"); // cabe: 5 letras + '\0' em 6 bytes
    printf("%s - %s\n", cidade, estado);

    // cidade = "Recife";  não compila: vetor não pode ser atribuído
    // estado[0] = 'r';    não compila: o const não deixa escrever
    return 0;
}
