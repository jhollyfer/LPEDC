// 0089 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E534 · ★★★

#include <stdio.h>
#include <string.h>
// Na pasta do assunto basta #include "pilha.h" (o rodar compila o pilha.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0089-pilha-aplicacoes/pilha.c"

enum { OK, FALTA_OPERANDO, DIVISAO_POR_ZERO, SOBROU_NUMERO, SIMBOLO_INVALIDO };

// devolve um dos códigos acima; em SIMBOLO_INVALIDO, guarda o símbolo em *ruim
int avalia(const char *linha, int *resultado, char *ruim) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return FALTA_OPERANDO;
    }
    int codigo = OK;
    for (int i = 0; linha[i] != '\0' && codigo == OK; i++) {
        char c = linha[i];
        if (c >= '0' && c <= '9') {
            int numero = 0;
            while (linha[i] >= '0' && linha[i] <= '9') {
                numero = numero * 10 + (linha[i] - '0');
                i++;
            }
            i--;
            pilha_empilha(p, numero);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int a, b;
            if (!pilha_desempilha(p, &b) || !pilha_desempilha(p, &a)) {
                codigo = FALTA_OPERANDO;
            } else if (c == '/' && b == 0) {
                codigo = DIVISAO_POR_ZERO;
            } else {
                pilha_empilha(p, c == '+' ? a + b : c == '-' ? a - b : c == '*' ? a * b : a / b);
            }
        } else if (c != ' ' && c != '\n') {
            *ruim = c;
            codigo = SIMBOLO_INVALIDO;
        }
    }
    if (codigo == OK) {
        if (!pilha_desempilha(p, resultado)) {
            codigo = FALTA_OPERANDO;
        } else if (!pilha_vazia(p)) {
            codigo = SOBROU_NUMERO;
        }
    }
    pilha_libera(p);
    return codigo;
}

int main(void) {
    char linha[128];
    while (fgets(linha, sizeof linha, stdin) != NULL) {
        if (linha[strspn(linha, " \n")] == '\0') {
            continue; // linha vazia
        }
        int resultado = 0;
        char ruim = '?';
        switch (avalia(linha, &resultado, &ruim)) {
            case OK:
                printf("= %d\n", resultado);
                break;
            case FALTA_OPERANDO:
                printf("erro: falta operando\n");
                break;
            case DIVISAO_POR_ZERO:
                printf("erro: divisão por zero\n");
                break;
            case SOBROU_NUMERO:
                printf("erro: sobrou número na pilha\n");
                break;
            default:
                printf("erro: símbolo inválido '%c'\n", ruim);
        }
    }
    return 0;
}
