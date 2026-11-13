## 0147 · Trie: árvore de prefixos e autocompletar

Você digita `bol` no celular e o teclado oferece "bola", "boleto", "bolo" e
"bolsa" na hora. Ele não compara `bol` com cada uma das milhares de palavras
do dicionário. Ele vai direto ao lugar onde moram as palavras que começam
com `bol`, como quem abre um dicionário de papel na letra B, depois no
pedaço "bo", depois em "bol". Na estrutura que ele usa, **o prefixo é o
endereço**.

Essa estrutura é a **trie**, nome tirado de *retrieval* (recuperação),
também chamada **árvore de prefixos**. Cada aresta da árvore **é** uma
letra, e o caminho da raiz até um nó soletra um prefixo. Da raiz, a aresta
`b` leva ao nó de "b"; dele, a aresta `o` leva ao nó de "bo"; dele, a `l`
leva ao nó de "bol". Todas as palavras que começam com "bol" moram na
subárvore desse nó (FREDKIN, 1960).

Note que os nós não guardam palavras inteiras. A palavra está espalhada no
caminho, uma letra por aresta. Isso cria uma dúvida: o nó de "bol" existe,
porque "bolo" passa por ele, mas "bol" não é uma palavra. Para separar os
dois casos, cada nó guarda um `bool fim`, verdadeiro quando alguma palavra
**termina** ali (ZIVIANI, 2010, cap. 5). O nó do `o` depois de "bol" tem `fim`
verdadeiro, porque "bolo" é palavra; o nó de "bol" tem `fim` falso.

Como achar o filho de uma letra? Com letras minúsculas sem acento, cada nó
tem um vetor de 26 ponteiros, um por letra. O filho da letra `c` fica em
`filho[c - 'a']`: a conta transforma `'a'` em 0, `'b'` em 1, e assim até
`'z'` em 25 (CORTÉS, 2015). Ponteiro `NULL` quer dizer que nenhuma palavra
segue por aquela letra.

Com isso, as operações são curtas. Para **inserir** uma palavra, desça
letra por letra pelo filho correspondente; se o filho não existe, crie-o.
Ao fim da palavra, marque `fim = true` no nó onde você parou. Para
**buscar**, desça do mesmo jeito; se faltar um filho no meio, a palavra não
existe. Se chegar ao fim do texto, a resposta é o `fim` daquele nó (ZIVIANI,
2010, cap. 5).

O **autocompletar** junta as duas ideias. Desça até o nó do prefixo
digitado. Depois percorra toda a subárvore dele, filho por filho, de `a` a
`z`, montando as letras do caminho; cada vez que encontrar um nó com `fim`
verdadeiro, imprima a palavra montada. Como os filhos são visitados em
ordem alfabética, as sugestões já saem ordenadas.

O custo é a grande vantagem. Inserir e buscar custam **O(L)**, com L o
tamanho da palavra, e **não dependem de quantas palavras** existem: "bolsa"
desce 5 nós num dicionário de 10 palavras ou de 100 mil. Uma BST com 100 mil
palavras faria umas 17 comparações de strings, cada uma podendo olhar várias
letras (SEDGEWICK; WAYNE, 2011).

O preço é memória. Cada nó com 26 ponteiros e o `fim` ocupa 216 bytes, e
quase todos os ponteiros são `NULL`, porque poucas letras seguem cada
prefixo. Oito palavras curtas cabem em 45 bytes como strings e, numa trie,
ocupam 22 nós, quase 5 KB. Guardar os filhos numa lista, como no primeiro
filho, próximo irmão (0144), ou numa BST por nó, a árvore ternária, gasta
bem menos, ao custo de achar o filho com mais passos.

> [!WARNING]
> Achar o nó não é achar a palavra: a busca olha o `fim`
> (`return n != NULL && n->fim;`). E o índice só vale de `'a'` a `'z'`:
> `'B' - 'a'` dá -31 e `'ã'` não é um `char` só em UTF-8.

{{exemplo}}

Um teclado guarda bolo, bola, bolsa, boleto, bom, bombom, pão e pastel (sem
acento: `pao`). No ramo do `b`, o caminho verde é o prefixo "bol"; os nós verdes
marcam o fim de uma palavra:

{{ideia}}

O nó e a inserção, em `trie.c` (o `calloc` deixa os ponteiros `NULL` e `fim`
falso):

```c
typedef struct NoTrie {
    struct NoTrie *filho[TRIE_LETRAS]; // filho['c' - 'a'] segue a letra c
    bool fim;                          // uma palavra termina aqui?
} NoTrie;

bool trie_insere(NoTrie *r, const char *palavra) {
    for (const char *p = palavra; *p != '\0'; p++) { // confere antes de mexer
        if (*p < 'a' || *p > 'z') {
            return false;
        }
    }
    for (; *palavra != '\0'; palavra++) {
        int i = *palavra - 'a';
        if (r->filho[i] == NULL) {
            r->filho[i] = trie_cria(); // o caminho ainda não existe: cria
        }
        r = r->filho[i];
    }
    r->fim = true; // marca o fim da palavra
    return true;
}
```

O cliente monta o dicionário e testa três textos:

```c
#include <stdio.h>
#include "trie.h"

int main(void) {
    const char *dicionario[] = {"bolo", "bola", "bolsa", "boleto", "bom", "bombom", "pao", "pastel"};
    NoTrie *teclado = trie_cria();
    for (int i = 0; i < 8; i++) {
        trie_insere(teclado, dicionario[i]);
    }

    const char *testes[] = {"bol", "bom", "pa"};
    for (int i = 0; i < 3; i++) {
        printf("\"%s\": palavra? %s | sugestões:", testes[i],
               trie_busca(teclado, testes[i]) ? "sim" : "não");
        trie_autocompleta(teclado, testes[i], 4);
        printf("\n");
    }
    printf("Nós: %d (%zu bytes cada)\n", trie_nos(teclado), sizeof(NoTrie));

    trie_libera(teclado);
    return 0;
}
// Saída:
// "bol": palavra? não | sugestões: bola boleto bolo bolsa
// "bom": palavra? sim | sugestões: bom bombom
// "pa": palavra? não | sugestões: pao pastel
// Nós: 22 (216 bytes cada)
```

O fluxograma mostra a inserção de "bom". O `b` e o `o` já existem; o `m` é novo
e recebe `fim = true`:

{{fluxograma}}
