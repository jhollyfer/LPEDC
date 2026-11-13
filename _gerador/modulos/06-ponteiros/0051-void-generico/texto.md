## 0051 · void * e cast

- **`void *`**: **ponteiro genérico**. Guarda o endereço de qualquer dado, mas
  não diz o que mora lá (DEITEL; DEITEL, 2011, cap. 7).
- **Conversão livre**: em C, qualquer ponteiro de dado vira `void *` e volta
  sem cast (`int *q = p;`) (DEITEL; DEITEL, 2011, cap. 7).
- **Não se desreferencia**: `*p` não compila, porque o compilador não sabe
  quantos bytes ler. Converta antes com um **cast**: `*(int *)p`. E `p + 1` não
  existe no C padrão (BACKES, 2013, cap. 10).
- **O cast é uma promessa**: `(double *)` num endereço de `int` lê 8 bytes onde
  havia 4 e mostra lixo (BACKES, 2013, cap. 10).
- **Funções genéricas**: recebem `void *` e o tamanho em bytes, e olham a
  memória com `unsigned char *`, o único tipo que lê qualquer objeto byte a
  byte. Assim funcionam `memcpy`, `qsort` e `malloc` (CELES; RANGEL, 2002).

> [!WARNING]
> O `void *` desliga a conferência de tipos: `troca_generica(&senha_a,
> &preco_a, sizeof preco_a)` compila e troca 8 bytes numa variável de 4. Use o
> `sizeof` da própria variável, nunca um número à mão.

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
