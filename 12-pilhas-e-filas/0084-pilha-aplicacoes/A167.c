// A167 · Parênteses dentro de aspas não contam

#include <stdbool.h>
#include <stdio.h>
#include "pilha.h"

char abertura_de(char fecha) {
    return fecha == ')' ? '(' : fecha == ']' ? '[' : '{';
}

// Confere uma linha de código C. Com pula_aspas, o que está entre "..." ou
// '...' é texto, não código: um ')' dentro de aspas não fecha nada.
bool balanceada(const char *s, bool pula_aspas) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return false;
    }
    bool ok = true;
    char aspa = '\0'; // '\0' = fora de aspas; senão, a aspa que abriu
    for (int i = 0; s[i] != '\0' && ok; i++) {
        char c = s[i];
        if (aspa != '\0') {
            if (c == '\\' && s[i + 1] != '\0') {
                i++; // \" ou \' não fecham a aspa: pula o caractere seguinte
            } else if (c == aspa) {
                aspa = '\0'; // fechou o texto
            }
        } else if (pula_aspas && (c == '"' || c == '\'')) {
            aspa = c; // começou um texto
        } else if (c == '(' || c == '[' || c == '{') {
            pilha_empilha(p, c);
        } else if (c == ')' || c == ']' || c == '}') {
            int topo;
            if (!pilha_desempilha(p, &topo) || topo != abertura_de(c)) {
                ok = false;
            }
        }
    }
    if (!pilha_vazia(p) || aspa != '\0') {
        ok = false; // sobrou abertura, ou uma aspa ficou aberta
    }
    pilha_libera(p);
    return ok;
}

int main(void) {
    const char *linhas[] = {
        "if (c == ')') { n++; }",
        "printf(\"[%d]\\n\", v[i]);",
        "puts(\"sorriso :)\");",
        "v[(i + 1] = 0;",
    };
    printf("%-28s %-10s %s\n", "linha", "simples", "pulando aspas");
    for (int i = 0; i < 4; i++) {
        printf("%-28s %-10s %s\n", linhas[i],
               balanceada(linhas[i], false) ? "ok" : "erro",
               balanceada(linhas[i], true) ? "ok" : "erro");
    }
    return 0;
}
// Saída:
// linha                        simples    pulando aspas
// if (c == ')') { n++; }       erro       ok
// printf("[%d]\n", v[i]);      ok         ok
// puts("sorriso :)");          erro       ok
// v[(i + 1] = 0;               erro       erro
