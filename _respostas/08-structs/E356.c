// 0060 · Typedef
// Exercício E356 · ★☆☆

#include <stdio.h>
#include <string.h>

typedef int Metros;
typedef int Segundos;
typedef char Nome[12]; // Nome é "vetor de 12 char"

int main(void) {
    Metros distancia = 100;
    Segundos tempo = 20;
    Nome atleta = "Rayssa";

    printf("Atleta: %s\n", atleta);
    printf("Velocidade: %d m/s\n", distancia / tempo);
    printf("sizeof(Nome) = %zu, strlen = %zu\n", sizeof(Nome), strlen(atleta));
    // não faz sentido físico, mas compila: para o C, os dois são int
    printf("distancia + tempo = %d\n", distancia + tempo);
    return 0;
}
