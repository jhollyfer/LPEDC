// A341 · Descendo com size_t sem cair do zero

#include <stdio.h>
#include <string.h>

int main(void) {
    int notas[] = {7, 9, 6, 10};
    size_t n = sizeof notas / sizeof notas[0]; // sizeof devolve size_t

    // testa e depois desce: i vale n-1, n-2, ..., 0 dentro do laço
    printf("de trás para a frente:");
    for (size_t i = n; i-- > 0;) {
        printf(" %d", notas[i]);
    }
    printf("\n");

    // a mesma forma não faz nada com um vetor vazio
    size_t vazio = 0;
    int voltas = 0;
    for (size_t i = vazio; i-- > 0;) {
        voltas++;
    }
    printf("com n = 0: %d voltas\n", voltas);

    // por que "for (size_t i = n - 1; ...)" é perigoso: n - 1 com n = 0
    printf("vazio - 1 = %zu\n", vazio - 1);

    // diferença de tamanhos: size_t menos size_t nunca é negativo
    const char *a = "Ana";
    const char *b = "Bernardo";
    printf("strlen(a) - strlen(b) = %zu\n", strlen(a) - strlen(b));
    printf("Ana é mais longo? %s (com a subtração)\n", strlen(a) - strlen(b) > 0 ? "sim" : "não");
    printf("Ana é mais longo? %s (comparando direto)\n", strlen(a) > strlen(b) ? "sim" : "não");
    return 0;
}
// Saída:
// de trás para a frente: 10 6 9 7
// com n = 0: 0 voltas
// vazio - 1 = 18446744073709551615
// strlen(a) - strlen(b) = 18446744073709551611
// Ana é mais longo? sim (com a subtração)
// Ana é mais longo? não (comparando direto)
