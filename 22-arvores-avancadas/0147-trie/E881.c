// 0147 · Trie
// Exercício E881 · ★★★
//
// Ache o bug. O teclado do celular sugere palavras com a função sugere(),
// escrita à mão sobre o struct do trie.h. Para o prefixo "bol", ela deveria
// mostrar bola, boleto, bolo e bolsa, mas mostra palavras que nem existem:
//
//   Saída que aparece:
//   bol: bola boleto boloto bolsao
//   bo: bola boleto boloto bolsao bomsao bombom
//
//   Saída esperada:
//   bol: bola boleto bolo bolsa
//   bo: bola boleto bolo bolsa bom bombom
//
// Não há erro de memória: o programa roda limpo e mesmo assim erra. Ache a
// linha que falta, conserte e rode de novo.
//
// Dicas:
// 1. Acompanhe o conteúdo de buf: depois de imprimir "boleto", a recursão
//    volta para o nível 3 e escreve 'o' em buf[3]. O que ainda está em
//    buf[4] e buf[5]?
// 2. O buffer começou zerado, por isso "bola" e "boleto" saíram certas: o
//    '\0' que as termina estava lá por acaso.
// 3. Resposta esperada: falta "buf[nivel] = '\0';" logo antes do printf, em
//    sugere. Cada palavra precisa ser fechada no comprimento dela, e não
//    no da maior palavra que passou antes pelo buffer.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>
#include "trie.h"

void junta(const NoTrie *n, char buf[], int nivel) {
    if (n->fim) {
        printf(" %s", buf);
    }
    for (int i = 0; i < TRIE_LETRAS; i++) {
        if (n->filho[i] != NULL) {
            buf[nivel] = (char)('a' + i);
            junta(n->filho[i], buf, nivel + 1);
        }
    }
}

void sugere(const NoTrie *r, const char *prefixo) {
    char buf[TRIE_MAX] = {0}; // tudo zerado
    strcpy(buf, prefixo);
    printf("%s:", prefixo);
    const NoTrie *n = trie_prefixo(r, prefixo);
    if (n != NULL) {
        junta(n, buf, (int)strlen(prefixo));
    }
    printf("\n");
}

int main(void) {
    const char *palavras[] = {"bolo", "bola", "bolsa", "boleto", "bom", "bombom"};
    NoTrie *t = trie_cria();
    for (int i = 0; i < 6; i++) {
        trie_insere(t, palavras[i]);
    }
    sugere(t, "bol");
    sugere(t, "bo");
    trie_libera(t);
    return 0;
}
