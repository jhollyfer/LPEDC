## 0147 · Trie: árvore de prefixos e autocompletar

Você digita `bol` no celular e o teclado já oferece "bola", "boleto", "bolo" e
"bolsa". Ele não compara o que você digitou com cada palavra do dicionário,
uma por uma: são dezenas de milhares de palavras, e a sugestão aparece a cada
letra. O truque é guardar as palavras de um jeito em que **o prefixo é o
endereço**.

Esse jeito é a **trie** (do inglês *retrieval*; também chamada de **árvore de
prefixos** ou árvore digital). Cada nó tem um filho para cada letra possível, e
cada aresta **é** uma letra. O caminho da raiz até um nó soletra um prefixo:
raiz, `b`, `o`, `l` é o nó do prefixo "bol". Todas as palavras que começam com
"bol" moram embaixo dele.

Um prefixo não é necessariamente uma palavra: "bol" tem nó, mas não está no
dicionário. Por isso cada nó guarda um `bool fim`, que diz se alguma palavra
**termina** ali. "bolo" termina no `o` depois do `l`; "bom", no `m` depois do
`o`.

Com letras minúsculas sem acento, o nó é um vetor de 26 ponteiros. O filho da
letra `c` fica em `filho[c - 'a']`: a letra vira o índice, sem busca nenhuma.

- **inserir**: para cada letra, desça pelo filho dela; se ele não existir,
  crie. No fim, `fim = true`;
- **buscar**: desça letra por letra. Faltou um filho, a palavra não existe.
  Chegou ao fim do texto, a resposta é o `fim` daquele nó;
- **autocompletar**: desça até o nó do prefixo e percorra a subárvore dele,
  imprimindo cada caminho que termina num `fim`.

O custo de inserir e de buscar é **O(L)**, em que L é o tamanho da palavra, e
**não depende de quantas palavras existem**. Com 10 ou com 100 mil palavras,
buscar "bolsa" desce 5 nós. Numa BST de 100 mil palavras seriam umas 17
comparações de strings inteiras.

Vamos ver na prática. O teclado guarda oito palavras: bolo, bola, bolsa,
boleto, bom, bombom, pão e pastel (sem acento: `pao`). No desenho, o ramo do
`b`: o caminho verde é o prefixo "bol", que tem nó mas não é palavra; os nós
verdes são onde alguma palavra termina:

{{ideia}}

O nó e a inserção, no `trie.c`. O `calloc` zera o nó inteiro: os 26 ponteiros
começam `NULL` e o `fim`, `false`:

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

O cliente monta o dicionário e testa três textos digitados:

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

As sugestões saem em ordem alfabética sem ordenar nada: a função que percorre
a subárvore visita os filhos de `a` a `z`, então "bola" (`a`) vem antes de
"boleto" (`e`), que vem antes de "bolo" (`o`).

Repara no fluxograma: é a inserção de "bom", que chega depois das quatro
palavras com "bol". O `b` e o `o` já existem (o caminho segue pelo "Não" duas
vezes); o `m` é novo e ganha um nó. Acabaram as letras, e o `m` recebe
`fim = true`:

{{fluxograma}}

> [!WARNING]
> Achar o nó não quer dizer achar a palavra. `trie_prefixo(t, "bol")` devolve
> um nó válido, mas "bol" não foi inserida: a busca tem que olhar o `fim`
> (`return n != NULL && n->fim;`). O erro oposto também acontece: inserir só
> criando os nós e esquecer o `r->fim = true` do final. Aí a palavra fica
> "meio dentro": as mais compridas que passam por ela aparecem, ela não. E
> cuidado com o índice: `'B' - 'a'` dá -31 e `'ã'` nem é um `char` só em UTF-8.
> Por isso `trie_insere` recusa tudo o que não for de `'a'` a `'z'` antes de
> mexer na árvore.

> [!TIP]
> **Por dentro do C:** cada `NoTrie` tem 216 bytes: 26 ponteiros de 8 bytes
> (208), 1 do `bool` e 7 de enchimento. As 8 palavras do exemplo somam 37 letras
> e cabem em 45 bytes como strings, mas a trie usa 22 nós, 4752 bytes, cem vezes
> mais. Quase todos os ponteiros estão em `NULL` (o A293 mede: mais de 95%). É
> o preço da velocidade: o filho certo está a um índice de distância, sem
> laço. Quando a memória aperta, as alternativas guardam só os filhos que
> existem: uma lista encadeada de filhos (a ideia do primeiro filho/próximo
> irmão do assunto 0144) ou uma pequena BST por nó (a árvore ternária de busca).

> [!NOTE]
> **Pergunta para você:** se você inserir "bolota" no teclado, quantos nós novos
> aparecem? E se inserir "bo"? Em cada caso, o que muda na lista de sugestões
> para "bo"? Responda antes de acrescentar as palavras no vetor do exemplo.

{{pratique}}
