## 0147 · Trie: árvore de prefixos e autocompletar

- **Trie** (de *retrieval*) ou **árvore de prefixos**: cada aresta **é** uma
  letra, e o caminho da raiz até um nó soletra um prefixo. As palavras com esse
  prefixo moram embaixo dele (FREDKIN, 1960).
- **Marca de fim**: o prefixo "bol" tem nó, mas não é palavra. Cada nó guarda um
  `bool fim` que diz se alguma palavra **termina** ali (ZIVIANI, 2010, cap. 5).
- **Nó com vetor**: com minúsculas sem acento, o nó tem 26 ponteiros, e o filho
  da letra `c` fica em `filho[c - 'a']` (CORTÉS, 2015).
- **Inserir**: desça pelo filho de cada letra, criando-o se faltar; no fim,
  `fim = true`. **Buscar**: desça letra por letra; faltou filho, não existe; no
  fim, vale o `fim` do nó.
- **Autocompletar**: desça até o nó do prefixo e percorra a subárvore, de `a` a
  `z`, imprimindo cada caminho que termina num `fim`.
- **Custo**: inserir e buscar custam **O(L)**, L o tamanho da palavra, sem
  depender de quantas há. Uma BST de 100 mil palavras faz umas 17 comparações de
  strings (SEDGEWICK; WAYNE, 2011).
- **Memória**: cada `NoTrie` tem 216 bytes, quase todos ponteiros `NULL`. Lista
  de filhos (0144) ou árvore ternária gastam menos.

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
