// A061 · Sair da prisão: dados até tirar dupla

#include <stdio.h>
#include <stdlib.h> // rand e srand

int main(void) {
    srand(2022); // semente fixa: a mesma sequência a cada execução

    int dado1, dado2;
    int jogadas = 0;

    do {
        dado1 = 1 + rand() % 6; // rand() % 6 vai de 0 a 5; + 1 vira 1 a 6
        dado2 = 1 + rand() % 6;
        jogadas++;
        printf("Jogada %d: %d e %d\n", jogadas, dado1, dado2);
    } while (dado1 != dado2);

    printf("Dupla de %d na jogada %d. Saiu da prisão!\n", dado1, jogadas);
    return 0;
}
// Saída (glibc, Linux; em outro sistema a sequência pode ser outra):
// Jogada 1: 1 e 5
// Jogada 2: 5 e 1
// Jogada 3: 1 e 6
// Jogada 4: 4 e 4
// Dupla de 4 na jogada 4. Saiu da prisão!
