## 0056 · void * e cast

Nos Correios, o funcionário carimba e despacha qualquer caixa sem abrir:
para ele, uma caixa tem um endereço de entrega e um peso, e só. Quem
recebe é que abre e sabe se dentro tem um livro ou um tênis. O **`void *`**
é essa caixa fechada.

Um `void *` é um **ponteiro genérico**: guarda o endereço de qualquer dado
(`int`, `double`, vetor, outro ponteiro), mas não diz o que mora lá. Antes
de usar o dado, você precisa dizer o tipo.

Duas regras saem disso:

- **conversão livre.** Em C, qualquer ponteiro de dado vira `void *` e
  volta sem cast: `void *p = &senha;` e `int *q = p;` compilam limpo;
- **não dá para desreferenciar.** `*p` com `p` do tipo `void *` não
  compila: o compilador não sabe quantos bytes ler nem como interpretar.
  Converta antes, com um **cast**: `*(int *)p`. Pelo mesmo motivo, `p + 1`
  não existe no C padrão (o `gcc` aceita como extensão, e o `-pedantic`
  avisa).

O cast é uma promessa sua: o compilador acredita. Se
você disser `(double *)` para um endereço onde mora um `int`, ele lê 8
bytes onde só tinha 4 e mostra lixo. Ninguém confere por você.

Para que serve uma caixa fechada? Para escrever funções que trabalham com
**qualquer tipo**. Elas recebem `void *` e, como não sabem o tamanho do
dado, recebem também o tamanho em bytes. Lá dentro, tratam a memória como
uma fileira de bytes, com um `unsigned char *`, o único tipo que o C deixa
olhar byte a byte qualquer objeto. É assim que funcionam `memcpy`,
`memset`, o `qsort` (assunto 0055) e o `malloc` do módulo 07, que devolve
`void *` porque não sabe o que você vai guardar.

Vamos ver na prática. A `troca` do assunto 0051 só troca `int`. A
`troca_generica` recebe dois endereços sem tipo e o tamanho: com 4, troca
duas senhas `int`; com 8, troca dois preços `double`. Byte a byte, ela nem
sabe o que está trocando:

{{ideia}}

O código chama a mesma função para os dois tipos:

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

Repare que `&senha_a` (um `int *`) entra no parâmetro `void *` sem cast
nenhum, e que o `sizeof` na chamada é quem conta à função o tamanho do
dado.

Repara no fluxograma: a função não pergunta "que tipo é?", porque não tem
como saber. Ela só pergunta "ainda tem byte para trocar?":

{{fluxograma}}

> [!WARNING]
> O `void *` desliga a conferência de tipos. `troca_generica(&senha_a,
> &preco_a, sizeof preco_a)` compila sem aviso e troca 8 bytes a partir de
> uma variável que só tem 4: o AddressSanitizer acusa
> `stack-buffer-overflow`. O mesmo vale para o cast errado na leitura:
> `*(double *)p` com `p` apontando para um `int`. Com `void *`, você é o
> responsável por lembrar o tipo e o tamanho de verdade. Use `sizeof` da
> própria variável, nunca um número digitado à mão.

> [!TIP]
> **Por dentro do C:** o A112 usa um `const unsigned char *` para espiar os
> bytes de qualquer variável. O `int` 1000 (`0x000003E8`) aparece como `e8 03
> 00 00`: o byte menos significativo vem primeiro, no endereço menor. É o
> **little-endian** dos processadores Intel, AMD e ARM. O `-1` vira `ff ff ff
> ff` (complemento de dois) e a string `"Pix"` vira `50 69 78 00`, os
> códigos ASCII com o `'\0'` no fim. Olhar a memória como bytes só é
> garantido com tipos `char`; ler um `float` através de um `int *`, por
> exemplo, quebra uma regra do C (a de *strict aliasing*) e o otimizador
> pode gerar código errado.

> [!NOTE]
> **Pergunta para você:** por que `troca_generica` precisa do parâmetro
> `tam` e a `troca` do assunto 0051 não precisa? O que aconteceria se você
> passasse `sizeof(int)` para trocar dois `double`?

{{pratique}}
