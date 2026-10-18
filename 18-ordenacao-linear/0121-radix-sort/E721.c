// 0121 · Radix sort
// Exercício E721 · ★☆☆
//
// As duas perguntas que o radix sort faz o tempo todo são "quantos dígitos
// tem o maior número?" (quantas passadas) e "qual é o dígito desta casa?".
// Escreva as duas funções, só com divisão e resto por 10 (sem pow):
//
// - int quantos_digitos(int x): 5082 tem 4, 7 tem 1;
//
// - int digito(int x, int pos): pos 0 é a unidade, 1 a dezena, e assim por
// diante. digito(5082, 1) é 8.
//
// O main já mostra a tabela para quatro números.
//
//   Saída esperada:
//   5082: 4 dígitos; unidade 2, dezena 8, centena 0, milhar 5
//   7: 1 dígito; unidade 7
//   340: 3 dígitos; unidade 0, dezena 4, centena 3
//   19000: 5 dígitos; unidade 0, dezena 0, centena 0, milhar 9, dezena de milhar 1
//
// Dicas:
// 1. quantos_digitos: comece com 1 e divida por 10 enquanto x >= 10.
//    Cuidado com o 0, que tem 1 dígito.
// 2. digito: divida x por 10, pos vezes, e devolva x % 10.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (escreva as duas funções):

#include <stdio.h>

int quantos_digitos(int x) {
    (void) x; // apague esta linha
    return 1;
}

int digito(int x, int pos) {
    (void) x; // apague estas duas linhas
    (void) pos;
    return 0;
}

int main(void) {
    int numeros[] = {5082, 7, 340, 19000};
    const char *casas[] = {"unidade", "dezena", "centena", "milhar", "dezena de milhar"};
    for (int i = 0; i < 4; i++) {
        int d = quantos_digitos(numeros[i]);
        printf("%d: %d dígito%s;", numeros[i], d, d > 1 ? "s" : "");
        for (int pos = 0; pos < d; pos++) {
            printf(" %s %d%s", casas[pos], digito(numeros[i], pos), pos < d - 1 ? "," : "\n");
        }
    }
    return 0;
}
