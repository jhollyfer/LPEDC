// 0131 · Divisão e conquista
// Exercício E781 · ★☆☆

#include <stdio.h>

static int chamadas = 0;

// soma de v[ini..fim] (intervalo fechado), dividindo ao meio
int soma(const int v[], int ini, int fim) {
    chamadas++;
    if (ini == fim) {
        return v[ini];                  // um dia só: a soma é ele
    }
    int meio = ini + (fim - ini) / 2;
    return soma(v, ini, meio) + soma(v, meio + 1, fim);
}

int main(void) {
    int vendas[] = {320, 415, 280, 510, 390, 605, 720, 460};
    int total = soma(vendas, 0, 7);
    printf("Total: R$ %d\n", total);
    printf("Chamadas: %d\n", chamadas);
    return 0;
}
