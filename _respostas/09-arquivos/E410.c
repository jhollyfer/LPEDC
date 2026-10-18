// 0069 · Argumentos da linha de comando
// Exercício E410 · ★☆☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    printf("argc = %d\n", argc); // o nome do programa também conta
    int soma = 0;
    for (int i = 1; i < argc; i++) {
        int valor = atoi(argv[i]); // não avisa se o texto não é número
        printf("argv[%d] = \"%s\": %zu caractere(s), começa com '%c', atoi = %d\n",
               i, argv[i], strlen(argv[i]), argv[i][0], valor);
        soma += valor;
    }
    printf("Soma dos atoi: %d\n", soma);
    return 0;
}
