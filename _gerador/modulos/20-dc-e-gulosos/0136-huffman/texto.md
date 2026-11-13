## 0136 · Código de Huffman

Na placa da barraca está escrito `BANANA NA CABANA`. São 16 caracteres, e
com 8 bits por caractere a frase ocupa 128 bits. Mas ela usa só **5
símbolos**: A, N, B, C e o espaço. Com 3 bits cada, já daria para numerar os
cinco, e a frase cairia para 48 bits. E dá para gastar menos ainda, porque o
A aparece 7 vezes e o C, uma só.

A ideia é usar um **código de tamanho variável**: o símbolo frequente ganha
um código curto e o raro ganha um comprido, como no Morse, em que o E é um
ponto só. No total, a mensagem gasta menos bits que com o código fixo
(TENENBAUM; LANGSAM; AUGENSTEIN, 1995, seção 5.3). O preço é uma dúvida nova:
na hora de ler, onde termina um código e começa o seguinte? Se A = `0` e
N = `01`, a sequência `001` pode ser "A, A, e o começo de outra coisa" ou
"A, N".

A saída é exigir um **código livre de prefixo**: nenhum código é o começo de
outro. Assim, quem lê a sequência de bits da esquerda para a direita sabe
que um código terminou no instante em que ele bate com um da tabela, sem
precisar olhar adiante (CORMEN et al., 2024, cap. 15). Com A = `0` e N = `10`,
o `0` só pode ser A, e `10` só pode ser N.

Todo código livre de prefixo cabe numa **árvore binária de código**. Cada
símbolo é uma **folha**, um nó sem filhos. O código de um símbolo é o
caminho da raiz até a folha dele: cada passo para a esquerda escreve `0` e
cada passo para a direita escreve `1`. Como os símbolos só moram nas folhas,
nenhum caminho passa por outro símbolo, e o prefixo nunca se repete. O
tamanho do código é a **profundidade** da folha, e o total de bits da
mensagem é a soma de `frequência × profundidade` de todas as folhas
(SZWARCFITER; MARKENZON, 2010).

Resta achar a árvore que deixa essa soma mínima. David Huffman mostrou que
um guloso (0133) acha (HUFFMAN, 1952). Crie uma folha por símbolo, com a
frequência dele, e ponha todas num **heap de mínimo** (0102), a estrutura
que entrega sempre o menor elemento. Enquanto houver mais de um nó no heap,
tire os dois de menor frequência, crie um nó pai com os dois como filhos e
com a **soma** das frequências, e devolva o pai ao heap. Quando sobrar um nó
só, ele é a raiz.

A intuição do guloso: os dois símbolos mais raros devem ficar no fundo da
árvore, com os códigos mais longos, porque pagam pouco por isso. Juntá-los
primeiro garante que fiquem lá embaixo, irmãos. Na frase da barraca, A = 7,
N = 4, B = 2, espaço = 2 e C = 1. C e espaço viram um nó de 3; ele e o B viram
5; com o N, 9; com o A, a raiz, 16. O A fica a um passo da raiz e ganha o
código `0`; o C fica no fundo e ganha `1110`. O total cai para 33 bits.

O custo vem do heap. Para `k` símbolos são `k - 1` junções, porque cada uma
diminui o heap em um nó, e cada operação no heap custa O(log k). O total é
**O(k log k)**. A árvore final tem `k` folhas e `k - 1` nós internos, ou
seja, `2k - 1` nós (CORMEN et al., 2024, cap. 15).

Quando duas frequências empatam, o heap pode tirar uma ou outra primeiro, e
saem árvores diferentes. Todas são ótimas, com o mesmo total de bits, mas
os códigos mudam. Por isso quem decodifica precisa da **mesma** árvore de
quem codificou: o arquivo compactado guarda a árvore, ou as frequências e a
regra de desempate (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, seção 5.3).

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
