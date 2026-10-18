// 0157 · Força bruta
// Exercício E938 · ★☆☆

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *extrato = "Pix R$ 50,00; Uber R$ 23,90; Mercado R$ 187,45";
    int total = 0;

    const char *p = strstr(extrato, "R$");
    while (p != NULL) {
        total++;
        printf("posição %td: ", p - extrato);
        // o valor começa 3 letras depois do "R$" e vai até o ';' (ou o fim)
        for (const char *c = p + 3; *c != '\0' && *c != ';'; c++) {
            putchar(*c);
        }
        printf("\n");
        p = strstr(p + 2, "R$");
    }
    printf("%d valores\n", total);
    return 0;
}
