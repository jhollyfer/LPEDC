// 0084 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E500 · ★☆☆
//
// Com tipos diferentes, o contador só sabe QUANTOS estão abertos, não QUAL
// foi o último a abrir. Em "( [ ) ]" ele chega a 0 no fim e diz ok.

#include <stdbool.h>
#include <stdio.h>

bool parenteses_ok(const char *s) {
    int abertos = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            abertos++;
        } else if (s[i] == ')') {
            abertos--;
            if (abertos < 0) {
                return false; // fechou sem abrir
            }
        }
    }
    return abertos == 0;
}

int main(void) {
    const char *testes[] = {"(a+(b*c))", "(a+b))(", ")(", "((x)"};
    for (int i = 0; i < 4; i++) {
        printf("%-10s %s\n", testes[i], parenteses_ok(testes[i]) ? "ok" : "erro");
    }
    return 0;
}
