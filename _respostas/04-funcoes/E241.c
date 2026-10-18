// 0041 · Juntando tudo: o caixa da lanchonete
// Exercício E241 · ★☆☆

#include <stdio.h>

int ler_inteiro_entre(int min, int max) {
    int valor;
    do {
        printf("Valor entre %d e %d: ", min, max);
        if (scanf("%d", &valor) != 1) {
            return min;
        }
    } while (valor < min || valor > max);
    return valor;
}

int main(void) {
    int nota = ler_inteiro_entre(0, 10);
    int quantidade = ler_inteiro_entre(1, 5);
    printf("Nota %d, quantidade %d\n", nota, quantidade);
    return 0;
}
