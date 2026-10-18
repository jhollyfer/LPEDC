// 0005 · Do .c ao executável
// Exercício E027 · ★★☆
//
// Resposta: falta ";" depois do primeiro printf (compilador: "expected ';'"); "prinft" está escrito errado (o compilador só avisa "implicit declaration", e o ligador para com "undefined reference to prinft"). Consertado, mostra "Linha 1" e "Linha 2".

#include <stdio.h>

int main(void) {
    printf("Linha 1\n");
    printf("Linha 2\n");
    return 0;
}
