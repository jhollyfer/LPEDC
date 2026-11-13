## 0136 · Código de Huffman

- **Código de tamanho variável**: curto para o símbolo frequente, comprido
  para o raro, como no Morse. Gasta menos bits que o código fixo
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, seção 5.3).
- **Código livre de prefixo**: nenhum código é o começo de outro, e a leitura
  não tem dúvida. Com A = `0` e N = `01`, `001` seria ambíguo
  (CORMEN et al., 2024, cap. 15).
- **Árvore de código**: cada símbolo é uma **folha**; o código é o caminho da
  raiz até ela, `0` à esquerda e `1` à direita. O total de bits é a soma de
  `frequência × profundidade` (SZWARCFITER; MARKENZON, 2010).
- **Algoritmo de Huffman**: ponha uma folha por símbolo num **heap de mínimo**
  (0102); enquanto houver mais de um nó, tire os dois menores e devolva um pai
  com a soma; o que sobra é a raiz. Esse guloso acha a melhor árvore
  (HUFFMAN, 1952).
- **Custo**: `k - 1` junções com heap O(log k), logo **O(k log k)**; a árvore
  tem `2k - 1` nós (CORMEN et al., 2024, cap. 15).
- **Desempate**: frequências iguais permitem árvores diferentes, todas
  ótimas. Quem decodifica precisa da **mesma** árvore
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, seção 5.3).

> [!WARNING]
> Se o desempate mudar entre codificar e decodificar, os códigos mudam e a
> frase sai trocada. E indexe a frequência por `(unsigned char)*p`: com
> `char` com sinal, os bytes de acento em UTF-8 são negativos e `freq[*p]` lê
> fora do vetor.

{{exemplo}}

A placa `BANANA NA CABANA` tem 16 letras e só 5 símbolos: A = 7, N = 4, B = 2,
espaço = 2 e C = 1. C e espaço viram 3; com o B, 5; com o N, 9; com o A, a raiz
16. O A ganha `0` e o C, `1110`:

{{ideia}}

O TAD está em `huffman.h` e `huffman.c`. A parte central é o laço do guloso,
com um heap de mínimo de ponteiros para nó:

```c
NoHuf *huf_constroi(const long freq[256]) {
    Heap h = {.n = 0};
    for (int c = 0; c < 256; c++) {
        if (freq[c] > 0) {
            poe(&h, novo_no((unsigned char)c, freq[c], c, NULL, NULL));
        }
    }
    if (h.n == 0) {
        return NULL;
    }
    int criados = 0;
    while (h.n > 1) {
        NoHuf *a = tira(&h);  // o menos frequente vira o filho 0
        NoHuf *b = tira(&h);  // o segundo vira o filho 1
        poe(&h, novo_no(0, a->freq + b->freq, 256 + criados++, a, b));
    }
    return tira(&h);
}
```

O campo `ordem` (terceiro argumento de `novo_no`) desempata frequências
iguais: folhas usam o próprio byte e nós internos, 256 em diante. O cliente
conta as frequências, monta a árvore e mostra os códigos:

```c
#include <stdio.h>
#include <string.h>
#include "huffman.h"

int main(void) {
    const char *frase = "BANANA NA CABANA";
    long freq[256] = {0};
    for (const char *p = frase; *p != '\0'; p++) {
        freq[(unsigned char)*p]++;          // conta cada byte
    }

    NoHuf *raiz = huf_constroi(freq);
    static char cod[256][256];              // 64 KB: static, fora da pilha
    huf_codigos(raiz, cod);

    long bits = 0;
    for (int c = 0; c < 256; c++) {
        if (freq[c] > 0) {
            printf("'%c' aparece %ld vez(es): %s\n", c, freq[c], cod[c]);
            bits += freq[c] * (long)strlen(cod[c]);
        }
    }
    printf("Codificada: ");
    for (const char *p = frase; *p != '\0'; p++) {
        printf("%s", cod[(unsigned char)*p]);
    }
    printf("\n%ld bits, contra %zu com 8 bits por letra\n", bits, 8 * strlen(frase));

    huf_libera(raiz);
    return 0;
}
// Saída:
// ' ' aparece 2 vez(es): 1111
// 'A' aparece 7 vez(es): 0
// 'B' aparece 2 vez(es): 110
// 'C' aparece 1 vez(es): 1110
// 'N' aparece 4 vez(es): 10
// Codificada: 110010010011111001111111001100100
// 33 bits, contra 128 com 8 bits por letra
```

São 7·1 + 4·2 + 2·3 + 1·4 + 2·4 = 33 bits, contra 48 do código fixo de 3 bits.
No `huf_constroi`, cada volta tira dois nós e põe um: 4 voltas para 5 folhas:

{{fluxograma}}

### Passo a passo

Heap a cada junção. No empate, desempata o byte (espaço, 32, antes do B, 66):

| junção | heap antes | tira | cria |
| --- | --- | --- | --- |
| 1 | C:1, esp:2, B:2, N:4, A:7 | C:1 e esp:2 | 3 |
| 2 | B:2, 3, N:4, A:7 | B:2 e 3 | 5 |
| 3 | N:4, 5, A:7 | N:4 e 5 | 9 |
| 4 | A:7, 9 | A:7 e 9 | 16 (a raiz) |
