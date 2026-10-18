// 0147 · Trie
// Exercício E879 · ★★☆
//
// Conte quantas vezes cada palavra aparece num texto usando uma trie em que
// o nó guarda um contador (int qtd) no lugar do bool fim. O struct e o main
// já estão prontos; escreva:
// - conta(r, p, tam): soma 1 na palavra de tam letras que começa em p
//  (o texto não tem '\0' depois de cada palavra, por isso o tam);
// - lista(n, buf, nivel, &distintas): mostra as palavras em ordem alfabética
//  com a contagem e conta quantas palavras diferentes existem;
// - libera(n).
//
//   Saída esperada:
//   a      1
//   da     1
//   de     1
//   do     1
//   o      2
//   rato   1
//   rei    2
//   riu    1
//   roeu   1
//   roma   1
//   roupa  2
//   14 palavras, 11 diferentes
//
// Dicas:
// 1. conta é a trie_insere do TAD com duas mudanças: o laço vai de 0 a
//    tam - 1 e, no fim, r->qtd++ em vez de r->fim = true.
// 2. lista é a coleta do trie.c: se n->qtd > 0, termine buf com '\0' na
//    posição nivel e imprima com printf("%-6s %d\n", buf, n->qtd).
// 3. Resposta esperada: a saída acima. Repare que a ordem alfabética sai de
//    graça: os filhos são visitados de 'a' a 'z'.
//
// Escreva sua resposta abaixo (escreva conta, lista e libera):

#include <stdio.h>
#include <stdlib.h>

typedef struct NoFreq {
    struct NoFreq *filho[26];
    int qtd; // quantas vezes a palavra que termina aqui apareceu (0: nenhuma)
} NoFreq;

NoFreq *novo(void) {
    NoFreq *n = calloc(1, sizeof(NoFreq));
    if (n == NULL) {
        exit(1);
    }
    return n;
}

int main(void) {
    const char *texto = "o rato roeu a roupa do rei de roma o rei riu da roupa";
    NoFreq *r = novo();
    int total = 0;
    int i = 0;
    while (texto[i] != '\0') {
        if (texto[i] == ' ') {
            i++;
            continue;
        }
        int ini = i;
        while (texto[i] >= 'a' && texto[i] <= 'z') {
            i++;
        }
        // conta(r, texto + ini, i - ini);
        (void)ini; // apague esta linha
        total++;
    }
    printf("%d palavras\n", total); // troque pela lista e pelas diferentes

    free(r); // troque por libera(r)
    return 0;
}
