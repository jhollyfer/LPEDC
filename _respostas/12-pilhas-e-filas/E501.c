// 0084 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E501 · ★★☆

#include <stdio.h>
// Na pasta do assunto basta #include "pilha.h" (o rodar compila o pilha.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0084-pilha-aplicacoes/pilha.c"

char fechamento_de(int abre) {
    if (abre == '(') {
        return ')';
    }
    if (abre == '[') {
        return ']';
    }
    return '}';
}

void diagnostico(const char *s) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return;
    }
    printf("%s: ", s);
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            pilha_empilha(p, i); // a posição, não o caractere
        } else if (c == ')' || c == ']' || c == '}') {
            int topo;
            if (!pilha_desempilha(p, &topo)) {
                printf("fecha sem abrir na posição %d\n", i);
                pilha_libera(p);
                return;
            }
            if (fechamento_de(s[topo]) != c) {
                printf("esperava %c e veio %c na posição %d (o %c abriu na posição %d)\n",
                       fechamento_de(s[topo]), c, i, s[topo], topo);
                pilha_libera(p);
                return;
            }
        }
    }
    if (pilha_vazia(p)) {
        printf("ok\n");
    } else {
        int topo = 0;
        pilha_topo(p, &topo);
        printf("faltou fechar %d; o de cima é o %c da posição %d\n", pilha_tamanho(p), s[topo], topo);
    }
    pilha_libera(p);
}

int main(void) {
    diagnostico("[1, (2, 3)]");
    diagnostico("{a: [1, 2}]");
    diagnostico("f(x))");
    diagnostico("if (a[0] {");
    return 0;
}
