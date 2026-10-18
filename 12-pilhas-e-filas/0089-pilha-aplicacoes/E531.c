// 0089 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E531 · ★★☆
//
// Este verificador é mais educado que o do A177: além de dizer que deu
// errado, diz onde e por quê. Sem rodar, preveja as quatro linhas que ele
// mostra. Atenção às posições: a primeira posição da string é 0.
//
// Dicas:
// 1. Faça uma tabela com a posição, o caractere e a pilha depois dele.
// 2. O laço para no primeiro erro; "faltou fechar" só aparece quando a
//    string acaba sem erro antes.
// 3. Resposta esperada:
//    [1, (2, 3)]: ok
//    {a: [1, 2}]: esperava ] e veio } na posição 9
//    f(x)): fecha sem abrir na posição 4
//    if (a[0] {: faltou fechar 2
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>
#include "pilha.h"

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
            pilha_empilha(p, c);
        } else if (c == ')' || c == ']' || c == '}') {
            int topo;
            if (!pilha_desempilha(p, &topo)) {
                printf("fecha sem abrir na posição %d\n", i);
                pilha_libera(p);
                return;
            }
            if (fechamento_de(topo) != c) {
                printf("esperava %c e veio %c na posição %d\n", fechamento_de(topo), c, i);
                pilha_libera(p);
                return;
            }
        }
    }
    if (pilha_vazia(p)) {
        printf("ok\n");
    } else {
        printf("faltou fechar %d\n", pilha_tamanho(p));
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
