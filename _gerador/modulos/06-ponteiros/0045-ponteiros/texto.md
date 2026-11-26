## 0045 · Ponteiros

O assunto 0044 mostrou que toda variável mora num endereço e que o `&`
descobre esse número. Falta guardá-lo. Se o endereço é um número, ele pode
ficar numa variável, e com ele na mão você consegue chegar à variável
original de qualquer parte do programa, mesmo sem saber o nome dela.

Pense no entregador do app de comida. Ele não carrega a sua casa no celular;
carrega o **endereço**. Com ele, chega à porta e entrega o pedido. Em C, a
variável que faz o papel desse celular é o **ponteiro**: uma variável que
guarda um endereço em vez de um valor comum. O ponteiro também mora numa
gaveta e tem endereço próprio, mas o que ele guarda é o número de **outra**
gaveta. Ziviani e a tradução do livro de Kernighan e Ritchie usam o nome
**apontador**; é a mesma coisa (ZIVIANI, 2010).

Na declaração, um `*` antes do nome indica que a variável é um ponteiro:
`int *cartao;` lê-se "cartao é um ponteiro para int". O tipo antes do `*`
diz **o que** mora no endereço apontado e, com isso, quantos bytes ler lá:
4 para um `int`, 8 para um `double` (DEITEL; DEITEL, 2011, cap. 7).

Dois operadores fazem todo o trabalho. O `&x`, que você já conhece, dá o
endereço de `x`, e esse endereço vai para o ponteiro: `cartao = &pontos;`.
O `*cartao` faz o caminho de volta: vai ao endereço guardado em `cartao` e
mexe no que está lá. Essa operação se chama **desreferenciar** o ponteiro
(KERNIGHAN; RITCHIE, 1989, cap. 5). Ler `*cartao` dá o valor de `pontos`;
escrever `*cartao = 150;` muda `pontos`, sem que o nome `pontos` apareça na
linha.

```c
int pontos = 120;
int *cartao = &pontos;   // cartao guarda o endereço de pontos
*cartao = *cartao + 30;  // vai até pontos e soma 30
printf("%d\n", pontos);  // 150
```

O mesmo símbolo `*` tem três papéis, e só o contexto os separa. Entre dois
valores, como em `a * b`, é a multiplicação. Numa declaração, como em
`int *p`, diz que `p` é um ponteiro. Na frente de um ponteiro já declarado,
como em `*p = 5`, é a desreferência (BACKES, 2013, cap. 10). Quando a leitura
travar, pergunte em qual dos três casos você está.

Às vezes o ponteiro ainda não tem para onde apontar. Para isso existe o
**`NULL`**, um endereço especial que quer dizer "lugar nenhum". Na prática é
o endereço 0, uma região que o sistema proíbe de propósito: desreferenciar
`NULL` derruba o programa na hora, com o erro *segmentation fault*, em vez de
estragar algum dado em silêncio. Antes de usar um ponteiro que pode estar
vazio, teste `if (cartao != NULL)` (DEITEL; DEITEL, 2011, cap. 7).

Um último detalhe ajuda a montar a imagem certa. Todo ponteiro para dado tem
o mesmo tamanho, 8 bytes num computador de 64 bits, porque todos guardam a
mesma coisa: um endereço. O tipo do ponteiro não muda o tamanho dele; muda a
**leitura**. `*cartao` busca 4 bytes e os trata como `int` porque `cartao` é
um `int *` (BACKES, 2013, cap. 10).

> [!WARNING]
> `int *p;` sem valor guarda **lixo**, um endereço qualquer, e `*p = 10;`
> escreve numa gaveta desconhecida: pode travar na hora ou corromper outra
> variável e dar problema só depois. Inicialize com um endereço ou `NULL`. E
> em `int *a, b;` só `a` é ponteiro; para dois, `int *a, *b;`.

{{exemplo}}

No caixa da farmácia, o cliente tem 120 pontos. O ponteiro `cartao` começa em
`NULL`, recebe `&pontos`, e a compra soma 30 **por meio do ponteiro**:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    int pontos = 120;     // pontos do cartão fidelidade
    int *cartao = NULL;   // ponteiro para int; NULL: ainda não aponta para nada

    cartao = &pontos;     // o cliente passou o cartão: cartao guarda &pontos

    printf("&pontos = %p\n", (void *)&pontos);
    printf("cartao  = %p\n", (void *)cartao); // o mesmo endereço
    printf("*cartao = %d\n", *cartao);        // o que tem na gaveta apontada

    if (cartao != NULL) {
        *cartao = *cartao + 30; // compra de R$ 30: muda pontos ATRAVÉS do ponteiro
    } else {
        printf("Compra sem cartão\n");
    }
    printf("pontos  = %d\n", pontos);
    printf("&cartao = %p\n", (void *)&cartao); // o ponteiro também mora numa gaveta
    return 0;
}
// Saída (os endereços mudam a cada execução):
// &pontos = 0x7f631f200030
// cartao  = 0x7f631f200030
// *cartao = 120
// pontos  = 150
// &cartao = 0x7f631f200040
```

`cartao` é o endereço guardado, `*cartao` o valor lá dentro e `&cartao` onde o
próprio ponteiro mora. Antes de desreferenciar, o teste contra `NULL`:

{{fluxograma}}
