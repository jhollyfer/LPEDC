// 0089 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E532 · ★★☆
//
// Resposta: os dois pilha_desempilha estavam na ordem errada. O primeiro a
// sair é o operando da direita, então ele vai para b. A soma e a
// multiplicação escondiam o erro porque a + b == b + a.

#include <stdio.h>
// Na pasta do assunto basta #include "pilha.h" (o rodar compila o pilha.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0089-pilha-aplicacoes/pilha.c"

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
