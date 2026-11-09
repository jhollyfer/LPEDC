// Lista · Módulo 12 · Pilhas e filas
// Exercício P1208 · ★☆☆ · O jogo das bolhas de mesma cor

#include <stdio.h>
#include <string.h>

void estoura(const char *bolhas, char *sobra) {
    int n = 0; // sobra[0..n-1] é a pilha; o topo é sobra[n - 1]
    for (int i = 0; bolhas[i] != '\0'; i++) {
        if (n > 0 && sobra[n - 1] == bolhas[i]) {
            n--; // as duas estouram
        } else {
            sobra[n++] = bolhas[i];
        }
    }
    sobra[n] = '\0';
}

int main(void) {
    const char *jogos[4] = {"abbaca", "aabbcc", "azxxzy", "abc"};
    for (int i = 0; i < 4; i++) {
        char sobra[64];
        estoura(jogos[i], sobra);
        printf("%s -> %s\n", jogos[i], sobra[0] != '\0' ? sobra : "(nada)");
    }
    return 0;
}
