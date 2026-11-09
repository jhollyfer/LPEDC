// 0178 · Hash: divisão e multiplicação
// Exercício E1066 · ★★☆

#include <stdbool.h>
#include <stdio.h>

bool eh_primo(int x) {
    if (x < 2) {
        return false;
    }
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            return false;
        }
    }
    return true;
}

int primo_a_partir(int x) {
    while (!eh_primo(x)) {
        x++;
    }
    return x;
}

// distância até a potência de 2 mais próxima
int distancia_potencia(int m) {
    int p = 1;
    while (p * 2 <= m) {
        p *= 2;
    }
    int abaixo = m - p, acima = 2 * p - m;
    return abaixo < acima ? abaixo : acima;
}

void escolhe(int n, int alfa) {
    int alvo = (n + alfa - 1) / alfa; // n / alfa, arredondado para cima
    int m = primo_a_partir(alvo);
    while (distancia_potencia(m) < alvo / 8) { // perto demais de 2^p: o próximo primo
        m = primo_a_partir(m + 1);
    }
    printf("n = %d, alfa = %d: alvo %d -> m = %d (a %d da potência de 2 mais perto)\n",
           n, alfa, alvo, m, distancia_potencia(m));
}

int main(void) {
    escolhe(2000, 3);
    escolhe(3000, 2);
    escolhe(5000, 5);
    escolhe(100, 2);
    return 0;
}
