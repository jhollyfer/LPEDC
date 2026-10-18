## 0049 · Memória e endereços

No guarda-volumes do mercado, você entrega a mochila e recebe uma ficha com o
número 47. Você não precisa saber em que prateleira ela foi parar: com o
número, o funcionário acha a gaveta certa. A memória do computador funciona
igualzinho.

A **memória** (RAM) é uma fileira enorme de gavetas de **1 byte** cada, e
cada gaveta tem um número: o **endereço**. Quando você declara `int idade =
30;`, o compilador separa 4 gavetas seguidas para `idade` e guarda o 30 lá
dentro. O **endereço da variável** é o número da primeira dessas gavetas.

Você pensa no **nome** (`idade`). O processador só conhece **endereços**. O
compilador faz a ponte: troca cada nome pelo endereço da gaveta. Até agora
isso ficou escondido; neste módulo você vai mexer direto nos números.

Para perguntar "em que gaveta você mora?", use o operador **`&`** (endereço
de): `&idade`. É o mesmo `&` que você coloca no `scanf` desde o assunto 0011.
O `scanf` precisa saber **onde** guardar o que leu, e o `&` entrega a ficha
do guarda-volumes. O assunto 0051 conta essa história inteira.

Para mostrar um endereço, o `printf` tem o **`%p`**, que imprime em
hexadecimal. O `%p` espera um "endereço genérico", do tipo
`void *`, então escreva `(void *)&idade`. Esse `(void *)` é um cast, e o
assunto 0056 explica o tipo `void *` com calma.

Dois detalhes que surpreendem quem vem do JS:

- **o endereço muda a cada execução.** O sistema sorteia onde o programa
  vai morar, por segurança. Não decore endereço nenhum;
- **cada tipo ocupa um número de gavetas**: `char` 1, `int` 4, `double` 8 (o
  `sizeof` do assunto 0007 diz quantas). O endereço é sempre o da primeira.

Vamos ver na prática. No cadastro da academia, a idade (30, um `int`), a
mensalidade (R$ 119,90, um `double`) e o plano (`'B'`, um `char`) ganham
gavetas. Os endereços do desenho são **fictícios** e curtos, para caber na
cabeça; os de verdade têm 12 dígitos hexa:

{{ideia}}

O programa mostra, para cada variável, o valor, o endereço e o tamanho:

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

O `%zu` é o formato certo para o resultado do `sizeof` (um `size_t`, inteiro
sem sinal). Rode duas vezes: os valores e os tamanhos se repetem, os
endereços não.

Repara no fluxograma: não tem decisão nenhuma. Para cada variável, o
programa faz as mesmas três perguntas: o que tem dentro, onde mora e quanto
ocupa:

{{fluxograma}}

> [!WARNING]
> Nunca mostre endereço com `%d` ou `%x`. Um endereço tem 8 bytes num
> sistema de 64 bits, e o `%d` lê só 4: você vê um número cortado, às vezes
> negativo. O `rodar` avisa (`format '%d' expects argument of type 'int', but
> argument 2 has type 'int *'`). O certo é sempre `%p` com `(void *)`. E não
> conclua nada da ordem dos endereços de variáveis soltas: o compilador
> arruma as gavetas como quiser (na saída acima, `plano` ficou **antes** de
> `idade`). Só num vetor a ordem é garantida.

> [!TIP]
> **Por dentro do C:** o endereço `0x7f0440e00030` tem 12 dígitos hexa, ou
> seja, 48 bits. O ponteiro ocupa 8 bytes (64 bits), mas os processadores de
> hoje só usam 48 deles para endereçar: dá 256 TB, sobra. O sorteio do
> endereço a cada execução se chama **ASLR** (*Address Space Layout
> Randomization*): se o atacante não sabe onde as coisas moram, fica bem
> mais difícil explorar uma falha. E as variáveis locais moram numa região
> chamada **pilha**, a mesma pilha de chamadas do assunto 0036; o módulo 07
> mostra o mapa completo.

> [!NOTE]
> **Pergunta para você:** se `idade` começa na gaveta `0x1000` e ocupa 4
> bytes, qual é o endereço do **último** byte dela? E onde poderia começar a
> próxima variável `int`, sem sobrepor? Depois rode o A098 e veja os
> endereços de um vetor subindo de 4 em 4.

{{pratique}}
