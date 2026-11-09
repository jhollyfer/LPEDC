// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1716 · ★★☆ · Contador com zerar: o reset que não varre tudo

#include <stdbool.h>
#include <stdio.h>

#define K 16

int b[K], maior = -1;

int incrementa(void) {
    int i = 0, custo = 0;
    while (i < K && b[i] == 1) {
        b[i++] = 0;
        custo++;
    }
    if (i < K) {
        b[i] = 1;
        custo++;
        if (i > maior) maior = i; // o bit mais alto ligado desde o último zerar
    }
    return custo;
}

int zera(bool esperto) {
    int ate = esperto ? maior : K - 1, custo = 0;
    for (int i = 0; i <= ate; i++) {
        b[i] = 0;
        custo++;
    }
    maior = -1;
    return custo;
}

long passo(bool esperto, char op, int vezes, int *incs, int *zeros) {
    long total = 0;
    for (int r = 0; r < vezes; r++) {
        if (op == 'i') {
            total += incrementa();
            (*incs)++;
        } else {
            total += zera(esperto);
            (*zeros)++;
        }
    }
    return total;
}

long roda(bool esperto, int *incs, int *zeros) {
    long total = 0;
    *incs = *zeros = 0;
    for (int t = 0; t < 50; t++) { // turnos curtos
        total += passo(esperto, 'i', 3, incs, zeros);
        total += passo(esperto, 'z', 1, incs, zeros);
    }
    total += passo(esperto, 'i', 1000, incs, zeros);
    total += passo(esperto, 'z', 1, incs, zeros);
    total += passo(esperto, 'z', 1, incs, zeros);
    return total;
}

int main(void) {
    int incs, zeros;

    long bobo = roda(false, &incs, &zeros);
    long esperto = roda(true, &incs, &zeros);
    printf("Incrementos: %d | zerares: %d\n", incs, zeros);
    printf("Zerar varrendo tudo: %ld\n", bobo);
    printf("Zerar até o maior:   %ld\n", esperto);
    printf("Limite 3·%d + %d = %d\n", incs, zeros, 3 * incs + zeros);
    return 0;
}
