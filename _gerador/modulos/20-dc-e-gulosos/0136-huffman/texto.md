## 0136 · Código de Huffman

Na placa da barraca de frutas está escrito `BANANA NA CABANA`. Num arquivo de
texto, cada uma dessas 16 letras ocupa um byte, 8 bits: 128 bits ao todo. Só
que a frase usa **5 símbolos** diferentes (A, N, B, C e o espaço), e o A
aparece 7 vezes enquanto o C aparece uma. Gastar 8 bits com cada um é
desperdício. Com 3 bits por símbolo já daria (2³ = 8 combinações): 48 bits.
Dá para fazer melhor ainda?

Dá, se cada símbolo tiver um código de tamanho **diferente**: curto para o
que aparece muito, comprido para o raro. É a ideia do código Morse, em que
o E (a letra mais comum do inglês) é um ponto só. Mas tamanho variável traz
um problema: onde termina um código e começa o próximo? Se A = `0` e
N = `01`, a sequência `001` pode ser "A A ..." ou "A N".

A saída é um **código livre de prefixo**: nenhum código é o começo de outro.
Aí a leitura não tem dúvida: você lê bits até formar um código, e ele só
pode ser aquele. Esse tipo de código é uma **árvore binária**: cada símbolo é
uma **folha**, e o código é o caminho da raiz até ela, com `0` para a
esquerda e `1` para a direita. Como os símbolos só moram nas folhas, nenhum
caminho é o começo de outro.

Qual árvore dá o menor total de bits? O total é a soma de
`frequência × profundidade` de cada folha. David Huffman, em 1952, mostrou
que um **guloso** acha a melhor:

1. crie uma folha para cada símbolo, com a sua frequência, e ponha todas
   num **heap de mínimo** (assunto 0102), ordenado pela frequência;
2. enquanto houver mais de um nó no heap, **tire os dois menores**, crie um
   nó pai com os dois como filhos e a **soma** das frequências, e devolva o
   pai ao heap;
3. o nó que sobrar é a **raiz**.

Os símbolos raros são juntados primeiro e vão parar lá no fundo, com códigos
compridos; os frequentes entram por último, perto da raiz. Para `k` símbolos
são `k - 1` junções, cada uma com operações de heap de O(log k): o total é
**O(k log k)**.

Vamos ver na prática. As frequências são A = 7, N = 4, B = 2, espaço = 2 e
C = 1. O C e o espaço (os menores) se juntam num nó 3; o B junta com o 3
num 5; o N com o 5 num 9; e o A com o 9 na raiz, 16. Lendo os caminhos: A
ganha o código `0`, de 1 bit, e o C ganha `1110`, de 4:

{{ideia}}

### Passo a passo

O heap a cada junção. Quando duas frequências empatam, o desempate é pelo
byte (o espaço, 32, vem antes do B, 66):

| junção | heap antes | tira | cria |
| --- | --- | --- | --- |
| 1 | C:1, esp:2, B:2, N:4, A:7 | C:1 e esp:2 | 3 |
| 2 | B:2, 3, N:4, A:7 | B:2 e 3 | 5 |
| 3 | N:4, 5, A:7 | N:4 e 5 | 9 |
| 4 | A:7, 9 | A:7 e 9 | 16 (a raiz) |

O TAD fica em `huffman.h` e `huffman.c`. O nó guarda o símbolo, a frequência
e os dois filhos. O coração do `huffman.c` é o laço do guloso, usando um heap
de mínimo de ponteiros para nó:

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

O campo `ordem` (o terceiro argumento de `novo_no`) desempata frequências
iguais: as folhas usam o próprio byte e os nós internos, 256 em diante, na
ordem de criação. Sem ele, a árvore dependeria de detalhes do heap. Os
códigos saem de uma descida recursiva que vai acumulando `0` e `1`. O
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

São 7·1 + 4·2 + 2·3 + 1·4 + 2·4 = 33 bits: um quarto do texto original e
menos que os 48 do código fixo de 3 bits.

Repara no fluxograma: é o laço do `huf_constroi`. Cada volta tira dois nós e
põe um, então o heap encolhe um por volta. Com 5 folhas, são 4 voltas:

{{fluxograma}}

> [!WARNING]
> Para decodificar, quem recebe os bits precisa da **mesma árvore**. Se o
> desempate for diferente (o B antes do espaço, por exemplo), os códigos
> mudam e a frase sai trocada, embora o total de bits continue 33. Por isso
> o compactador precisa guardar no arquivo a árvore, ou as frequências e a
> regra exata de desempate, para o descompactador refazer a mesma árvore. E
> cuidado com o caso de um símbolo só (`AAAA`): a árvore é só a raiz, e o
> caminho até ela é vazio. O `huf_codigos` dá o código `0` para ele.

> [!TIP]
> **Por dentro do C:** a frequência é indexada por `(unsigned char)*p`, e não
> por `*p`. Em muitos compiladores, `char` tem sinal, e os bytes de
> acentos em UTF-8 (como o `ã`, que vira `0xC3 0xA3`) são negativos:
> `freq[*p]` leria fora do vetor, antes do começo. A tabela `cod` tem
> 256 × 256 bytes = 64 KB e é `static` para não ocupar a pilha do `main`. E
> repare que a árvore tem `2k - 1` nós (k folhas e k - 1 internos): 9
> `malloc` aqui, e `huf_libera` devolve todos em pós-ordem, os filhos antes
> do pai.

> [!NOTE]
> **Pergunta para você:** monte, no papel, a árvore de Huffman de
> `ARARA AZUL`. Quantos bits ela dá? Depois troque a frase no programa e
> confira.

{{pratique}}
