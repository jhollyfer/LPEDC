// 0118 · Juntando tudo
// Exercício E706 · ★★☆

#include <stdio.h>

// as quatro caixas-pretas: cada uma devolve quantos passos deu
long misterio_a(long n) {
    long passos = 0;
    for (long i = 0; i < n; i++) {
        for (long j = i + 1; j < n; j++) {
            passos++;
        }
    }
    return passos;
}

long misterio_b(long n) {
    if (n <= 1) {
        return 1;
    }
    return misterio_b(n / 2) + misterio_b(n - n / 2) + 1;
}

long misterio_c(long n) {
    long passos = 0;
    for (long i = 0; i < n; i++) {
        for (long j = 1; j < n; j *= 2) {
            passos++;
        }
    }
    return passos;
}

long misterio_d(long n) {
    long passos = 0;
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            for (long k = j; k < n; k += 2) {
                passos++;
            }
        }
    }
    return passos;
}

const char *classe(long (*f)(long), double *razao) {
    *razao = (double)f(128) / f(64);
    if (*razao < 2.15) {
        return "Θ(n)";
    }
    if (*razao < 3) {
        return "Θ(n log n)";
    }
    if (*razao < 6) {
        return "Θ(n²)";
    }
    return "Θ(n³)";
}

int main(void) {
    const char *nomes[] = {"misterio_a", "misterio_b", "misterio_c", "misterio_d"};
    long (*funcoes[])(long) = {misterio_a, misterio_b, misterio_c, misterio_d};
    for (int i = 0; i < 4; i++) {
        double r;
        const char *c = classe(funcoes[i], &r);
        printf("%s: dobrou n, custo x%.2f -> %s\n", nomes[i], r, c);
    }
    return 0;
}
