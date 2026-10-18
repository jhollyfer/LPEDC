// 0149 · Juntando tudo
// Exercício E891 · ★★☆

#include <stdio.h>
#include <string.h>
#include "corretor.h"

// mostra até *falta palavras da subárvore de n, em ordem alfabética
void lista(const NoC *n, char buf[], int nivel, int *falta) {
    if (*falta == 0) {
        return;
    }
    if (n->fim) {
        buf[nivel] = '\0';
        printf(" %s", buf);
        (*falta)--;
    }
    for (int i = 0; i < COR_LETRAS && nivel < COR_MAX - 1; i++) {
        if (n->filho[i] != NULL) {
            buf[nivel] = (char)('a' + i);
            lista(n->filho[i], buf, nivel + 1, falta);
        }
    }
}

// desce enquanto as letras da palavra existirem na trie e sugere as
// palavras que ficam embaixo do nó mais fundo (o maior prefixo em comum)
void pelo_prefixo(const NoC *d, const char *palavra, int max) {
    char buf[COR_MAX];
    int k = 0;
    while (palavra[k] != '\0' && k < COR_MAX - 1 && d->filho[palavra[k] - 'a'] != NULL) {
        buf[k] = palavra[k];
        d = d->filho[palavra[k] - 'a'];
        k++;
    }
    buf[k] = '\0';
    printf("%s: prefixo \"%s\" |", palavra, buf);
    if (k == 0) {
        printf(" nenhuma\n");
        return;
    }
    int falta = max;
    lista(d, buf, k, &falta);
    printf("\n");
}

int main(void) {
    NoC *dic = cor_cria();
    cor_carrega_basico(dic);
    const char *testes[] = {"esquina", "cafezinho", "mercadinho", "portaria", "xis"};
    for (int i = 0; i < 5; i++) {
        pelo_prefixo(dic, testes[i], 3);
    }
    cor_libera(dic);
    return 0;
}
