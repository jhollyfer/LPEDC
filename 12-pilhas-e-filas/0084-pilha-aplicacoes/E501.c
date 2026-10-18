// 0084 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E501 · ★★☆
//
// Este verificador é mais educado que o do texto: além de dizer que deu
// errado, diz onde. Melhore ainda mais: em vez de empilhar o caractere,
// empilhe a POSIÇÃO dele na string (o caractere você recupera com s[pos]).
// Assim as mensagens também podem dizer onde a abertura estava. A primeira
// posição da string é 0.
//
//   Saída esperada:
//   [1, (2, 3)]: ok
//   {a: [1, 2}]: esperava ] e veio } na posição 9 (o [ abriu na posição 4)
//   f(x)): fecha sem abrir na posição 4
//   if (a[0] {: faltou fechar 2; o de cima é o { da posição 9
//
// Dicas:
// 1. pilha_empilha(p, i) no lugar de pilha_empilha(p, c).
// 2. Ao desempilhar, a abertura é s[topo], e topo é a posição dela.
// 3. No "faltou fechar", use pilha_topo para pegar a última abertura.
// 4. Resposta esperada: as quatro linhas acima.
//
// Escreva sua resposta abaixo (modifique diagnostico):

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
