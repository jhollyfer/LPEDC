## 0147 · Trie: árvore de prefixos e autocompletar

Você digita `bol` e o teclado oferece "bola", "boleto", "bolo" e "bolsa" sem
comparar com o dicionário inteiro: nele, **o prefixo é o endereço**.

Esse modo é a **trie** (de *retrieval*; ou **árvore de prefixos**). Cada nó tem
um filho por letra, e cada aresta **é** uma letra. O caminho da raiz até um nó
soletra um prefixo: raiz, `b`, `o`, `l` é o nó de "bol", e as palavras que
começam com "bol" moram embaixo dele.

"bol" tem nó, mas não é palavra. Por isso cada nó guarda um `bool fim`, que diz
se alguma palavra **termina** ali: "bolo" termina no `o` depois do `l`.

Com letras minúsculas sem acento, o nó é um vetor de 26 ponteiros, e o filho da
letra `c` fica em `filho[c - 'a']`.

- **inserir**: desça pelo filho de cada letra, criando-o se faltar; no fim,
  `fim = true`;
- **buscar**: desça letra por letra; faltou um filho, a palavra não existe; no
  fim do texto, a resposta é o `fim` do nó;
- **autocompletar**: desça até o nó do prefixo e percorra a subárvore dele,
  imprimindo cada caminho que termina num `fim`.

Inserir e buscar custam **O(L)**, com L o tamanho da palavra, **sem depender do
número de palavras**: "bolsa" desce 5 nós com 10 ou com 100 mil palavras. Numa
BST de 100 mil palavras, seriam umas 17 comparações de strings.

O teclado do exemplo guarda bolo, bola, bolsa, boleto, bom, bombom, pão e
pastel (sem acento: `pao`). No ramo do `b`, o caminho verde é o prefixo "bol";
os nós verdes marcam o fim de uma palavra:

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

As sugestões saem em ordem alfabética porque a subárvore é percorrida de `a` a
`z`.

O fluxograma mostra a inserção de "bom". O `b` e o `o` já existem; o `m` é novo
e recebe `fim = true`:

{{fluxograma}}

> [!WARNING]
> Achar o nó não é achar a palavra: `trie_prefixo(t, "bol")` devolve um nó, mas
> a busca precisa olhar o `fim` (`return n != NULL && n->fim;`). Esquecer o
> `r->fim = true` na inserção faz a palavra sumir. No índice, `'B' - 'a'` dá -31 e `'ã'` não é um `char` só em UTF-8;
> por isso `trie_insere` recusa o que não for de `'a'` a `'z'`.

> [!TIP]
> Cada `NoTrie` tem 216 bytes. As 8 palavras cabem em 45 bytes como strings, mas
> a trie usa 22 nós, 4752 bytes, quase todos ponteiros `NULL`. Alternativas:
> lista de filhos (0144) ou BST por nó (árvore ternária).

> [!NOTE]
> **Pergunta para você:** se você inserir "bolota", quantos nós novos aparecem?
> E se inserir "bo"? Em cada caso, o que muda nas sugestões para "bo"? Responda
> antes de acrescentar as palavras no vetor do exemplo.

{{pratique}}
