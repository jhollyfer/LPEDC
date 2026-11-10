## 0136 · Código de Huffman

Na placa da barraca está `BANANA NA CABANA`: 16 letras de 8 bits, 128 bits.
Mas há só **5 símbolos** (A, N, B, C e o espaço), e o A aparece 7 vezes e o C
uma. Com 3 bits por símbolo seriam 48, e dá para gastar menos.

Basta dar códigos de tamanho **diferente**: curto para o frequente, comprido
para o raro, como no Morse. Mas onde um código termina? Se A = `0` e N = `01`,
`001` pode ser "A A ..." ou "A N".

A saída é o **código livre de prefixo**: nenhum código é o começo de outro, e
a leitura não tem dúvida. Ele é uma **árvore binária**: cada símbolo é uma
**folha** e o código é o caminho da raiz até ela, com `0` para a esquerda e
`1` para a direita.

O total de bits é a soma de `frequência × profundidade` de cada folha. David
Huffman mostrou em 1952 que um **guloso** acha a melhor árvore:

1. crie uma folha por símbolo, com a frequência, e ponha todas num **heap de
   mínimo** (0102);
2. enquanto houver mais de um nó, **tire os dois menores**, crie um pai com
   os dois como filhos e a **soma** das frequências, e devolva-o ao heap;
3. o nó que sobrar é a **raiz**.

Para `k` símbolos são `k - 1` junções com heap de O(log k): **O(k log k)**.

Aqui, A = 7, N = 4, B = 2, espaço = 2 e C = 1: C e espaço viram 3; com o B,
5; com o N, 9; com o A, a raiz 16. O A ganha `0` e o C, `1110`:

{{ideia}}

### Passo a passo

Heap a cada junção. No empate, desempata o byte (espaço, 32, antes do B, 66):

| junção | heap antes | tira | cria |
| --- | --- | --- | --- |
| 1 | C:1, esp:2, B:2, N:4, A:7 | C:1 e esp:2 | 3 |
| 2 | B:2, 3, N:4, A:7 | B:2 e 3 | 5 |
| 3 | N:4, 5, A:7 | N:4 e 5 | 9 |
| 4 | A:7, 9 | A:7 e 9 | 16 (a raiz) |

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
iguais: folhas usam o próprio byte e nós internos, 256 em diante, a ordem de
criação. Os códigos saem de uma descida recursiva que acumula `0` e `1`. O
cliente conta as frequências, monta a árvore e mostra os códigos:

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

São 7·1 + 4·2 + 2·3 + 1·4 + 2·4 = 33 bits, contra 48 do código fixo.

No fluxograma do `huf_constroi`, cada volta tira dois nós e põe um: 4 voltas
para 5 folhas:

{{fluxograma}}

> [!WARNING]
> Quem decodifica precisa da **mesma árvore**: se o desempate mudar, os
> códigos mudam e a frase sai trocada. O arquivo guarda a árvore, ou as
> frequências e a regra de desempate. Com um símbolo só (`AAAA`), o
> `huf_codigos` dá o código `0`.

> [!TIP]
> **Por dentro do C:** indexe a frequência por `(unsigned char)*p`: com `char`
> com sinal, os bytes de acentos em UTF-8 (`ã` é `0xC3 0xA3`) são negativos e
> `freq[*p]` leria fora do vetor. A árvore tem `2k - 1` nós, e `huf_libera`
> devolve todos em pós-ordem.

> [!NOTE]
> **Pergunta para você:** monte, no papel, a árvore de Huffman de
> `ARARA AZUL`. Quantos bits ela dá? Depois troque a frase no programa e
> confira.

{{pratique}}
