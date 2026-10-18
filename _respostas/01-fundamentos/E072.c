// 0012 · Aritmética
// Exercício E072 · ★★★
//
// Resposta: 472 vira 274. Com 120, o invertido vale 21: um int não guarda
// zero à esquerda. Para mostrar 021, use %03d.

#include <stdio.h>

int main(void) {
    int n;
    printf("Número: ");
    scanf("%d", &n);

    int unidade = n % 10;       // 2
    int dezena = n / 10 % 10;   // 7
    int centena = n / 100;      // 4
    int invertido = unidade * 100 + dezena * 10 + centena;

    printf("Ao contrário: %d\n", invertido);
    printf("Com 3 dígitos: %03d\n", invertido);
    return 0;
}
