## 0051 · void * e cast

A função `troca` do assunto 0046 troca dois `int`. Para trocar dois `double`,
você escreveria outra, quase igual; para dois caracteres, mais uma. O
`qsort` do assunto 0050 tem o mesmo problema ao contrário: ele precisa
receber vetores de qualquer tipo sem saber qual. Falta um ponteiro que aceite
qualquer endereço.

Pense no funcionário dos Correios que carimba e despacha caixas sem abri-las.
Para ele, cada caixa tem um endereço e um peso, e só. Quem recebe abre e
descobre se é um livro ou um tênis. Em C, essa caixa fechada é o **`void
*`**, o **ponteiro genérico**: ele guarda o endereço de qualquer dado, seja
`int`, `double`, vetor ou outro ponteiro, mas não diz o que mora lá (DEITEL;
DEITEL, 2011, cap. 7).

A primeira regra é a da conversão livre. Em C, qualquer ponteiro para dado
vira `void *` e volta para o tipo original sem precisar escrever nada:
`void *p = &senha;` e depois `int *q = p;` compilam limpos (DEITEL; DEITEL,
2011, cap. 7). Ponteiro para função não entra nessa regra.

A segunda regra é a que dá trabalho: um `void *` **não se desreferencia**.
Escrever `*p` com `p` do tipo `void *` não compila, porque o compilador não
sabe quantos bytes ler nem como interpretá-los. Antes de usar o dado, você
diz o tipo com um **cast**, um tipo entre parênteses na frente da expressão:
`*(int *)p` primeiro trata `p` como `int *` e depois lê o `int`. Pelo mesmo
motivo, `p + 1` não existe no C padrão, já que o compilador não sabe o
tamanho do passo; o `gcc` aceita como extensão e o `-pedantic` avisa (BACKES,
2013, cap. 10).

```c
int senha = 1234;
void *p = &senha;               // caixa fechada com o endereço de senha
printf("%d\n", *(int *)p);      // 1234: o cast diz o que tem dentro
```

O cast é uma promessa sua, e o compilador acredita nela sem conferir. Se você
diz `(double *)` para um endereço em que mora um `int`, ele lê 8 bytes onde
só havia 4 e mostra lixo (BACKES, 2013, cap. 10).

A caixa fechada permite escrever funções que trabalham com **qualquer
tipo**. Elas recebem `void *` e, como não conhecem o tamanho do dado,
recebem também o tamanho em bytes. Por dentro, tratam a memória como uma
fileira de bytes, com um `unsigned char *`, o único tipo que o C deixa olhar
qualquer objeto byte a byte. Assim funcionam `memcpy` e `memset`, o `qsort`
e o `malloc` do módulo 07, que devolve `void *` porque não sabe o que você
vai guardar (CELES; RANGEL, 2002).

Olhar os bytes ensina como o computador guarda um número. O A102 espia uma
variável com `const unsigned char *`. O `int` 1000, que em hexadecimal é
`0x000003E8`, aparece como `e8 03 00 00`: o byte menos significativo vem
primeiro, no endereço menor. Esse arranjo se chama **little-endian**, e é o
dos processadores Intel, AMD e ARM. Só os tipos `char` podem fazer essa
leitura com segurança; ler um `float` por um `int *` quebra a regra de
*strict aliasing*, que proíbe acessar um objeto por um ponteiro de outro
tipo.

> [!WARNING]
> O `void *` desliga a conferência de tipos: `troca_generica(&senha_a,
> &preco_a, sizeof preco_a)` compila sem aviso e troca 8 bytes a partir de
> uma variável de 4, e o AddressSanitizer acusa `stack-buffer-overflow`. Use o
> `sizeof` da própria variável, nunca um número digitado à mão.

{{exemplo}}

A `troca` do assunto 0046 só troca `int`. A `troca_generica` recebe dois
endereços sem tipo e o tamanho: com 4, troca duas senhas; com 8, dois preços.
Byte a byte, ela nem sabe o que troca:

{{ideia}}

```c
#include <stdio.h>

// void *: "endereço de qualquer coisa". Como a função não sabe o tipo,
// recebe o tamanho em bytes e troca byte a byte.
void troca_generica(void *a, void *b, size_t tam) {
    unsigned char *x = a; // void * vira outro ponteiro sem cast, em C
    unsigned char *y = b;
    for (size_t i = 0; i < tam; i++) {
        unsigned char tmp = x[i];
        x[i] = y[i];
        y[i] = tmp;
    }
}

int main(void) {
    int senha_a = 17, senha_b = 42;               // senhas do atendimento
    double preco_a = 12.90, preco_b = 8.50;       // preços na etiqueta

    troca_generica(&senha_a, &senha_b, sizeof senha_a);   // troca 4 bytes
    troca_generica(&preco_a, &preco_b, sizeof preco_a);   // troca 8 bytes

    printf("senhas: %d e %d\n", senha_a, senha_b);
    printf("preços: %.2f e %.2f\n", preco_a, preco_b);
    return 0;
}
// Saída:
// senhas: 42 e 17
// preços: 8.50 e 12.90
```

O A102 espia os bytes com `const unsigned char *`: o `int` 1000 aparece como
`e8 03 00 00`, o byte menos significativo primeiro (**little-endian**).

A função não pergunta "que tipo é?", só "ainda tem byte para trocar?":

{{fluxograma}}
