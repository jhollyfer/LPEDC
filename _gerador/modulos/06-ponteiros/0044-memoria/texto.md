## 0044 · Memória e endereços

No guarda-volumes do mercado, você entrega a mochila e recebe a ficha 47. Não
precisa saber em que prateleira ela está: com o número, o funcionário acha a
gaveta. A memória do computador funciona assim.

A **memória** (RAM) é uma fileira de gavetas de **1 byte**, cada uma com um
número: o **endereço**. Ao declarar `int idade = 30;`, o compilador separa 4
gavetas seguidas para `idade` e guarda o 30 nelas. O **endereço da variável**
é o número da primeira gaveta.

Você pensa no **nome** (`idade`); o processador só conhece **endereços**, e o
compilador troca um pelo outro.

O operador **`&`** (endereço de) pergunta "em que gaveta você mora?": `&idade`.
É o `&` do `scanf` desde o assunto 0006: o `scanf` precisa saber **onde**
guardar o que leu. O assunto 0046 conta essa história.

O `printf` mostra um endereço com **`%p`**, em hexadecimal. O `%p` espera um
`void *`, então escreva `(void *)&idade`. O assunto 0051 explica esse tipo.

Dois detalhes que surpreendem:

- **o endereço muda a cada execução**: o sistema sorteia onde o programa mora,
  por segurança. Não decore endereços;
- **cada tipo ocupa um número de gavetas**: `char` 1, `int` 4, `double` 8 (o
  `sizeof` do assunto 0002 diz). O endereço é sempre o da primeira.

No cadastro da academia, a idade (30, `int`), a mensalidade (R$ 119,90,
`double`) e o plano (`'B'`, `char`) ganham gavetas. Os endereços do desenho são
fictícios:

{{ideia}}

O programa mostra, de cada variável, o valor, o endereço e o tamanho:

```c
#include <stdio.h>

int main(void) {
    int idade = 30;
    double mensalidade = 119.90;
    char plano = 'B';

    // & pergunta "em que gaveta você mora?"; %p mostra a resposta em hexa
    printf("idade:       %d, mora em %p, ocupa %zu bytes\n",
           idade, (void *)&idade, sizeof idade);
    printf("mensalidade: %.2f, mora em %p, ocupa %zu bytes\n",
           mensalidade, (void *)&mensalidade, sizeof mensalidade);
    printf("plano:       %c, mora em %p, ocupa %zu byte\n",
           plano, (void *)&plano, sizeof plano);
    return 0;
}
// Saída (os endereços mudam a cada execução):
// idade:       30, mora em 0x7f0440e00030, ocupa 4 bytes
// mensalidade: 119.90, mora em 0x7f0440e00040, ocupa 8 bytes
// plano:       B, mora em 0x7f0440e00020, ocupa 1 byte
```

O `%zu` é o formato do resultado do `sizeof` (`size_t`, inteiro sem sinal).
Rode duas vezes: valores e tamanhos se repetem, endereços não.

O fluxograma não tem decisão. Para cada variável, o programa faz as mesmas três
perguntas: o que tem dentro, onde mora e quanto ocupa:

{{fluxograma}}

> [!WARNING]
> Nunca mostre endereço com `%d` ou `%x`. Um endereço tem 8 bytes em 64 bits e
> o `%d` lê só 4: o número sai cortado, às vezes negativo. O gcc com as flags de
> estudo avisa (`format '%d' expects argument of type 'int', but argument 2 has
> type 'int *'`). Use `%p` com `(void *)`. E não deduza nada da ordem dos
> endereços de variáveis soltas: o compilador arruma como quiser (acima,
> `plano` ficou **antes** de `idade`). Só num vetor a ordem é garantida.

> [!TIP]
> **Por dentro do C:** o sorteio do endereço a cada execução se chama **ASLR**;
> dificulta explorar falhas, pois o atacante não sabe onde as coisas moram. As
> variáveis locais ficam na **pilha** do assunto 0031; o módulo 07 mostra o
> mapa completo.

> [!NOTE]
> **Pergunta para você:** se `idade` começa na gaveta `0x1000` e ocupa 4
> bytes, qual é o endereço do **último** byte dela? E onde poderia começar a
> próxima variável `int`, sem sobrepor? Depois rode o A088 e veja os
> endereços de um vetor subindo de 4 em 4.

{{pratique}}
