// 0069 · Argumentos da linha de comando
// Exercício E414 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// converte o texto em double; devolve 1 se deu certo
int ler_numero(const char *texto, double *saida) {
    char *fim;
    *saida = strtod(texto, &fim);
    return fim != texto && *fim == '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <número> <+ - x /> <número>\n", argv[0]);
        return 1;
    }
    double a, b;
    if (!ler_numero(argv[1], &a) || !ler_numero(argv[3], &b)) {
        fprintf(stderr, "Erro: número inválido\n");
        return 1;
    }
    if (strlen(argv[2]) != 1) {
        fprintf(stderr, "Erro: operador \"%s\" desconhecido (use + - x /)\n", argv[2]);
        return 1;
    }

    char op = argv[2][0];
    double resultado;
    switch (op) {
    case '+':
        resultado = a + b;
        break;
    case '-':
        resultado = a - b;
        break;
    case 'x':
    case '*':
        resultado = a * b;
        break;
    case '/':
        if (b == 0) {
            fprintf(stderr, "Erro: divisão por zero\n");
            return 1;
        }
        resultado = a / b;
        break;
    default:
        fprintf(stderr, "Erro: operador \"%s\" desconhecido (use + - x /)\n", argv[2]);
        return 1;
    }
    printf("%.2f %c %.2f = %.2f\n", a, op, b, resultado);
    return 0;
}
