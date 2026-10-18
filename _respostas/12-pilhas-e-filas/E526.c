// 0088 · Juntando tudo: a calculadora de expressões
// Exercício E526 · ★★☆
//
// Resposta: o while da conversão usava ">" e deveria usar ">=". Com ">",
// operadores de mesma precedência ficavam empilhados e a conta associava à
// direita: 8 - (3 - 2) = 7 e 9 / (3 / 3) = 9. Com ">=", o operador que já
// estava na pilha sai antes do novo, e a conta associa à esquerda.

#include <stdio.h>
// Na pasta do assunto basta incluir os .h (o rodar compila o pilha.c e o
// fila.c junto). Aqui a resolução inclui as implementações para compilar
// sozinha.
#include "../../12-pilhas-e-filas/0088-juntando-tudo/fila.c"
#include "../../12-pilhas-e-filas/0088-juntando-tudo/pilha.c"

int prec(int op) {
    return (op == '*' || op == '/') ? 2 : 1;
}

void converte(const char *s, Fila *saida) {
    Pilha *ops = pilha_cria();
    if (ops == NULL) {
        return;
    }
    int topo;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            fila_insere(saida, s[i]); // guarda o caractere: '8', não 8
        } else {
            while (pilha_topo(ops, &topo) && prec(topo) >= prec(s[i])) {
                pilha_desempilha(ops, &topo);
                fila_insere(saida, topo);
            }
            pilha_empilha(ops, s[i]);
        }
    }
    while (pilha_desempilha(ops, &topo)) {
        fila_insere(saida, topo);
    }
    pilha_libera(ops);
}

int avalia(Fila *posfixa) {
    Pilha *val = pilha_cria();
    if (val == NULL) {
        return 0;
    }
    int t, a = 0, b = 0;
    while (fila_retira(posfixa, &t)) {
        printf("%c ", t);
        if (t >= '0' && t <= '9') {
            pilha_empilha(val, t - '0');
        } else {
            pilha_desempilha(val, &b);
            pilha_desempilha(val, &a);
            pilha_empilha(val, t == '+' ? a + b : t == '-' ? a - b : t == '*' ? a * b : a / b);
        }
    }
    int r = 0;
    pilha_desempilha(val, &r);
    pilha_libera(val);
    return r;
}

int main(void) {
    const char *contas[] = {"2+3*4", "8-3-2", "9/3/3"};
    for (int i = 0; i < 3; i++) {
        Fila *f = fila_cria();
        if (f == NULL) {
            return 1;
        }
        printf("%s -> ", contas[i]);
        converte(contas[i], f);
        int r = avalia(f);
        printf("= %d\n", r);
        fila_libera(f);
    }
    return 0;
}
