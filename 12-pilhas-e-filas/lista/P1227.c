// Lista · Módulo 12 · Pilhas e filas
// Exercício P1227 · ★★★ · O verificador de fórmulas com três defeitos
//
// O verificador de delimitadores abaixo foi escrito às pressas. Ele compila
// sem aviso, mas tem TRÊS erros de propósito: recusa uma fórmula certa,
// aceita uma errada e, numa terceira, o sanitizer acusa
// "stack-buffer-underflow" (leitura antes do começo do vetor). Conserte os
// três. Rode, compare com a saída esperada e use cada fórmula como teste de
// um caso: abrir, fechar, sobrar, faltar.
//
//   Saída esperada:
//   {[()]}: ok
//   ([)]: erro
//   ((: erro
//   ()): erro
//   a[b{c}d]e: ok
//
// Dicas:
// 1. Qual fórmula é recusada sem motivo? Que fechamento dela dá problema?
//    Confira a função par, caso por caso.
// 2. Em "((", o laço termina sem nenhum erro. O que a pilha ainda tem? Uma
//    fórmula certa termina com a pilha como?
// 3. Em "())", o segundo ')' chega com a pilha vazia. O que o código lê?
// 4. Resposta esperada: par(']') deve devolver '[' (não '{'); o return
//    final deve ser n == 0; e o fechamento deve testar n == 0 (devolvendo
//    false) antes de olhar pilha[n - 1].
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

char par(char fecha) {
    if (fecha == ')') {
        return '(';
    }
    if (fecha == ']') {
        return '{';
    }
    return '{';
}

bool balanceado(const char *s) {
    char pilha[100];
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            if (n == 100) {
                return false;
            }
            pilha[n++] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (pilha[n - 1] != par(c)) {
                return false;
            }
            n--;
        }
    }
    return true;
}

int main(void) {
    const char *formulas[5] = {"{[()]}", "([)]", "((", "())", "a[b{c}d]e"};
    for (int i = 0; i < 5; i++) {
        printf("%s: %s\n", formulas[i], balanceado(formulas[i]) ? "ok" : "erro");
    }
    return 0;
}
