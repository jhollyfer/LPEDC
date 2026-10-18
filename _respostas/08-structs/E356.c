// 0060 · Typedef
// Exercício E356 · ★☆☆
//
// Resposta: compila. Metros e Segundos são só outros nomes para int, então
// somar os dois é permitido (não faz sentido físico, mas o C não sabe). Mostra
// 120, "5 m/s", 12 (o tamanho do vetor que Nome representa) e "12 6" (o vetor
// tem 12 bytes; o texto "Rayssa" tem 6 letras).

#include <stdio.h>
#include <string.h>

typedef int Metros;
typedef int Segundos;
typedef char Nome[12];

int main(void) {
    Metros distancia = 100;
    Segundos tempo = 20;
    Nome atleta = "Rayssa";

    printf("%d\n", distancia + tempo);
    printf("%d m/s\n", distancia / tempo);
    printf("%zu\n", sizeof(Nome));
    printf("%zu %zu\n", sizeof atleta, strlen(atleta));
    return 0;
}
