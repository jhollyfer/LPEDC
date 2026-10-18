// 0089 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E533 · ★★★

#include <stdio.h>
// Na pasta do assunto basta #include "pilha.h" (o rodar compila o pilha.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0089-pilha-aplicacoes/pilha.c"

int precedencia(int op) {
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '+' || op == '-') {
        return 1;
    }
    return 0; // o '(' nunca sai por causa de um operador
}

void para_posfixa(const char *in, char *out) {
    Pilha *ops = pilha_cria();
    int k = 0;
    if (ops == NULL) {
        out[0] = '\0';
        return;
    }
    for (int i = 0; in[i] != '\0'; i++) {
        char c = in[i];
        int topo;
        if (c >= '0' && c <= '9') {
            out[k++] = c;
            out[k++] = ' ';
        } else if (c == '(') {
            pilha_empilha(ops, c);
        } else if (c == ')') {
            while (pilha_desempilha(ops, &topo) && topo != '(') {
                out[k++] = (char)topo;
                out[k++] = ' ';
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (pilha_topo(ops, &topo) && precedencia(topo) >= precedencia(c)) {
                pilha_desempilha(ops, &topo);
                out[k++] = (char)topo;
                out[k++] = ' ';
            }
            pilha_empilha(ops, c);
        }
    }
    int topo;
    while (pilha_desempilha(ops, &topo)) {
        out[k++] = (char)topo;
        out[k++] = ' ';
    }
    out[k > 0 ? k - 1 : 0] = '\0'; // troca o último espaço pelo fim da string
    pilha_libera(ops);
}

int main(void) {
    const char *testes[] = {"1+2*3", "(6+2)*5-8/4", "(1+2)*(3-4)", "9-4-2"};
    char saida[64];
    for (int i = 0; i < 4; i++) {
        para_posfixa(testes[i], saida);
        printf("%s -> %s\n", testes[i], saida);
    }
    return 0;
}
