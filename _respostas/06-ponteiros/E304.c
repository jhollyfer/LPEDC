// 0051 · void * e cast
// Exercício E304 · ★★☆

#include <stdio.h>

void mostra_vetor(const void *v, size_t n, size_t tam, void (*mostra)(const void *)) {
    const unsigned char *inicio = v;
    for (size_t i = 0; i < n; i++) {
        mostra(inicio + i * tam);
    }
    printf("\n");
}

void mostra_int(const void *p) { printf("%d ", *(const int *)p); }
void mostra_double(const void *p) { printf("%.2f ", *(const double *)p); }

int main(void) {
    int senhas[4] = {101, 102, 103, 104};
    double notas[3] = {7.5, 9.25, 6.0};

    mostra_vetor(senhas, 4, sizeof senhas[0], mostra_int);
    mostra_vetor(notas, 3, sizeof notas[0], mostra_double);
    return 0;
}
