// A294 · A trie ordena e acha o prefixo comum

#include <stdio.h>
#include "trie.h"

// quantos filhos o nó tem e, em *unico, o índice do último achado
int filhos(const NoTrie *n, int *unico) {
    int qtd = 0;
    for (int i = 0; i < TRIE_LETRAS; i++) {
        if (n->filho[i] != NULL) {
            qtd++;
            *unico = i;
        }
    }
    return qtd;
}

// maior prefixo comum a TODAS as palavras: desce enquanto o caminho não se
// divide (um filho só) e nenhuma palavra termina no meio do caminho
void prefixo_comum(const NoTrie *r, char saida[]) {
    int k = 0, i = 0;
    while (!r->fim && filhos(r, &i) == 1 && k < TRIE_MAX - 1) {
        saida[k++] = (char)('a' + i);
        r = r->filho[i];
    }
    saida[k] = '\0';
}

int main(void) {
    const char *obra[] = {"pedreiro", "pedra", "pedregulho", "pedrada", "pedrisco"};
    NoTrie *t = trie_cria();
    for (int i = 0; i < 5; i++) {
        trie_insere(t, obra[i]);
    }

    printf("Em ordem alfabética:");
    trie_autocompleta(t, "", 100); // prefixo vazio: a trie inteira
    char pc[TRIE_MAX];
    prefixo_comum(t, pc);
    printf("\nPrefixo comum: \"%s\"\n", pc);

    trie_insere(t, "pe"); // uma palavra curta corta o prefixo comum
    prefixo_comum(t, pc);
    printf("Com \"pe\" no dicionário: \"%s\"\n", pc);

    trie_insere(t, "areia"); // outra letra inicial: não sobra prefixo
    prefixo_comum(t, pc);
    printf("Com \"areia\" também: \"%s\"\n", pc);

    trie_libera(t);
    return 0;
}
// Saída:
// Em ordem alfabética: pedra pedrada pedregulho pedreiro pedrisco
// Prefixo comum: "pedr"
// Com "pe" no dicionário: "pe"
// Com "areia" também: ""
