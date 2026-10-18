// 0053 · Ponteiros e strings
// Exercício E314 · ★☆☆
//
// Resposta: a) sizeof cidade = 6 (5 letras + '\0'), sizeof estado = 8 (um
// endereço); b) strlen 5 e 2; c) 1 funciona (o vetor é seu); 2 funciona (o
// ponteiro muda de alvo); 3 não compila (vetor não pode ser atribuído);
// 4 não compila por causa do const (sem ele, compilaria e cairia ao rodar,
// porque o literal é só leitura); 5 funciona (6 bytes bastam).

#include <stdio.h>
#include <string.h>

int main(void) {
    char cidade[] = "Natal";
    const char *estado = "RN";

    printf("sizeof cidade = %zu, sizeof estado = %zu\n", sizeof cidade, sizeof estado);
    printf("strlen cidade = %zu, strlen estado = %zu\n", strlen(cidade), strlen(estado));

    cidade[0] = 'n';
    estado = "PB";
    printf("%s %s\n", cidade, estado);
    strcpy(cidade, "Natal");
    printf("%s %s\n", cidade, estado);
    return 0;
}
