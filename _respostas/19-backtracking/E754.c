// 0126 · Permutações
// Exercício E754 · ★★☆

#include <stdio.h>
#include <string.h>

#define N 5
#define PODIO 3

int contagem = 0;
int podios_total = 0;
int com_bia = 0;

void troca(const char **a, const char **b) {
    const char *t = *a;
    *a = *b;
    *b = t;
}

void ordens(const char *v[], int i) {
    if (i == N) {
        contagem++;
        return;
    }
    for (int j = i; j < N; j++) {
        troca(&v[i], &v[j]);
        ordens(v, i + 1);
        troca(&v[i], &v[j]);
    }
}

// igual a ordens, mas para assim que ouro, prata e bronze estão decididos
void podios(const char *v[], int i) {
    if (i == PODIO) {
        podios_total++;
        for (int k = 0; k < PODIO; k++) {
            if (strcmp(v[k], "Bia") == 0) {
                com_bia++;
                break;
            }
        }
        return;
    }
    for (int j = i; j < N; j++) {
        troca(&v[i], &v[j]);
        podios(v, i + 1);
        troca(&v[i], &v[j]);
    }
}

int main(void) {
    const char *atletas[N] = {"Ana", "Bia", "Cris", "Dani", "Edu"};
    ordens(atletas, 0);
    printf("%d ordens de chegada\n", contagem);
    podios(atletas, 0);
    printf("%d pódios possíveis\n", podios_total);
    printf("Bia aparece em %d\n", com_bia);
    return 0;
}
