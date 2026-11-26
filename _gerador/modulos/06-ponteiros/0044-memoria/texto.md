## 0044 · Memória e endereços

Até aqui você guardou valores em variáveis e as chamou pelo nome. Funcionou
porque o compilador cuidou de um detalhe por você: decidir em que lugar da
memória cada variável fica. Para entender ponteiros, passagem por referência
e memória dinâmica, você precisa enxergar esse detalhe. Este assunto abre o
módulo mostrando o que é a memória e como se chega a um lugar dentro dela.

Pense no guarda-volumes do mercado. Você entrega a mochila e recebe a ficha
47. Não precisa saber em que prateleira ela ficou: com o número, o
funcionário vai direto à gaveta certa. A **memória** principal do computador,
a RAM, funciona assim. Ela é uma fileira enorme de gavetas de **1 byte**, e
cada gaveta tem um número, o seu **endereço** (FEOFILOFF, 2009, ap. D).

Quando você declara `int idade = 30;`, o compilador separa 4 gavetas
seguidas para `idade` e guarda o 30 nelas. O **endereço da variável** é o
número da primeira dessas gavetas. Cada tipo ocupa uma quantidade diferente:
o `char` usa 1 gaveta, o `int` usa 4 e o `double` usa 8, como o `sizeof` do
assunto 0002 mostra. Seja qual for o tamanho, o endereço da variável é sempre
o da primeira gaveta (BACKES, 2013, cap. 10).

Você pensa em nomes, como `idade` e `preco`. O processador não conhece nomes;
ele só sabe ler e escrever em endereços. Quem faz a ponte é o compilador:
ao traduzir o programa, ele troca cada nome pelo endereço correspondente
(BACKES, 2013, cap. 10). Os nomes existem para você, e os endereços para a
máquina.

O C deixa você perguntar o endereço de uma variável com o operador **`&`**,
lido como "endereço de". `&idade` é a pergunta "em que gaveta você mora?".
Você usa esse operador desde o assunto 0006, no `scanf("%d", &idade)`: o
`scanf` precisa saber **onde** guardar o número que leu, e o `&` entrega esse
lugar (DEITEL; DEITEL, 2011, cap. 7). O assunto 0046 conta essa história
inteira.

Para ver um endereço na tela, o `printf` tem o **`%p`**, que mostra o número
em hexadecimal, a base 16, como `0x7ffd5e8c`. O `%p` espera um valor do tipo
`void *`, então a forma correta é `printf("%p\n", (void *)&idade);`. O
assunto 0051 explica esse tipo (DEITEL; DEITEL, 2011, cap. 7).

Se você rodar o mesmo programa duas vezes, os endereços mudam. Não é erro: o
sistema sorteia em que região o programa vai morar a cada execução, um
recurso de segurança chamado **ASLR**. Quem tenta explorar uma falha não sabe
de antemão onde as coisas estão. Por isso, não decore endereços nem conte com
eles de uma execução para outra.

As variáveis locais, como `idade` dentro do `main`, ficam na **pilha** que
você viu no assunto 0031. O módulo 07 mostra o mapa completo da memória de um
programa, com a pilha e as outras regiões.

> [!WARNING]
> Nunca mostre endereço com `%d` ou `%x`: o endereço tem 8 bytes em 64 bits,
> e o `%d` lê só 4, então o número sai cortado ou negativo. Use `%p` com
> `(void *)`. E não deduza nada da ordem de variáveis soltas: o compilador as
> arruma como quiser. Só num vetor a ordem é garantida.

{{exemplo}}

No cadastro da academia, a idade (`int`), a mensalidade (`double`) e o plano
(`char`) ganham gavetas. Os endereços do desenho são fictícios:

{{ideia}}

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

Rode duas vezes: valores e tamanhos se repetem, endereços não (o sistema
sorteia onde o programa mora). Para cada
variável, as mesmas três perguntas: o que tem dentro, onde mora e quanto ocupa:

{{fluxograma}}
