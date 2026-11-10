// 0084 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E502 · ★★☆

#include <stdio.h>
// Inclui a implementação do TAD para compilar sozinho (no enunciado: #include do .h).
#include "../../0084-pilha.c"

int avalia(const char *expr) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return 0;
    }
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c >= '0' && c <= '9') {
            pilha_empilha(p, c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int a = 0, b = 0;
            pilha_desempilha(p, &b); // sai primeiro: o da direita
            pilha_desempilha(p, &a);
            int r = c == '+' ? a + b : c == '-' ? a - b : c == '*' ? a * b : a / b;
            pilha_empilha(p, r);
        }
    }
    int resultado = 0;
    pilha_desempilha(p, &resultado);
    pilha_libera(p);
    return resultado;
}

int main(void) {
    const char *contas[] = {"2 3 +", "8 3 -", "8 4 /", "9 5 2 - *"};
    for (int i = 0; i < 4; i++) {
        printf("%s = %d\n", contas[i], avalia(contas[i]));
    }
    return 0;
}
