// A287 · O sumário numerado da apostila

#include <stdio.h>
#include "arvgen.h"

// numera como num sumário: o número de um nó é o do pai + a posição dele
// entre os irmãos (1, 2, 3...). O prefixo vai crescendo na descida.
void sumario(const NoG *r, const char *prefixo) {
    int pos = 1;
    for (const NoG *p = r->filho; p != NULL; p = p->irmao, pos++) {
        char numero[32];
        if (prefixo[0] == '\0') {
            snprintf(numero, sizeof numero, "%d", pos);
        } else {
            snprintf(numero, sizeof numero, "%s.%d", prefixo, pos);
        }
        if (p->filho == NULL) {
            printf("%-6s %-14s %3d pág.\n", numero, p->nome, p->valor);
        } else {
            printf("%-6s %-14s %3d pág. no total\n", numero, p->nome, ag_total(p));
        }
        sumario(p, numero); // os filhos de p herdam o número dele
    }
}

int main(void) {
    NoG *apostila = ag_cria("apostila", 0);
    NoG *c1 = ag_adiciona(apostila, "Fundamentos", 0);
    ag_adiciona(c1, "Algoritmos", 6);
    ag_adiciona(c1, "Tipos", 9);
    NoG *c2 = ag_adiciona(apostila, "Condicionais", 0);
    ag_adiciona(c2, "if e else", 8);
    NoG *sw = ag_adiciona(c2, "switch", 0);
    ag_adiciona(sw, "case", 4);
    ag_adiciona(sw, "break", 3);
    ag_adiciona(apostila, "Projetos", 15); // capítulo sem seções: é folha

    sumario(apostila, "");
    printf("Total: %d páginas em %d capítulos\n", ag_total(apostila), ag_grau(apostila));

    ag_libera(apostila);
    return 0;
}
// Saída:
// 1      Fundamentos     15 pág. no total
// 1.1    Algoritmos       6 pág.
// 1.2    Tipos            9 pág.
// 2      Condicionais    15 pág. no total
// 2.1    if e else        8 pág.
// 2.2    switch           7 pág. no total
// 2.2.1  case             4 pág.
// 2.2.2  break            3 pág.
// 3      Projetos        15 pág.
// Total: 45 páginas em 3 capítulos
