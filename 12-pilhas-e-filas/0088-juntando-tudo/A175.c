// A175 · A calculadora que explica o erro

#include <stdio.h>
#include "fila.h"
#include "pilha.h"

enum { SOMA = -1, SUB = -2, MULT = -3, DIV = -4, ABRE = -5 };

// códigos de erro: cada etapa descobre os seus
enum { OK, FECHA_SEM_ABRIR, FALTOU_FECHAR, FALTA_OPERANDO, DIV_ZERO, SOBROU_NUMERO, SEM_MEMORIA };

const char *mensagem[] = {
    "ok", "')' sem '(' antes", "'(' sem ')' depois",
    "falta operando", "divisão por zero", "sobrou número", "faltou memória",
};

int precedencia(int op) {
    return (op == MULT || op == DIV) ? 2 : (op == SOMA || op == SUB) ? 1 : 0;
}

// Etapa 1. Os erros de parêntese só aparecem aqui: na fila pós-fixa não
// existe parêntese nenhum, e um ABRE perdido lá dentro viraria lixo na conta.
int converte(const char *s, Fila *saida) {
    Pilha *ops = pilha_cria();
    if (ops == NULL) {
        return SEM_MEMORIA;
    }
    int erro = OK;
    int topo;
    for (int i = 0; s[i] != '\0' && erro == OK; i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            int numero = 0;
            for (; s[i] >= '0' && s[i] <= '9'; i++) {
                numero = numero * 10 + (s[i] - '0');
            }
            i--;
            fila_insere(saida, numero);
        } else if (c == '(') {
            pilha_empilha(ops, ABRE);
        } else if (c == ')') {
            topo = 0; // se a pilha já estiver vazia, topo não pode ficar com lixo
            while (pilha_desempilha(ops, &topo) && topo != ABRE) {
                fila_insere(saida, topo);
            }
            if (topo != ABRE) {
                erro = FECHA_SEM_ABRIR; // a pilha acabou antes de achar o '('
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int op = c == '+' ? SOMA : c == '-' ? SUB : c == '*' ? MULT : DIV;
            while (pilha_topo(ops, &topo) && precedencia(topo) >= precedencia(op)) {
                pilha_desempilha(ops, &topo);
                fila_insere(saida, topo);
            }
            pilha_empilha(ops, op);
        }
    }
    while (erro == OK && pilha_desempilha(ops, &topo)) {
        if (topo == ABRE) {
            erro = FALTOU_FECHAR; // sobrou um '(' que ninguém fechou
        } else {
            fila_insere(saida, topo);
        }
    }
    pilha_libera(ops);
    return erro;
}

// Etapa 2. Aqui aparecem os erros de conta.
int avalia(Fila *posfixa, int *resultado) {
    Pilha *val = pilha_cria();
    if (val == NULL) {
        return SEM_MEMORIA;
    }
    int erro = OK;
    int t, a, b;
    while (erro == OK && fila_retira(posfixa, &t)) {
        if (t >= 0) {
            pilha_empilha(val, t);
        } else if (!pilha_desempilha(val, &b) || !pilha_desempilha(val, &a)) {
            erro = FALTA_OPERANDO;
        } else if (t == DIV && b == 0) {
            erro = DIV_ZERO;
        } else {
            pilha_empilha(val, t == SOMA ? a + b : t == SUB ? a - b : t == MULT ? a * b : a / b);
        }
    }
    if (erro == OK && (!pilha_desempilha(val, resultado) || !pilha_vazia(val))) {
        erro = pilha_vazia(val) ? FALTA_OPERANDO : SOBROU_NUMERO;
    }
    pilha_libera(val);
    return erro;
}

int main(void) {
    const char *contas[] = {"(10 + 2) * 3", "10 / (5 - 5)", "4 * (2 + 3", "4 + 2) * 3", "7 * + 2", "(8) 9"};
    for (int i = 0; i < 6; i++) {
        Fila *posfixa = fila_cria();
        if (posfixa == NULL) {
            return 1;
        }
        int r = 0;
        int erro = converte(contas[i], posfixa);
        if (erro == OK) {
            erro = avalia(posfixa, &r);
        }
        if (erro == OK) {
            printf("%-14s = %d\n", contas[i], r);
        } else {
            printf("%-14s erro: %s\n", contas[i], mensagem[erro]);
        }
        fila_libera(posfixa); // libera também o que sobrou na fila depois de um erro
    }
    return 0;
}
// Saída:
// (10 + 2) * 3   = 36
// 10 / (5 - 5)   erro: divisão por zero
// 4 * (2 + 3     erro: '(' sem ')' depois
// 4 + 2) * 3     erro: ')' sem '(' antes
// 7 * + 2        erro: falta operando
// (8) 9          erro: sobrou número
